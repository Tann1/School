#ifndef LENGTH_H
#define LENGTH_H

#include <iostream>

class Length {

	public:
		Length();
		Length(int);
		Length(int, int);
	
		//setters
		void set_feet(int);
		void set_inches(int);
		
		//getters
		double get_feet();
		double get_inches();

		//overload
		friend std::ostream& operator<< (std::ostream&, const Length&);
		Length operator+(const Length&);
		Length operator+(int);
		void operator=(const Length&);
		
	private:
		int feet, inches;

};



#endif
