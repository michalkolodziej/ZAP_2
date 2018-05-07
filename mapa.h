#pragma once
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <iostream>
#include <fstream>
using  namespace std;
struct macierz;
using namespace cv;
using namespace std;

void **imgtoarray(Mat image, macierz **&tablica);

void showimg(string nazwa, Mat img);
