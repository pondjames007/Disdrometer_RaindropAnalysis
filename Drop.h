#pragma once
#include <vector>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

class Drop
{
public:
	Drop(void){
		Drop::have_drop = false;
	};
	~Drop(void){};

	int getXPos(){
		return Drop::xPos;	
	};
	int getYPos(){
		return Drop::yPos;
	};
	Point2i getPos(){
		return Drop::pos;
	};
	double getArea(){
		return Drop::area;
	};
	double getPeri(){
		return Drop::peri;	
	};
	Rect getRect(){
		return Drop::objBoundingRect;	
	};
	vector<Point> getContour(){
		return Drop::contour;	
	};
	
	void setPara(Point2i pos, int x, int y, double area, double perimeter, vector<Point> contour, Rect objBoundingRect){
		Drop::xPos = x;
		Drop::yPos = y;
		Drop::area = area;
		Drop::peri = perimeter;
		Drop::contour = contour;
		Drop::pos = pos;
		Drop::objBoundingRect = objBoundingRect;
		
	};
	bool have_drop;
	//void haveDrop();
	//bool checkDrop();
private:
	int xPos, yPos;
	Point2i pos;
	double area, peri;
	vector< Point > contour;
	Rect objBoundingRect;
	
};

