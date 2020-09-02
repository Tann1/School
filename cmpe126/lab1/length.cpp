#include "length.h"


Length::Length()
{
	this->feet = 0;
	this->inches = 0;
}

Length::Length(int feet)
{
	this->feet = feet;
	this->inches = 0;
}

Length::Length(int feet, int inches)
{
	this->feet = feet;
	set_inches(inches);
}

void Length::set_feet(int feet)
{
	this->feet = feet;
}

void Length::set_inches(int inches)
{
	while(inches/12 != 0) //make sure it's from 0 to 11 
	{
		std::cout << "invalid input, please enter a number between 0 and 11 inches: ";
		std::cin >> inches;
	}
	this->inches = inches;
}

double Length::get_feet()
{
	return this->feet;
}

double Length::get_inches()
{
	return this->inches;
}

Length Length::operator+(const Length& len)
{
	Length temp(this->feet, this->inches); //temp so I don't modify the actual object calling it
	
	temp.feet += len.feet + (temp.inches + len.inches) / 12;
	temp.inches = (temp.inches + len.inches) % 12;
	return temp;
}

Length Length::operator+(int inches)
{
	Length temp(this->feet, this->inches);
	
	temp.feet += (temp.inches + inches) / 12;
	temp.inches = (temp.inches + inches) % 12;
	return temp;
}

void Length::operator=(const Length& len)
{
	this->feet = len.feet;
	this->inches = len.inches;
}

std::ostream& operator<<(std::ostream& out, const Length& len)
{
	out << len.feet << "'" << len.inches << "\"";
	return out;
}


	





