#include <opencv2\highgui\highgui.hpp>				/* 方框滤波 */
#include <opencv2\imgproc\imgproc.hpp>				/* boxFilter方法 */
#define WINDOW_NAME "方框模糊"
using namespace cv;

int g_nBoxFilterValue = 3;	//轨迹条参数值
Mat g_srcImage,g_dstImage;

void onTrackbar(int, void*){
	boxFilter(g_srcImage, g_dstImage, -1, Size(g_nBoxFilterValue+1,g_nBoxFilterValue+1));	//注意滤波器Size不能小于(1,1)
	imshow("方框模糊",g_dstImage);
}

int main(){
	//读取图片
	g_srcImage = imread("test.jpg");
	//创建滚动条
	namedWindow(WINDOW_NAME);
	createTrackbar("邻域大小", WINDOW_NAME, &g_nBoxFilterValue, 40, onTrackbar);
	onTrackbar(g_nBoxFilterValue,0);
	//显示图片
	imshow("原图",g_srcImage);
	imshow("方框模糊",g_dstImage);
	waitKey(0);
	return 0;
}
