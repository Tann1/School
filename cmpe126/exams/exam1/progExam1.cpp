#include <fstream>
#include <sstream>
#include "Line.h"



int main() {
	char dummy; //parsing reasons catches the ' ' between two points
	int input_size, i = 0; //i iterates through lines variable
	std::string input, second_half;
	Point inputs[2];
	Line greatest; //magnitude
	Line* lines;
	std::stringstream ss;
	std::ifstream inputFile("lines.txt");
	const Point* pts; //get points from a given line

	if (inputFile.is_open()) {
		std::getline(inputFile, input);
		ss << input;
		ss >> input_size;
		lines = new Line[input_size];
		ss.str("");
		while (std::getline(inputFile, input)) {
			ss << input;
			ss >> inputs[0]  >> dummy >> second_half;
			ss.str(second_half);
			ss >> inputs[1];	
			lines[i++].set_points(inputs[0], inputs[1]);
			ss.str("");
		}
	}
	else
		std::cout << "input file did not open" << std::endl;
	std::cout << "testing functionality of comparision operators" << std::endl;
	
	if (lines[0] > lines[1])
		std::cout << "lines[0] is greater than lines[1]" << std::endl;
	else if (lines[0] < lines[1])
		std::cout << "lines[0] is less than lines[1]" << std::endl;
	if (lines[2] <= lines[3])
		std::cout << "lines[2] is less than or equal to lines[3]" << std::endl;
	else if (lines[2] >= lines[3])
		std::cout << "lines[3] is greater than or equal to lines[3]" << std::endl; 
	

	greatest = lines[0]; //assume first one to be greatest
	for (int i = 0; i < input_size; ++i) {
		if (lines[i].magnitude() == 0) { //if a given lines doesn't form a line aka duplicate points
			pts = lines[i].get_points();
			std::cout << "invalid input, pts: " << pts[0] << " and " << pts[1] << " do not make a line" << std::endl;
			return 0; 
		}
		if (lines[i] >= greatest) //update greatest
			greatest = lines[i];	
	} //by the end of the loop we have greatest line
		
	pts = greatest.get_points();
	greatest.magnitude();
	std::cout << "pts: " << pts[0] << " and " << pts[1] << " make the longest line with a magnitude of " << greatest.magnitude() << std::endl;

	

	delete [] lines;
	return 0;
}
