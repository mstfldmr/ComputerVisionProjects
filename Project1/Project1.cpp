#define Pi 3.1415926
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>


using namespace cv;
using namespace std;

float Amplitude(float x);


void rotate(cv::Mat& src, double angle, cv::Mat& dst)
{
    int len = std::max(src.cols, src.rows);
    cv::Point2f pt(len / 2., len / 2.);
    cv::Mat r = cv::getRotationMatrix2D(pt, angle, 1.2);

    cv::warpAffine(src, dst, r, cv::Size(len, len));
}


float Amplitude(float x)
{
    float A;
    if (x < 0)
    {
        A = abs((127.5 / 10)*abs(x)-127.5);

    }
    if (x >= 0)
    {
        A = ((127.5 / 10)*abs(x))+127.5;
    }

    return A;

}


int main(int argc, char ** argv)
{
    int max = 500;
    Mat image(max, max, CV_8UC1);
    int phase = 30;
    int frequency = 20;
    float A = 0,x,rotation;

    //image = imread("sample.jpg", CV_LOAD_IMAGE_COLOR);
    //Mat image(max, max, CV_8UC3, Scalar(1, 1, 1));


    cout << "Enter Amplitude " << endl;
    cin >> x;

    cout << "Enter Frequency " << endl;
    cin >> frequency;

    cout << "Enter Rotation " << endl;
    cin >> rotation;

    A = Amplitude(x);
    cout << "Brightness is " << A << endl;


    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)

        {
            if (i>0 && j>0) {
                image.at<uchar>(i, j) = abs(A * sin(2 * Pi * frequency / max * (i) + phase));
            }
            //image.at<uchar>(i, j)
        }


    }

    cv::Mat dst;
    rotate(image, rotation, dst);

    //cout << "M = " << endl << " " << image << endl << endl;

    namedWindow("DisplayWindow", WINDOW_AUTOSIZE);// Create a window for display.
    imshow("DisplayWindow", dst);                   // Show our image inside it.


    namedWindow("FourierWindow", WINDOW_AUTOSIZE);// Create a window for display.
    imshow("FourierWindow", dst);                   // Show our image inside it.
    waitKey(0);
}