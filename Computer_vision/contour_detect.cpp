//#include "opencv2\opencv.hpp"
//#include <stdint.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream> 

using namespace cv;
using namespace std;

Mat imgGray, imgBlur, imgCanny, imgDil;
void getContours(Mat imgDil, Mat img) {
	
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

	vector<vector<Point>> contPoly(contours.size());
	vector<Rect> boundRect(contours.size());
	string objType;

	for (int i = 0; i < contours.size(); i++)//loop through contours size, to find area, doing this you can idetify noise and eliminate
	{
		int area = contourArea(contours[i]);
		cout << area << endl;
		if (area > 1000)
		{
			float para = arcLength(contours[i], true);
			approxPolyDP(contours[i], contPoly[i], 0.02 * para, true);
			
			cout << contPoly[i].size() << endl;
			boundRect[i] = boundingRect(contPoly[i]);
			
			int objCor = (int)contPoly[i].size();
			if (objCor == 3) { objType = "triangle"; }
			else if (objCor == 4) {

				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				cout << aspRatio << endl;
				if (aspRatio > 0.9 && aspRatio < 1.1) { objType = "square"; }
				else {
					objType = "rectangle";
				}
			}
			
			else if (objCor == 5) { objType = "pentagon"; }
			else if (objCor == 6) { objType = "hexagon"; }
			else if (objCor > 6) { objType = "circle"; }

			drawContours(img, contPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			putText(img, objType, { boundRect[i].x,boundRect[i].y - 5}, FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 0), 1.5);
		}
	}
}

void main()
{
	Mat img;
	Mat image = imread("Resources/shapes4.png");
	resize(image, img, Size(), 2, 2);
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(5, 5), 5, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	getContours(imgDil, img);

	imshow("Image", img);
	//imshow("ImageGray", imgGray);
	//imshow("ImageBlur", imgBlur);
	//imshow("ImageCanny", imgCanny);
	//imshow("ImageDil", imgDil);
	waitKey(0);
}