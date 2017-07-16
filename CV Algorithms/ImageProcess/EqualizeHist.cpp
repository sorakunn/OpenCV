#include <opencv2/opencv.hpp>					/*直方图均衡化*/
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

void MyEqualize(Mat& src, Mat& dst){

	//统计各亮度像素个数
	int ct[256]={0};
	uchar* pS = src.data;
	for(int i=0; i<src.rows*src.cols; i++)
		ct[*pS++]++;

	//生成概率密度函数
	float f[256]={0};
	for(int i=0; i<256; i++){
		f[i] = (float) ct[i] / (src.rows*src.cols);	
	}

	//生成累计分布函数
	for(int i=1; i<256; i++){
		f[i] += f[i-1];	
	}

	//生成查找表
	Mat table = Mat(1,256,CV_8U);
	uchar* pL = table.data;
	for(int i=0; i<256; i++){
		pL[i] = (int) (256*f[i]);	//拉伸、取整
	}
	LUT(src,table,dst);

}

int main(){
	Mat srcImage = imread("test2.jpg");
	cvtColor(srcImage,srcImage,COLOR_BGR2GRAY);
	Mat dstImage = srcImage.clone();

	//*直方图均衡化
	//equalizeHist(srcImage,dstImage);		//OpenCV库函数
	MyEqualize(srcImage,dstImage);
	//*/

	imshow("原图",srcImage);
	imshow("效果图",dstImage);
	waitKey(0);
	return 0;
}

/*
	 彩色图片：直方图均衡化一般不能直接对R、G、B三个分量分别进行上述的操作，
			   而是将RGB转换成HSV来对V分量进行直方图均衡化的操作
*/
