#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "image_header.h"

using namespace cv;
using namespace std;

#define BGR 1

struct ImgPackHdr header;
struct ImgPackHdr *hdr = &header;

void fill_hdr(Mat *image);
void fill_hdr(Mat *image){
    // General info
    hdr->ver = 2;
    hdr->hsz = sizeof(ImgPackHdr);
    hdr->w = image->cols;
    hdr->h = image->rows;
    hdr->format = BGR;
    hdr->tm = time(NULL);
    hdr->mtype = image->type();

}

int main()
{
        Mat image;
        Mat image1;


        image = imread("image.jpeg",  IMREAD_UNCHANGED );
        fill_hdr(&image);

        if (!image.data) {
            cout << "Could not open the image.jpeg file" << endl;
            return -1;
        }
        else {

            cv::namedWindow("cvmat", cv::WINDOW_AUTOSIZE );
            cv::imshow("cvmat", image );

            uint totalElements = image.total()*image.channels();
            cv::Mat flat = image.reshape(1, totalElements);
            if(!image.isContinuous()) {
                flat = flat.clone(); // O(N),
            }

            uchar * ptr = flat.data;
            hdr->buf_size = flat.dataend-flat.datastart;

            // send data to socket
            // ......
            // receive data from socket

            cv::Mat restored = cv::Mat(hdr->h, hdr->w, hdr->mtype, ptr);
            cv::namedWindow("reconstructed", cv::WINDOW_AUTOSIZE);
            cv::imshow("reconstructed", restored);

            cv::waitKey(0);
            image.release();
            image1.release();
            return 0;
        }
}