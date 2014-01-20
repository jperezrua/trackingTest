#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>

#include <opencv2/imgproc.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    start_timer_image();
    tracker1 = createMeanShiftTracker();
    tracker2 = createSpatiogramTracker();
}

MainWindow::~MainWindow(){
    timerImage->stop();
    delete timerImage;
    delete ui;
    wait();
}

void MainWindow::start_timer_image(){
    capture = cv::VideoCapture(0);
    timerImage = new QTimer(this);
    connect(timerImage, SIGNAL(timeout()), this, SLOT(update_image_label()));
    timerImage->start(30);
}

//SLOTS
void MainWindow::on_pushButton_track_clicked(bool checked){
    if (!checked){
        ui->pushButton_track->setText("Re-START Tracking!");
    }else{
        ui->pushButton_track->setText("START Tracking!");
    }
}

void MainWindow::on_pushButton_track_clicked(){
    tinfo1.startSelection=tinfo1.selectObject=false;
    timerImage->stop();
    inputImage.copyTo(tinfo1.image);
    cv::imshow("SELECT BOX", tinfo1.image);
    cv::setMouseCallback( "SELECT BOX", onMouse, &tinfo1 );

    while(!tinfo1.selectObject) cv::waitKey(30);
    cv::destroyWindow("SELECT BOX");

    if (ui->radioButton_mshift->isChecked() || ui->radioButton_both->isChecked()){
        std::vector<int> channels, histSize;
        std::vector<float> ranges;

        if (ui->radioButton_histo1 || ui->radioButton_histo3){ //1 channel
            channels.push_back(0);
            histSize.push_back(8);
            ranges.push_back(0);
            ranges.push_back(255);
        }else{ //rgb
            channels.push_back(0);
            channels.push_back(2);
            histSize.push_back(8);
            histSize.push_back(8);
            ranges.push_back(0);
            ranges.push_back(255);
        }

        tracker1 = createMeanShiftTracker(channels, histSize, ranges);
    }
    if(ui->radioButton_sgram->isChecked() || ui->radioButton_both->isChecked()){
        int nBins = 8;
        int nIter = 10;
        tracker2 = createSpatiogramTracker( nBins, nIter );
    }
    if(ui->radioButton_pf->isChecked()){
        tracker1 = createSpatialPFTracker(20, 8, 12.50, 12.50, 5.0);
    }
    // restore this
    cv::Mat im;
    tinfo2=tinfo1;
    treatImage(tinfo1.image, im);
    if (ui->radioButton_mshift->isChecked() || ui->radioButton_both->isChecked())
        tracker1->init(im, tinfo1.bbox);
    if(ui->radioButton_sgram->isChecked() || ui->radioButton_both->isChecked())
        tracker2->init(im, tinfo2.bbox);
    if(ui->radioButton_pf->isChecked())
        tracker1->init(im, tinfo1.bbox);
    timerImage->start();
}

void MainWindow::treatImage(cv::Mat &imin, cv::Mat &imout){

    if (ui->radioButton_histo1->isChecked()){
        cv::cvtColor(imin,imout,cv::COLOR_BGR2GRAY);
    }
    if (ui->radioButton_histo2->isChecked()){
        cv::Mat hsv;
        cv::cvtColor(imin,hsv,cv::COLOR_BGR2HSV);
        imout.create(hsv.size(), hsv.depth());
        int ch[] = {0, 0};
        cv::mixChannels(&hsv, 1, &imout, 1, ch, 1);
    }
    if (ui->radioButton_histo3->isChecked()){
        cv::Mat iminfloat;
        imin.convertTo(iminfloat, CV_32F);
        std::vector<cv::Mat> bgr;
        cv::split(iminfloat, bgr);
        std::vector<cv::Mat> c(3);
        c[0] = (bgr[0]-bgr[1]+255)/2;
        c[1] = (bgr[1]-bgr[2]+255)/2;
        c[2] = (bgr[0]+bgr[1]+bgr[2])/3;
        c[0].convertTo(c[0],CV_8UC1);
        c[1].convertTo(c[1],CV_8UC1);
        c[2].convertTo(c[2],CV_8UC1);

        cv::merge(c,imout);
    }

}

