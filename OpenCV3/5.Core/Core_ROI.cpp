#include <opencv2/opencv.hpp>								/* 感兴趣区域ROI的选取 */
using namespace cv;											/* 用Rect框选、Range框选 */

int main(){
	Mat back = imread("back.jpg");
	Mat front = imread("front.jpg");
	//Mat imageROI = back(Rect(290,290,front.cols,front.rows));					//宽高				
	Mat imageROI = back(Range(290,290+front.rows),Range(290,290+front.cols));	//高宽

	//*对感兴趣区域进行遮罩复制操作
	Mat mask = Mat(150,150,CV_8U,Scalar::all(0));			
	circle(mask,Point(75,75),75,Scalar::all(255),-1,8);		//生成一个圆形遮罩
	front.copyTo(imageROI,mask);							//黑色说明有膜无法透过，白色说明无膜可以透过
	//*/

	imshow("效果图",back);
	waitKey(0);
	return 0;
}
