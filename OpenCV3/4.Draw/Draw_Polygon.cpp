#include <opencv2/highgui/highgui.hpp>				/* 自定义绘制填充多边形的函数 */
#include <opencv2/imgproc/imgproc.hpp>				/* fillPoly方法 */
#define WINDOW_WIDTH 600
#define WINDOW_NAME "绘制填充多边形"
using namespace cv;

//*自定义的绘制填充多边形方法
void DrawPolygon(Mat img){
	int lineType = 8;

	//*逐一创建组成顶点集的点
	Point rookPoints[1][20];
	rookPoints[0][0] = Point(WINDOW_WIDTH/4,7*WINDOW_WIDTH/8);
	rookPoints[0][1] = Point(3*WINDOW_WIDTH/4,7*WINDOW_WIDTH/8);
	rookPoints[0][2] = Point(3*WINDOW_WIDTH/4,13*WINDOW_WIDTH/16);
	rookPoints[0][3] = Point(11*WINDOW_WIDTH/16,13*WINDOW_WIDTH/16);
	rookPoints[0][4] = Point(19*WINDOW_WIDTH/32,3*WINDOW_WIDTH/8);
	rookPoints[0][5] = Point(3*WINDOW_WIDTH/4,3*WINDOW_WIDTH/8);
	rookPoints[0][6] = Point(3*WINDOW_WIDTH/4,WINDOW_WIDTH/8);
	rookPoints[0][7] = Point(26*WINDOW_WIDTH/40,WINDOW_WIDTH/8);
	rookPoints[0][8] = Point(26*WINDOW_WIDTH/40,WINDOW_WIDTH/4);
	rookPoints[0][9] = Point(22*WINDOW_WIDTH/40,WINDOW_WIDTH/4);
	rookPoints[0][10] = Point(22*WINDOW_WIDTH/40,WINDOW_WIDTH/8);
	rookPoints[0][11] = Point(18*WINDOW_WIDTH/40,WINDOW_WIDTH/8);
	rookPoints[0][12] = Point(18*WINDOW_WIDTH/40,WINDOW_WIDTH/4);
	rookPoints[0][13] = Point(14*WINDOW_WIDTH/40,WINDOW_WIDTH/4);
	rookPoints[0][14] = Point(14*WINDOW_WIDTH/40,WINDOW_WIDTH/8);
	rookPoints[0][15] = Point(WINDOW_WIDTH/4,WINDOW_WIDTH/8);
	rookPoints[0][16] = Point(WINDOW_WIDTH/4,3*WINDOW_WIDTH/8);
	rookPoints[0][17] = Point(13*WINDOW_WIDTH/32,3*WINDOW_WIDTH/8);
	rookPoints[0][18] = Point(5*WINDOW_WIDTH/16,13*WINDOW_WIDTH/16);
	rookPoints[0][19] = Point(WINDOW_WIDTH/4,13*WINDOW_WIDTH/16);
	//*/


	//*创建顶点集ppt
	const Point* ppt[1] = {rookPoints[0]};			//rookPoints[0]元素为数组指针
													//声明为 Point (*rookPoint)[20]
													//即指向“包含20个点的数组”的指针
	//这里的ppt类型为“数组指针”的数组，其内的每个“数组指针”都是一个多边形
	//const关键字放在了Point*的左边，代表指针所指向的内容是常量
	//*/


	//*创建顶点数目集npt
	int npt[] = {20};
	//同理，由于顶点集内可能包含多个“数组指针”，因此顶点数目集也是数组
	//*/

	fillPoly(img,ppt,npt,1,Scalar(255,255,255),lineType);
	//数组名代表行指针，即“指向指针的指针”，所以是Point**类型的
}


int main(){
	Mat painting = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);		//创建画布
	DrawPolygon(painting);												//绘制填充多边形
	imshow(WINDOW_NAME,painting);										//展示图像
	waitKey(0);
	return 0;
}
