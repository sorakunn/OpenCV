#include <opencv2/opencv.hpp>								/* 访问图像中像素（方法三） */
using namespace cv;											/* Mat.at<type>()方法 */

void colorReduce(Mat& srcImage, Mat& dstImage, int div){
	dstImage = srcImage.clone();
	int rowNumber = dstImage.rows;
	int colNumber = dstImage.cols;

	for(int i=0; i<rowNumber; i++){
		for(int j=0; j<colNumber; j++){
			dstImage.at<Vec3b>(i,j)[0] = dstImage.at<Vec3b>(i,j)[0]/div*div;	//不要忘了在<>中指定类型
			dstImage.at<Vec3b>(i,j)[1] = dstImage.at<Vec3b>(i,j)[1]/div*div;	//i,j表示像素点的行、列
			dstImage.at<Vec3b>(i,j)[2] = dstImage.at<Vec3b>(i,j)[2]/div*div;	//对于多通道的勿忘[]操作
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
 
