#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_update()));
    //Mat *obrazek = new Mat;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_clicked()
{
    ui->button->setVisible(0);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    ".",
                                                    tr("Images (*.png *.bmp *.jpg)"));

    Mat img;
    string name = fileName.toStdString();

    img = imread(name);
    Mat gray_image; //change color to gray scale
    cvtColor(img, gray_image, COLOR_BGR2GRAY);

    //cvtColor(img, img, COLOR_BGR2GRAY);
    macierz **mapa = new macierz*[gray_image.rows];
    for (int i = 0; i < gray_image.rows; i++)
    {
        mapa[i] = new macierz[gray_image.cols];
    }

    imgtoarray(gray_image, mapa);

    wypelnij(mapa, gray_image.rows, gray_image.cols);

    punkt poczatek, koniec;
    ustawpunkt(poczatek, koniec);

    int w = gray_image.rows;
    int k = gray_image.cols;


    liczG(poczatek, mapa, w, k);
    F_g_h(mapa, w, k);
    szukaj(mapa, w, k, ui);

    unsigned char *array_img = new unsigned char[w*k];

    int pomoc = 0;
    for(int i = 0; i < w; i++)
    {
        for (int j = 0; j < k; j++) {
            array_img[pomoc] = (unsigned char)mapa[i][j].kolejka;
            pomoc++;
        }
    }
    Mat array_img_cv = Mat(w, k, CV_8UC1, array_img);
    array_img_cv = 255 - array_img_cv;
    imwrite("/home/michal/Pictures/wyjscie.png", array_img_cv);
    ui->label->setPixmap(QPixmap::fromImage(QImage(array_img_cv.data, array_img_cv.cols, array_img_cv.rows, array_img_cv.step, QImage::Format_Grayscale8)));
    ui->button->setVisible(1);

    for (int i = 0; i < w; i++) {
        delete mapa[i];
    }
    delete mapa;
    delete array_img;

}

void MainWindow::on_pushButton_clicked()
{
    ui->button->setVisible(0);
    //włącza rysowanie

}
