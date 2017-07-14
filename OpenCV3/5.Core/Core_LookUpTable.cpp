#include <opencv2/opencv.hpp>					/* 颜色空间缩减 */
using namespace cv;						/* LUT方法 */

int main(){
	//准备工作
	Mat srcImage,dstImage;
	srcImage = imread("test.jpg");

	//生成一个查找表
	int table[256];
	int div = 30;
	for(int i=0; i<256; i++)
		table[i] = i/div *div;

	//将查找表转换为Mat型
	Mat lookUpTable = Mat(1,256,CV_8U);
	uchar *p = lookUpTable.data;
	for(int i=0; i<256; i++)
		p[i] = table[i];

	//调用LUT函数进行颜色空间缩减
	LUT(srcImage,lookUpTable,dstImage);

	//显示图片
	imshow("原图",srcImage);
	imshow("颜色空间缩减",dstImage);
	waitKey(0);
	return 0;
}
