#include <opencv2/opencv.hpp>						/* 通道的分离、合并 */
using namespace cv;									/* split方法, merge方法 */

int main(){
	Mat srcImage = imread("color.jpg");

	//*通道的分离
	Mat channels[3];
	split(srcImage,channels);						//色光三原色（加法三元色）,混合后趋于白色
	imshow("红色通道",channels[2]);					//红+绿 → 黄
	imshow("绿色通道",channels[1]);					//绿+蓝 → 青
	imshow("蓝色通道",channels[0]);					//蓝+红 → 品红
	//*/

	//*往蓝色通道里加个logo
	Mat logo = imread("logo.jpg");
	Mat channelRed = channels[2];
	Mat imageROI = channelRed(Rect(245,245,logo.cols,logo.rows));
	cvtColor(logo,logo,COLOR_BGR2GRAY);				//要将logo也转换为单通道
	addWeighted(imageROI,1.0,logo,1.0,0,imageROI);	//通道数一致才可以矩阵加权和！
	//*/


	//*通道的合并
	Mat mergeImage;
	merge(channels,3,mergeImage);
	imshow("合并通道",mergeImage);
	//*/

	waitKey(0);
	return 0;
}
 
 
