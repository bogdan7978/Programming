#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img;
vector<vector<int>> newPoints;

vector<vector<int>> myColors { {155,173,0,179,255,255},
								{23,50,121,45,199,255} }; //add more colors here

vector<Scalar> myColorValues { {0,0,255},
								{0, 255, 0 } }; // output color red

Point getContours(Mat imgDil) 
{

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

	vector<vector<Point>> contPoly(contours.size());
	vector<Rect> boundRect(contours.size());

	Point myPoint(0, 0);

	for (int i = 0; i < contours.size(); i++) //loop through contours size, to find area, doing this you can idetify noise and eliminate
	{
		int area = contourArea(contours[i]);
		cout << area << endl;

		string objType;

		if (area > 1000)
		{
			float para = arcLength(contours[i], true);
			approxPolyDP(contours[i], contPoly[i], 0.02 * para, true);

			cout << contPoly[i].size() << endl;
			boundRect[i] = boundingRect(contPoly[i]);

			drawContours(img, contPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			myPoint.x = boundRect[i].x + boundRect[i].width / 2;
			myPoint.y = boundRect[i].y;
		}
	}
	return myPoint;
}


vector<vector<int>> findColor(Mat img)
{	
	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	for (int i = 0; i < myColors.size(); i++) 
	{
		Scalar lower(myColors[i][0], myColors[i][1], myColors[i][2]);
		Scalar upper(myColors[i][3], myColors[i][4], myColors[i][5]);
		Mat mask;
		inRange(imgHSV, lower, upper, mask);
		//imshow(to_string(i), mask);
		Point myPoint = getContours(mask);
		if (myPoint.x != 0 && myPoint.y != 0) {
			newPoints.push_back({ myPoint.x, myPoint.y, i });
		}
	}
	return newPoints;
}

void drawOnCanvas(vector<vector<int>> newPoints, vector<Scalar> myColorValues) 
{
	for (int i = 0; i < newPoints.size(); i++) 
	{
		circle (img, Point(newPoints[i][0], newPoints[i][1]), 10, myColorValues[newPoints[i][2]], FILLED);
	}
}

void main() 
{
	//string path = "Res/test.mp4";
	VideoCapture cap(0);

	while (true) {
		cap.read(img);
		newPoints = findColor(img);
		drawOnCanvas(newPoints, myColorValues);
		imshow("Video", img);
		waitKey(1);
	}
}