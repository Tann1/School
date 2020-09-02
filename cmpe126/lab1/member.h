#ifndef MEMBER_H
#define MEMBER_H

#include "length.h"

class Member {

	public:
		//constructors
		Member();
		Member(int);

		//setters
		void set_height(Length);
		void set_height(int, int);
		void set_weight(double);
		void set_memberID(int);

		//getters
		Length get_height();
		double get_weight();
		int get_memberID();
			
		//overloading
		friend std::ostream& operator<<(std::ostream&, const Member&);
	

	private:
		Length height;
		double weight;
		int memberID;

};

#endif
