#include <opencv2/opencv.hpp>					/* 计时函数 */
using namespace cv;								/* getTickCount方法、getTickFrequency方法*/
using namespace std;

int main(){
	double time = (double) getTickCount();

		//*为了使时间不为零插入了一个小操作
		Mat srcImage = imread("test.jpg");
		cout << format(srcImage,"python") << endl << endl;
		//*/

	time = ((double)getTickCount() - time ) / getTickFrequency();
	cout << "经过了：" << time << "秒";
	getchar();
	return 0;
}
