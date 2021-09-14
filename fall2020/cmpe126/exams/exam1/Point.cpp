#include "Point.h"


void Point::set_x(const double& x) {
	this->x = x;
}

void Point::set_y(const double& y) {
	this->y = y;
}

double Point::get_x() const {
	return this->x;
}

double Point::get_y() const {
	return this->y;
}


std::ostream& operator<< (std::ostream& out, const Point& other) {
	return out << "(" << other.x << ", " << other.y << ")";
}

std::istream& operator>> (std::istream& in, Point& other) {
	char dummy[3]; //2 dummy characters ( , ) from the format of (x, y)
	return in >> dummy[0] >> other.x >> dummy[1] >> other.y >> dummy[2];
}