// CORE
void MainWindow::update_image_label(){
    capture >> inputImage;
    cv::resize(inputImage,inputImage,cv::Size(),0.4,0.4);
    outputImage=inputImage.clone();

    if(ui->radioButton_both->isChecked()){
        if (tracker1->started && tracker2->started){
            cv::Mat im;
            treatImage(outputImage, im);
            tracker1->update(im, tinfo1.bbox);
            tracker2->update(im, tinfo2.bbox);
            cv::rectangle( outputImage, tinfo1.bbox, cv::Scalar( 0, 0, 255 ), 2, cv::LINE_4 );
            cv::rectangle( outputImage, tinfo2.bbox, cv::Scalar( 0, 255, 0 ), 2, cv::LINE_4 );
        }
    }
    if(ui->radioButton_mshift->isChecked()){
        if (tracker1->started){
            cv::Mat im;
            treatImage(outputImage, im);
            tracker1->update(im, tinfo1.bbox);
            cv::rectangle( outputImage, tinfo1.bbox, cv::Scalar( 0, 0, 255 ), 2, cv::LINE_4 );
        }
    }
    if(ui->radioButton_sgram->isChecked()){
        if (tracker2->started){
            cv::Mat im;
            treatImage(outputImage, im); //cv::imshow("a",im);
            tracker2->update(im, tinfo2.bbox);
            cv::rectangle( outputImage, tinfo2.bbox, cv::Scalar( 0, 255, 0 ), 2, cv::LINE_4 );
        }
    }
    if(ui->radioButton_pf->isChecked()){
        if (tracker1->started){
            cv::Mat im;
            treatImage(outputImage, im);
            tracker1->update(im, tinfo1.bbox);

            cv::Ptr<spatialPFTracker> pft = tracker1.dynamicCast<spatialPFTracker>();
            if (!pft.empty()){
                std::vector<cv::Rect2d> parts;
                pft->getParticles(parts);
                for (size_t i=0; i<parts.size(); i++){
                    cv::rectangle( outputImage, parts[i], cv::Scalar( 255, 0, 255 ), 1, cv::LINE_4 );
                }
            }
            cv::rectangle( outputImage, tinfo1.bbox, cv::Scalar( 0, 255, 255 ), 2, cv::LINE_4 );
        }
    }

    QImage qim = mat2QImage(outputImage);
    ui->imageAxes->setPixmap(QPixmap::fromImage(qim));
    ui->imageAxes->show();
}

void MainWindow::onMouse( int event, int x, int y, int , void* p ){
    trackerinfo* info = (trackerinfo*) p;
    switch ( event ){
      case cv::EVENT_LBUTTONDOWN:
        //set origin of the bounding box
        info->startSelection = true;
        info->bbox.x = x;
        info->bbox.y = y;
        break;
      case cv::EVENT_LBUTTONUP:
        //sei with and height of the bounding box
        info->bbox.width = std::abs( x - info->bbox.x );
        info->bbox.height = std::abs( y - info->bbox.y );
        info->selectObject = true;
        break;
      case cv::EVENT_MOUSEMOVE:

        if( info->startSelection && !info->selectObject ){
          //draw the bounding box
          cv::Mat currentFrame;
          info->image.copyTo( currentFrame );
          cv::rectangle( currentFrame, cv::Point( info->bbox.x, info->bbox.y ),
                         cv::Point( x, y ), cv::Scalar( 255, 0, 0 ), 2, 1 );
          cv::imshow( "SELECT BOX", currentFrame );
        }
        break;
    }
}

void MainWindow::on_radioButton_mshift_clicked(){
    tracker1->started = false;
    tracker2->started = false;
}

void MainWindow::on_radioButton_sgram_clicked(){
    tracker1->started = false;
    tracker2->started = false;
}

void MainWindow::on_radioButton_both_clicked(){
    tracker1->started = false;
    tracker2->started = false;
}

void MainWindow::on_radioButton_pf_clicked(){
    tracker1->started = false;
    tracker2->started = false;
}

void MainWindow::on_radioButton_histo1_clicked(){
    tracker1->started = false;
    tracker2->started = false;
}

void MainWindow::on_radioButton_histo2_clicked(){
    tracker1->started = false;
    tracker2->started = false;
}

void MainWindow::on_radioButton_histo3_clicked(){
    tracker1->started = false;
    tracker2->started = false;
}
