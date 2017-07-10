#include <opencv2/opencv.hpp>							      	/* 该程序用来显示当前OpenCV版本 */
using namespace cv;																/* printf函数, cout函数 */
using namespace std;                              //使用C++风格输出时不要忘了	using namespace std;

void main(){
	printf("当前使用的OpenCV版本为：OpenCV"CV_VERSION);	   //C风格			prinf("%d",num)
	cout<<endl;															             	//C++风格		cout<<"版本为："<<CV_VERSION<<"版"	
}

