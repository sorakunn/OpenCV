#include <opencv2/highgui/highgui.hpp>				/* 自定义绘制椭圆的函数 */
#include <opencv2/imgproc/imgproc.hpp>				/* ellipse方法 */
#define WINDOW_WIDTH 600
#define WINDOW_NAME "绘制椭圆"
using namespace cv;

//*自定义的绘制椭圆方法
void DrawEllipse(Mat img, double angle){
	int thickness = 2;
	int lineType = 8;
	ellipse(img,Point(WINDOW_WIDTH/2,WINDOW_WIDTH/2),Size(WINDOW_WIDTH/8,WINDOW_WIDTH/4),angle,0,360,Scalar(255,129,0),thickness,lineType);
}
//*/

int main(){
	Mat painting = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);		//创建画布
	DrawEllipse(painting,90);											//绘制椭圆
	imshow(WINDOW_NAME,painting);										//展示图像
	waitKey(0);
	return 0;
}
