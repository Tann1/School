#include "Line.h"


Line::Line(Point pt1, Point pt2) {
	this->pts[0] = pt1;
	this->pts[1] = pt2;
}

void Line::set_points(Point pt1, Point pt2) {
	this->pts[0] = pt1;
	this->pts[1] = pt2;
}

const Point* Line::get_points() const {
	return pts;
}

double Line::magnitude() const {
	double x_diff = pts[0].get_x() - pts[1].get_x(); //x1 - x2
	double y_diff = pts[0].get_y() - pts[1].get_y(); //y1 - y2

	return sqrt(pow(x_diff,2) + pow(y_diff,2));
}

bool Line::operator>(const Line& other) {
	return this->magnitude() > other.magnitude();
}

bool Line::operator<(const Line& other) {
	return this->magnitude() < other.magnitude();
}

bool Line::operator>=(const Line& other) {
	return this->magnitude() >= other.magnitude();
}

bool Line::operator<=(const Line& other) {
	return this->magnitude() <= other.magnitude();
}

