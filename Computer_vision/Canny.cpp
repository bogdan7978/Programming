#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////// Image ///////////
int main(int argv, char** argc)
{
	Mat image = imread("Resources/vase.jpg", IMREAD_GRAYSCALE);
	Mat imgBlur, imgCanny, imgDil, imgErode;

	GaussianBlur(image, imgBlur, Size(5, 5),0);
	Canny(imgBlur, imgCanny, 20 , 60);
	//Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	//dilate(imgCanny, imgDil, kernel);
	//erode(imgCanny, imgErode, kernel);

	//imshow("Image", image);
	imshow("Blur", imgBlur);
	imshow("Canny", imgCanny);
	//imshow("Dilated", imgDil);
	//imshow("Erode", imgErode);
	waitKey(0);
	return 0;
}