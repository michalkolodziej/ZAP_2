#include "mapa.h"
#include <unistd.h>

using namespace cv;
using namespace std;



void imgtoarray(Mat image, macierz **&tablica)
{

    //Mat gray_image;
    //cvtColor(image, gray_image, CV_BGR2GRAY);

    //imwrite("Gray_Image.jpg", gray_image);

    //namedWindow("nazwa", CV_WINDOW_AUTOSIZE);
    //namedWindow("Gray image", CV_WINDOW_AUTOSIZE);
    Mat imgconv;
    image.convertTo(imgconv, CV_32S);

    if (imgconv.isContinuous()) {
        imgconv = imgconv.reshape(1, 1);
    }

    int *ptrarray = new int[imgconv.cols];

    for (int i = 0; i < imgconv.rows; ++i) {
        ptrarray = imgconv.ptr<int>(i);
    }
    //int **tablica = new int*[gray_image.rows];
    int k = 0;
    for (int i = 0; i < image.rows; i++)
    {
        //tablica[i] = new int[gray_image.cols];
        for (int j = 0; j < image.cols; j++)
        {
            tablica[i][j].waga = 255-ptrarray[k];
            //cout << tablica[i][j].waga << " ";
            k++;
        }
        //cout << endl;
    }
}

/*void showimg(string nazwa, Mat img)
{
    namedWindow(nazwa, CV_WINDOW_AUTOSIZE);
    imshow(nazwa, img);
}
*/
void szukaj(macierz **&mapa, int w, int k,  Ui::MainWindow *ui)
{   
    int wi = 0;
    int ko = 0;
    int suma = mapa[0][0].f;
    int parzysta = 0;

    while (1)
    {
        //usleep(30000);
        if (wi == w - 1 && ko == k - 1) break;
        if (wi == w - 1)
        {
            suma = suma + mapa[wi][ko + 1].f;
            mapa[wi][ko].kolejka = 0;

            ko++;
        }
        else if (ko == k - 1)
        {
            suma = suma + mapa[wi + 1][ko].f;
            mapa[wi][ko].kolejka = 0;

            wi++;

        }
        else
        {
            suma = suma + min(mapa[wi][ko + 1].f, mapa[wi + 1][ko].f);

            if (mapa[wi][ko + 1].f < mapa[wi + 1][ko].f)
            {
                mapa[wi][ko].kolejka = 0;

                ko++;

            }
            else if (mapa[wi][ko + 1].f > mapa[wi + 1][ko].f)
            {
                mapa[wi][ko].kolejka = 0;

                wi++;
                // cout<<"w++"<<endl;
            }
            else if (mapa[wi][ko + 1].f == mapa[wi + 1][ko].f)
            {
                mapa[wi][ko].kolejka = 0;
                if (parzysta % 2 == 0) wi++;
                else ko++;
                parzysta++;

            }

        }

        if (wi == w - 1)
            if (ko == k - 1)
            {
                mapa[wi][ko].kolejka = 0;
                break;
            }

//        Mat array_img_cv = Mat(w, k, CV_8UC1, array_img);

        //array_img_cv = 255 - array_img_cv;

       // ui->label->setPixmap(QPixmap::fromImage(QImage(array_img_cv.data, array_img_cv.cols, array_img_cv.rows, array_img_cv.step, QImage::Format_Grayscale8)));


    }
}
