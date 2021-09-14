#ifndef POINT_H
#define POINT_H
#include <iostream>


class Point {

	public:
		void set_x(const double&);
		void set_y(const double&);
		
		double get_x() const;
		double get_y() const;

		friend std::ostream& operator<< (std::ostream&, const Point&);
		friend std::istream& operator>> (std::istream&, Point&);

	private:
		double x, y;


};
#endif
