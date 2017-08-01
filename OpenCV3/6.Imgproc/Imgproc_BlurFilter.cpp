#include<opencv2/highgui/highgui.hpp>						/* 均值模糊 */
#include<opencv2/imgproc/imgproc.hpp>						/* blurFilter方法 */
#define WINDOW_NAME "均值模糊"
using namespace cv;

int g_nBlurFilterValue = 3;
Mat g_srcImage, g_dstImage;

void onTrackbar(int,void*){
	blur(g_srcImage, g_dstImage, Size(g_nBlurFilterValue+1,g_nBlurFilterValue+1));
	imshow(WINDOW_NAME,g_dstImage);
}

int main(){
	//载入图片
	g_srcImage = imread("test.jpg");
	//创建轨迹条
	namedWindow(WINDOW_NAME);
	createTrackbar("邻域大小", WINDOW_NAME, &g_nBlurFilterValue, 40, onTrackbar);
	onTrackbar(g_nBlurFilterValue,0);
	//显示结果
	imshow("原图",g_srcImage);
	imshow(WINDOW_NAME,g_dstImage);
	waitKey(0);
	return 0;
}
