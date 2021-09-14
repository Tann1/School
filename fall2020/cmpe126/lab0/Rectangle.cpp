#include "Rectangle.h"

Rectangle::Rectangle()
{
	len = 0;
	wid = 0;
}

Rectangle::Rectangle(double len, double wid)
{
	this->len = len;
	this->wid = wid;
}

double Rectangle::get_len() {return this->len;}

double Rectangle::get_wid() {return this->wid;}

void Rectangle::set_len(double len) {this->len = len;}

void Rectangle::set_wid(double wid) {this->wid = wid;}

double Rectangle::get_area() {return len * wid;}

void Rectangle::print_area()
{
	std::cout << "area of the rectangle is " << get_area() << std::endl;
}

