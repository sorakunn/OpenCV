#include "opencv2/highgui/highgui.hpp"				 /*颜色空间的转换函数*/
#include "opencv2/imgproc/imgproc.hpp"				 /* cvtColor方法 */
using namespace cv;

void main(){
	Mat srcImage,dstImage;
	srcImage = imread("test.jpg");					
	cvtColor(srcImage,dstImage,COLOR_BGR2RGB);		 //cvtColor((Mat)inputArray, (Mat)outputArray, int flag);
	imshow("颜色转换",dstImage);					  //注意BGR≠RGB
	waitKey(0);										 //OpenCV默认通道BGR
}

