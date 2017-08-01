#include<opencv2/highgui/highgui.hpp>					/* 高斯模糊 */
#include<opencv2/imgproc/imgproc.hpp>					/* GaussianBlur方法 */
#define WINDOW_NAME "高斯滤波"
using namespace cv;

int g_nGaussianBlurFilterValue = 3;
Mat g_srcImage, g_dstImage;

void onTrackbar(int,void*){
	GaussianBlur(g_srcImage, g_dstImage, Size(g_nGaussianBlurFilterValue*2+1,g_nGaussianBlurFilterValue*2+1), 0, 0);
	imshow(WINDOW_NAME,g_dstImage);
}

int main(){
	//载入图片
	g_srcImage = imread("test.jpg");
	//创建轨迹条
	namedWindow(WINDOW_NAME);
	createTrackbar("邻域大小", WINDOW_NAME, &g_nGaussianBlurFilterValue, 40, onTrackbar);
	onTrackbar(g_nGaussianBlurFilterValue,0);
	//显示图片
	imshow("原图",g_srcImage);
	imshow(WINDOW_NAME,g_dstImage);
	waitKey(0);
	return 0;
}
