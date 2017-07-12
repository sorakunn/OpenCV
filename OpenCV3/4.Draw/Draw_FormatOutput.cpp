#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;


int main(){
	Mat srcImage;
	srcImage = imread("test.jpg");
	cvtColor(srcImage,srcImage,COLOR_BGR2GRAY);
	cout << "矩阵为：" << endl << format(srcImage,"python") << endl;
	imshow("图片",srcImage);
	waitKey(0);
	return 0;
}
