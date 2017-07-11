#include <opencv2/highgui/highgui.hpp>				/* 自定义绘制实心圆的函数 */
#include <opencv2/imgproc/imgproc.hpp>				/* circle方法 */
#define WINDOW_WIDTH 600
#define WINDOW_NAME "绘制实心圆"
using namespace cv;

//*自定义的绘制实心圆方法
void DrawFilledCircle(Mat img, Point center){
	int thickness = -1;								//线条宽度-1代表“图形实心”
	int lineType = 8;
	circle(img,center, WINDOW_WIDTH/32, Scalar(0,0,255), thickness,lineType);
}
//*/

int main(){
	Mat painting = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);		//创建画布
	DrawFilledCircle(painting,Point(WINDOW_WIDTH/2,WINDOW_WIDTH/2));	//绘制实心圆
	imshow(WINDOW_NAME,painting);										//展示图像
	waitKey(0);
	return 0;
}
