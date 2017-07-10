#include<opencv2/opencv.hpp>				/* 调用摄像头采集图像 */
using namespace cv;

int main(){
	//*/从摄像头读入视频
	VideoCapture capture(0);			//capture(0)代表视频来源为摄像头
	Mat edges;
	//*/

	while(1){					//循环显示每一帧
		Mat frame;					//定义一个Mat存储每一帧图像
		capture>>frame;					//读取当前帧

		//*Canny边缘检测
		cvtColor(frame,edges,COLOR_BGR2GRAY);		//转灰度
		blur(edges,edges,Size(7,7));			//降噪
		Canny(edges,edges,0,30,3);			//Canny边缘检测
		//*/

		imshow("调用摄像头采集图像",edges);		//显示当前帧

		//*按ESC退出
		char pressedKey = waitKey(30);
		if(pressedKey == 27) break;
		//*/
	}

	return 0;
}
