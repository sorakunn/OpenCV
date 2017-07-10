#include <opencv2/opencv.hpp>										/* 为窗口创建控制用的滑动条 */
#include <opencv2/highgui/highgui.hpp>										
using namespace cv;															/* createTrackbar方法, on_Trackbar方法, getTrackbarPos方法 */
#define WINDOW_NAME "线性混合示例"							 /* 原理：通过一个中介函数配合一个回调函数实现 */

//滑动条参数
const int g_nMaxAlphaValue = 100;
int g_nAlphaValueSlider;
double g_dAlphaValue;
double g_dBetaValue;

//图像存放变量
Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;


void on_Trackbar(int,void* ){						// 回调函数 onTrackbar( (int)position, (void*)userdata );
																				//		(1)滑块当前位置
																				//		(2)用户传入数据  (若使用全局变量则不需传入数据)
                                        
	//AlphaValue与BetaValue的计算
	g_dAlphaValue = (double)g_nAlphaValueSlider/g_nMaxAlphaValue;
	g_dBetaValue = 1.0 - g_dAlphaValue;
  
	//线性混合
	addWeighted(g_srcImage1,g_dAlphaValue,g_srcImage2,g_dBetaValue,0.0,g_dstImage);
	imshow(WINDOW_NAME,g_dstImage);
  
}


int main(){


  //*准备工作
	g_srcImage1 = imread("background.jpg"); //读取背景图片
	g_srcImage2 = imread("foreground.jpg"); //读取前景图片
	if(!g_srcImage1.data){
		printf("读取第一幅图片失败，请检查目录");
		return -1;
	}
	if(!g_srcImage2.data){
		printf("读取第二幅图片失败，请检查目录");
		return -1;
	}
	g_nAlphaValueSlider = 50;	  //设置初始位置为70
	namedWindow(WINDOW_NAME,1); //创建窗口
  //*/
  
  
	//*创建滑动条
	createTrackbar("透明值", WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar);
	// createTrackbar("trackbar_name", "window_name", (int*)position, (int)length, (*)on_Trackbar, (void*)userdata);	[int]
	//！创建一个指定名字的滑动条在指定窗口上,并指定滑块当前位置、滑块最大位置、回调函数
																							//(1)轨迹条名
																							//(2)要创建轨迹条的窗口名
																							//(3)滑块当前位置(创建时作为初始值)	【用&取成指针】
																							//(4)滑块最大位置
																							//(5)回调函数 on_Trackbar
  //*/
  
	on_Trackbar(g_nAlphaValueSlider,0);         //手动执行一次回调函数避免开始时未拖动显示空白
	waitKey(0);
	return 0;
}

	// getTrackbarPos("trackbarName","windowName");	[int]
	//！获取指定窗口指定名字的滑动条的位置值
	//    (1)滑动条名
	//    (2)滑动条所属窗口名
