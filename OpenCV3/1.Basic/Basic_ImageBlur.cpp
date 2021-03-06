#include<opencv2/highgui/highgui.hpp>					/* 测试形态学运算——“均值滤波”(模糊一幅图像) */
#include<opencv2/imgproc/imgproc.hpp>					/* blur函数 */
using namespace cv;

int main(){
	Mat srcImage = imread("test.jpg");
	imshow("原图【均值滤波】", srcImage);

	Mat dstImage;
	blur(srcImage, dstImage, Size(7,7));

	imshow("效果图【均值滤波】",dstImage);
	waitKey(0);
	return 0;
}
