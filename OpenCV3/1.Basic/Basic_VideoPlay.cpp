#include<opencv2/opencv.hpp>										/*读取并播放视频*/
using namespace cv;															/* VideoCapture类 */

int main(){
	VideoCapture capture("test.avi");
  
	while(1){
		Mat frame;
		capture >> frame;
		imshow("读取视频测试",frame);
    
		//*按ESC退出
		char pressedKey = waitKey(30);
		if(pressedKey == 27) break;
		//*/
	}
  
	return 0;
}

/*	c++的基本输入语句：
	cin：	Console Input	
	cout：	Console Output	
	endl：	end of line
*/

/*	CMake：	crossplatform make	跨平台安装(编译)程序
*/
