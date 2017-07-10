#include<opencv2/highgui/highgui.hpp>										/* 测试形态学运算——“Canny边缘检测”(将载入图像转为灰度图并检测边缘) */
#include<opencv2/imgproc/imgproc.hpp>										/* Canny函数 */
using namespace cv;
int main(){
	Mat srcImage = imread("test.jpg");
	imshow("原图【canny边缘检测】",srcImage);
  
	//创建与srcImage同大小同类型的矩阵
	Mat dstImage,edge,grayImage;
	dstImage.create( srcImage.size(), srcImage.type() );
  
	//进行边缘检测	【转灰度→降噪→Canny函数】
	cvtColor(srcImage,grayImage,COLOR_BGR2GRAY);				//将图像转换为灰度图像
	blur(grayImage,edge,Size(3,3));								      //使用 3x3 内核来降噪
	Canny(edge,dstImage,3,9,3);								        	//运行Canny函数

	imshow("效果图【canny边缘检测】",dstImage);
	waitKey(0);
	return 0;
}
