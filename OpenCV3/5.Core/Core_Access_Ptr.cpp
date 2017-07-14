#include <opencv2/opencv.hpp>					/* 访问图像中像素（方法一） */
using namespace cv;						/* Mat.rows成员, Mat.cols成员 */
								/* Mat.channels()方法,Mat.ptr<type>()方法 */

void colorReduce(Mat& srcImage, Mat& dstImage, int div){	//注意是引用传递“&”
	dstImage = srcImage.clone();
	int rowNumber = dstImage.rows;
	int colNumber = dstImage.cols * dstImage.channels();

	for(int i=0; i<rowNumber; i++){
		uchar* p = dstImage.ptr<uchar>(i);		//ptr函数用于取得任意行的首地址
		for(int j=0; j<colNumber; j++){
			*p++ = *p/div*div;			//用指针运算和自增代替[]操作符
		}
	}
}

int main(){
	Mat srcImage = imread("test.jpg");
	Mat dstImage;
	dstImage.create(srcImage.rows,srcImage.cols,srcImage.type());

	double time = (double) getTickCount();
	colorReduce(srcImage, dstImage, 30);
	time = ((double)getTickCount() - time ) / getTickFrequency();

	imshow("原图",srcImage);
	imshow("效果图",dstImage);
	waitKey(0);
	return 0;
}
