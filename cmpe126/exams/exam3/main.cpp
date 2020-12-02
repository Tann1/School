#include <iostream>
#include <fstream>
using namespace std;

#define MAXSTUDENTS 64


unsigned int read(string filename, int* students){
	ifstream fin(filename);
	unsigned int index = 0;
	while(!fin.eof() && index < MAXSTUDENTS){
		fin >> students[index++];
	}
	return index;
}

void print(int* students, unsigned int num_students)  {
	for (int i = 0; i < num_students; ++i)
		std::cout << i << ": " << students[i] << std::endl;
}


void menu(int* students, unsigned int num_students);
int recurse(int* students, int element, unsigned int low, unsigned int high); //this one is mine
int ternarySearch(int* students, int element, int num_students);
void addStudent(int student, int* students, int num_students);
// void addStudents(int* newstudents, int* students); // Uncomment to implement bonus

int main() {
	int* students = new int[MAXSTUDENTS];
	unsigned int num_students = read("students.txt", students);

	menu(students, num_students);
	delete [] students;
	return 0;
}

int ternarySearch(int* students, int element, int num_students) {
	int low = 0, high = num_students - 1;

	return recurse(students, element, low, high);
}

int recurse(int* students, int element, unsigned int low, unsigned int high) {
	unsigned int mid1 = low + (high - low)/3, mid2 = high - (high-low)/3;
	if (students[mid1] == element)
		return mid1;
	if (students[mid2] == element)
		return mid2;
	if (high == low)
		return -1;
	if (element < students[mid1])
		return recurse(students, element, low, mid1);
	if (element > students[mid1] && element < students[mid2])
		return recurse(students, element, mid1, mid2);
	if (element > students[mid2])
		return recurse(students, element, mid2, high);
}




void addStudent(int student, int* students, unsigned int &num_students) {
	unsigned pos = num_students;
	if (num_students == MAXSTUDENTS) {
		std::cout << "Failed to add student ID: " << student << " list full!" << std::endl;
		return;	
	}
	while (pos > 0 && students[pos - 1] > student) {
		students[pos--] = students[pos - 1];
	} //the shift
	
	students[pos] = student, num_students++;
	std::cout << "Successfully added student ID: " << student << "!" << std::endl;
	
}

void menu(int* students, unsigned int num_students) {
	int choice = 0, stuID;
	do {
		std::cout << "1. Print students' IDs" << std::endl;
		std::cout << "2. Search student by ID" << std::endl;
		std::cout << "3. Add new student by ID" << std::endl;
		std::cout << "4. Quit" << std::endl;

		std::cout << "Your choice: ";
		std::cin >> choice;
		switch (choice) {
			case 1:
				std::cout << "printing students' IDs" << std::endl;
				print(students, num_students);
				std::cout << std::endl;
				break;
			case 2:
				std::cout << "Enter student's ID: ";
				std::cin >> stuID;
				std::cout << "Student at pos: " << ternarySearch(students, stuID, num_students) << std::endl;
				std::cout << std::endl;
				break;
			case 3:
				std::cout << "Enter new student's ID: ";
				std::cin >> stuID;
				addStudent(stuID, students, num_students);
				std::cout << std::endl;
				break;
		}
	} while (choice != 4);
}
