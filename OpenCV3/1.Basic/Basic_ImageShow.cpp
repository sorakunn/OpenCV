#include<opencv2\opencv.hpp>		/* 基本的图片显示功能的测试 */
using namespace cv;			/* imread方法, imshow方法 */

void main(){
  Mat srcImage = imread("test.jpg");	//imread( "picture_name.xxx", (enum)color_type );	[Mat]read_image 
					//！读取文件中的图片到OpenCV中
					//(1)图片路径
					//(2)颜色类型		0-灰度		1-彩色		2-深度图像

	imshow("显示图片",srcImage);     //imshow( "window_name", (Mat)image );
					//！在指定窗口显示指定图像
					//(1)窗口名称
					//(2)图像名称
	waitKey(0);
}
