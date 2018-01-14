


Drop::Drop(void)
{
	Drop::have_drop = false;
}


Drop::~Drop(void)
{
}

int Drop::getXPos(){
	return Drop::xPos;
}

int Drop::getYPos(){
	return Drop::yPos;
}

Point Drop::getPos(){
	return Drop::pos;
}

double Drop::getArea(){
	return Drop::area;
}

double Drop::getPeri(){
	return Drop::peri;
}

vector<Point> Drop::getContour(){
	return Drop::contour;
}

Rect Drop::getRect(){
	return Drop::objBoundingRect;
}

void Drop::setPara(Point pos, int x, int y, double area, double perimeter, vector<Point> contour, Rect objBoundingRect){
	Drop::xPos = x;
	Drop::yPos = y;
	Drop::area = area;
	Drop::peri = perimeter;
	Drop::contour = contour;
	Drop::pos = pos;
	Drop::objBoundingRect = objBoundingRect;
}

