#include<opencv2/highgui/highgui.hpp>			/* 图像的载入和显示 */
using namespace cv;					/* imread方法, imwrite方法 */
using namespace std;					/* namedWindow方法, imshow方法 */

int main(){
	Mat srcImage = imread("test.jpg");		//imread( "D://xxx//xxx.jpg", (enum) color_type);
							//！读取文件中的图片到OpenCV中
							//(1)读取路径(当前目录则只需图名)
							//(2)颜色类型
							//	a) 0：灰度
							//	b) 1：彩色	【默认值】
							//	c) 2：深度图像

	namedWindow("图片窗口");			     //namedWindow ("window_name", (enum) is_autosize );
							//！当在显示窗口之前要用到窗口时,就需要此函数
							//(1)窗口名
							//(2)是否自动大小
							//	a) WINDOW_NORMAL	：用户手动拖放窗口大小
							//	b) WINDOW_AUTOSIZE	：自动大小,且不可拖放	【默认值】
							//	c) WINDOW_OPENGL	：窗口创建时能支持OpenGL

	imshow("图片窗口", srcImage);		    //imshow( "window_name", (InputArray) mat_picture);
							//！在指定窗口显示指定图像
							//(1)窗口名
							//(2)图像结构-要显示的(InputArray型的mat)
	try{
		imwrite("Output.jpg",srcImage);		//imwrite("outputImage_name.xxx", (InputArray) mat_picture, param);	[bool]
							//！将图像保存到指定文件
							//(1)保存路径(当前目录则只需文件名)
							//(2)图像结构-要保存的(InputArray型的mat)
							//(3)控制参数	在书p68页有讲解,此处暂时跳过
                                      
		fprintf(stdout,"JPG图片文件已保存至工程所在目录\n");
		waitKey(0);
	}
  
	catch(runtime_error& ex){
		fprintf(stderr,"图像转换成PNG格式发生错误：%s\n",ex.what());
		return 1;
	}

	return 0;
}

/*	使用OpenCV命名空间的两种方法
	1.开头写：using namespace cv;
	2.使用写：cv::imshow();
*/

/*	“Mat”与“IplImage*”
	OpenCV1采用“IplImage*”结构。若在退出前没有将其release,会造成内存泄露,使用较为繁琐
	OpenCV2采用“Mat”类数据结构。用其进行图像存取,容易上手,易于开发
*/
