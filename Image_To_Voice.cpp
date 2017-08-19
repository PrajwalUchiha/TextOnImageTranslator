#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp>
#include<stdio.h> 
#include <math.h>
#include<fstream>
#include<stdlib.h>
using namespace cv; 
using namespace std; 
int main() 
{
Mat img1,img_bin,img_gray;
system("wget -A photoaf.jpg 192.168.43.1:8080/photoaf.jpg ");
//cvWaitKey(2000);
img1 = cvLoadImage("/home/pi/photoaf.jpg");
cvtColor(img1,img_gray,CV_RGB2GRAY);
threshold(img_gray, img_bin, 180, 255, THRESH_BINARY);
cvNamedWindow("Display", CV_WINDOW_AUTOSIZE);
imshow("Display",img_bin);
imwrite("/home/pi/ocr.tif",img_bin);
//cvWaitKey(0);
system("tesseract ocr.tif srctext");
system("rm photoaf.jpg");
cvDestroyWindow("Display");
system("sudo python3 convert.py");
system("espeak -f translatedtext.txt --stdout | aplay");
//cvWaitKey(2000);
}


