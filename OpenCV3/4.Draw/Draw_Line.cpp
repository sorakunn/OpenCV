#include <opencv2/highgui/highgui.hpp>				/* 自定义绘制线的函数 */
#include <opencv2/imgproc/imgproc.hpp>				/* line方法 */
#define WINDOW_WIDTH 600
#define WINDOW_NAME "绘制线"
using namespace cv;

//*自定义的绘制线方法
void DrawLine(Mat img, Point start,Point end){
	int thickness = 2;
	int lineType = 8;
	line(img,start,end,Scalar(255,255,255),thickness,lineType);
}
//*/

int main(){
	Mat painting = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);					//创建画布
	DrawLine(painting,Point(WINDOW_WIDTH/4,WINDOW_WIDTH/2),Point(3*WINDOW_WIDTH/4,WINDOW_WIDTH/2));	//绘制线
	imshow(WINDOW_NAME,painting);									//展示图像
	waitKey(0);
	return 0;
}
