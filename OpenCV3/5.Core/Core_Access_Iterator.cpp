#include <opencv2/opencv.hpp>								/* 访问图像中像素（方法二） */
using namespace cv;											/* MatIterator_<Vec3b>类型, Mat_<Vec3b>::iterator类型 */
															/* Mat.begin<type>()方法, Mat.end<type>()方法 */

void colorReduce(Mat& srcImage, Mat& dstImage, int div){	
	dstImage = srcImage.clone();
	//cvtColor(dstImage,dstImage,COLOR_BGR2GRAY);
	int channels = dstImage.channels();

	switch(channels){

	case 1:{//单通道情况（迭代器设置为uchar类型）
		MatIterator_<uchar> it;								//第一种定义方式 
		Mat_<uchar>::iterator itend;						//第二种定义方式
		it = dstImage.begin<uchar>();						//begin<>();方法返回指向第一个元素的迭代器
		itend = dstImage.end<uchar>();						//end<>():方法返回指向最后一个元素的迭代器
		for(; it!=itend; it++)
			*it = *it/div*div;
		break;  
		}

	case 3:{//三通道的情况（迭代器设置为Vec3b类型）
		MatIterator_<Vec3b> it;	
		Mat_<Vec3b>::iterator itend;
		it = dstImage.begin<Vec3b>();
		itend = dstImage.end<Vec3b>();
		//*使用迭代器对三个通道分别进行操作
		for(; it!=itend; it++){
			(*it)[0] = (*it)[0]/div*div;
			(*it)[1] = (*it)[1]/div*div;
			(*it)[2] = (*it)[2]/div*div;
		}
		//*/
		break;
		}

	}

}

int main(){
	Mat srcImage = imread("test.jpg");
	Mat dstImage;
	dstImage.create(srcImage.rows,srcImage.cols,srcImage.type());

	double time = (double) getTickCount();
	colorReduce(srcImage, dstImage, 30);
	time = ((double)getTickCount() - time ) / getTickFrequency();

	imshow("原图",srcImage);
	imshow("效果图",dstImage);
	waitKey(0);
	return 0;
} 
