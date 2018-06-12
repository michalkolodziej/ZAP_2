/**
 * \file mainwindow.h
 * \brief Plik nagłówkowy klasy \a mainwindow.
 *
 * Moduł \a mapa zawiera funkcje obsługujące okno w programie.
 *
 * \see mainwinodw.cpp
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QApplication>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QFileDialog>
#include <QDebug>
#include <QTimer>
#include <fstream>
#include "mapa.h"
#include "graf1.h"
#include "modul_2.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button_clicked();
    //void timer_update();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QTimer *timer;
};

#endif // MAINWINDOW_H
