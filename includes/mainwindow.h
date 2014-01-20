#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QImage>
#include "qt_opencv.hpp"
#include "mcv_tracker.hpp"
#include "meanShift_tracker.hpp"
#include "spatiogram_tracker.hpp"
#include "spatial_pf_tracker.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void start_timer_image(void);
    static void onMouse( int event, int x, int y, int f, void* p );

private slots:
    void on_pushButton_track_clicked(bool checked);
    void on_radioButton_mshift_clicked();
    void on_radioButton_sgram_clicked();
    void update_image_label();
    void on_pushButton_track_clicked();
    void on_radioButton_both_clicked();
    void on_radioButton_pf_clicked();
    void on_radioButton_histo1_clicked();
    void on_radioButton_histo2_clicked();
    void on_radioButton_histo3_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timerImage;
    cv::VideoCapture capture;
    cv::Mat inputImage;
    cv::Mat outputImage;
    trackerinfo tinfo1;
    trackerinfo tinfo2;
    cv::Ptr<mcv_tracker> tracker1;
    cv::Ptr<mcv_tracker> tracker2;

    void treatImage(cv::Mat &imin, cv::Mat &imout);
};

#endif // MAINWINDOW_H
