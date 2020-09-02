#include "member.h"



Member::Member()
{
	this->weight = 0;
}

Member::Member(int memberID)
{
	this->memberID = memberID;
	this->weight = 0;
}

void Member::set_height(Length height)
{
	this->height = height;
}

void Member::set_height(int feet, int inches)
{
	height.set_feet(feet);
	height.set_inches(inches);
}

void Member::set_weight(double weight)
{
	this->weight = weight;
}

void Member::set_memberID(int memberID)
{
	this->memberID = memberID;
}

std::ostream& operator<<(std::ostream& out, const Member& mem)
{

	out << "member ID: " << mem.memberID << std::endl << "weight: " << mem.weight << std::endl <<
	"height: " << mem.height;
	return out;
}


