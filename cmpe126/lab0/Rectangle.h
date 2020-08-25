#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle {
	
	public:
		//Constructors
		Rectangle();
		Rectangle(double len, double wid);
		
		//getters
		double get_len();
		double get_wid();
		
		//setters
		void set_len(double len);
		void set_wid(double wid);

		//member functions (methods)
		double get_area();
		void print_area();
	private:
		double len, wid;
};
#endif
