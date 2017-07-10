#include<opencv2/opencv.hpp>			/*读取并播放视频*/
using namespace cv;				/* VideoCapture类 */

int main(){
	VideoCapture capture("test.avi");	//读入视频

	while(1){				//循环播放每一帧
		Mat frame;				//定义一个Mat变量，用于存储每一帧图像
		capture >> frame;			//读取当前帧

		//*若视频播放完成，退出循环
		if(frame.empty()){
			break;
		}
		//*/

		imshow("读取视频测试",frame);	   //显示当前帧

		//*按ESC退出
		char pressedKey = waitKey(30);
		if(pressedKey == 27) break;
		//*/
	}

	return 0;
}

