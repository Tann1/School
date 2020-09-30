#ifndef LINE_H
#define LINE_H

#include <cmath> //for pow() and sqrt()
#include "Point.h"


class Line {
	
	public:
		Line() {}
		Line(Point, Point);
		void set_points(Point, Point);
		const Point* get_points() const;
		double magnitude() const;


		bool operator> (const Line&);
		bool operator< (const Line&);
		bool operator>= (const Line&);
		bool operator<= (const Line&);

	private:
		Point pts[2];
};


#endif
