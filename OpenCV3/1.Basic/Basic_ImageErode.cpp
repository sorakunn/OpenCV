#include<opencv2/highgui/highgui.hpp>		/* 测试形态学运算——“腐蚀”(用图像中暗色部分腐蚀掉高亮部分) */
#include<opencv2/imgproc/imgproc.hpp>		/* erode函数 */
using namespace cv;

int main(){
	Mat srcImage = imread("test.jpg");
	imshow("原图【腐蚀】",srcImage);
	
	Mat element = getStructuringElement(MORPH_RECT, Size(15,15));
	Mat dstImage;
	erode(srcImage,dstImage,element);

	imshow("效果图【腐蚀】",dstImage);
	waitKey(0);
	return 0;
}
