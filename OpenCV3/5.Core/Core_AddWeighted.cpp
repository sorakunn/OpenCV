#include <opencv2/opencv.hpp>				/* 两矩阵加权混合 */
using namespace cv;					/* addWeighted方法 */
using namespace std;
int main(){
	//图像读取
	Mat backImage = imread("back.jpg");		//混合的两幅图像必须
	Mat frontImage = imread("front.jpg");		//具有相同的尺寸
	Mat dstImage;
	if(backImage.empty()){
		cout << "背景图读取错误" << endl;
		return false;
	}
	if(frontImage.empty()){
		cout << "前景图读取错误" << endl;
		return false;
	}
	//两矩阵加权混合
	addWeighted(backImage,0.5,frontImage,0.5,0,dstImage);
	//显示图片
	imshow("线性混合",dstImage);
	waitKey(0);
	return 0;
}
