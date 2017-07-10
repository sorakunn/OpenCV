#include<opencv2/opencv.hpp>				    	/* 调用摄像头采集图像 */
using namespace cv;

int main(){
	VideoCapture capture(0);
	Mat edges;

	while(1){
		Mat frame;
		capture>>frame;

		//*	Canny边缘检测
		cvtColor(frame,edges,COLOR_BGR2GRAY);	//转灰度
		blur(edges,edges,Size(7,7));			    //降噪
		Canny(edges,edges,0,30,3);				    //Canny边缘检测
		//*/

		imshow("调用摄像头采集图像",edges);

		//*	按ESC退出
		char pressedKey = waitKey(30);
		if(pressedKey == 27) break;
		//*/
	}
  
	return 0;
}
