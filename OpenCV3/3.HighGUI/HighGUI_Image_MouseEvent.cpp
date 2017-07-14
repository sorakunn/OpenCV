#include <opencv2/opencv.hpp			/*为窗口创建鼠标事件*/
using namespace cv;				/* SetMouseCallback方法, on_Mouse方法 */
#define WINDOW_NAME "鼠标事件"		     /* 原理：通过一个中介函数配合一个回调函数实现 */


//全局变量声明
Rect g_rectangle;
bool g_bDrawingBox = false;//是否进行绘制
RNG g_rng(12345);


//*定制的矩形绘制函数
void DrawRectangle(Mat& img, Rect box){
	rectangle(img,box.tl(),box.br(),Scalar(g_rng.uniform(0,255),g_rng.uniform(0,255),g_rng.uniform(0,255)));
}
//*/


//* 鼠标事件回调函数
void on_Mouse(int event, int x, int y, int flags, void* param ){
//回调函数 on_Mouse( (int)event, (int)x, (int)y, (int)flags, (void*)param );
//	(1)鼠标发生事件（移动、按下、弹起、双击）
//		a)移动：EVENT_MOUSEMOVE
//		b)左键：EVENT_LBUTTONUP、EVENT_LBUTTONDOWN、EVENT_LBUTTONDBLCLK
//		c)右键：EVENT_RBUTTONUP、EVENT_RBUTTONDOWN、EVENT_RBUTTONDBLCLK
//		d)中键：EVENT_MBUTTONUP、EVENT_MBUTTONDOWN、EVENT_MBUTTONDBLCLK
//	(2)图像坐标系的x坐标
//	(3)图像坐标系的y坐标
//	(4)鼠标的拖拽事件/键盘鼠标联合事件
//		a)左鍵拖曳：EVENT_FLAG_LBUTTON
//		b)右键拖曳：EVENT_FLAG_RBUTTON
//		c)中键拖曳：EVENT_FLAG_MBUTTON
//		d)按住Ctrl：EVENT_FLAG_CTRLKEY
//		e)按住Shift：EVENT_FLAG_SHIFTKEY
//		f)按住Alt：EVENT_FLAG_ALTKEY																		
//	(5)传进来的控制参数
							
	Mat& image = *(Mat*) param;
	switch(event){
	
	case EVENT_MOUSEMOVE:{				//鼠标移动情况
			if(g_bDrawingBox){		//如果标识符为真，则记录下长和宽到RECT变量中
				g_rectangle.width = x-g_rectangle.x;
				g_rectangle.height = y-g_rectangle.y;
			}
		}
		break;

	case EVENT_LBUTTONDOWN:{			//鼠标左击情况
			g_bDrawingBox = true;			
			g_rectangle = Rect(x,y,0,0);	//记录起始点
		}
		break;

	case EVENT_LBUTTONUP:
		{
			g_bDrawingBox = false;
			//对宽和高小于0的情况进行处理
			if(g_rectangle.width<0){
				g_rectangle.x += g_rectangle.width;
				g_rectangle.width *= -1;
			}
			if(g_rectangle.height<0){
				g_rectangle.y += g_rectangle.height;
				g_rectangle.height *= -1;
			}
			//调用函数进行绘制
			DrawRectangle( image, g_rectangle);
		}
		break;
	}
}
//*/


int main(int argc, char** argv){


	//*准备工作
	g_rectangle = Rect(-1,-1,0,0);
	Mat srcImage(600, 800, CV_8UC3),tempImage;
	srcImage.copyTo(tempImage);
	srcImage = Scalar::all(0);
	//*/
	
	
	//*设置鼠标事件的回调函数
	namedWindow(WINDOW_NAME);
	setMouseCallback(WINDOW_NAME,on_Mouse, (void*)&srcImage);	// SetMouseCallback("window_name",(fun*)on_Mouse, (void*)userdata);
										//！为指定的窗口设置鼠标回调函数
										//(1)窗口名
										//(2)鼠标回调函数
										//(3)传递给回调函数的参数
	//*/


	//*程序主循环，当进行绘制的标识符为真时，进行绘制
	while(1)
	{
		srcImage.copyTo(tempImage);			//复制源图到临时变量
		if(g_bDrawingBox)
			DrawRectangle(tempImage, g_rectangle);	//当进行绘制的标识符为真时，则进行绘制
		imshow(WINDOW_NAME,tempImage);
		if( waitKey(10) == 27) break;			//按下ESC键，程序推出
	}
	//*/
	
	return 0;
}
