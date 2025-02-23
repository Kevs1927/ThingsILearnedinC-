#include <iostream>
#include <string>
#include <vector>

struct StudentInfo{
	std::string name;
	int grade;
	
	StudentInfo(const std::string& n, int s) : name(n), grade(s){}
};

int main()
{
	
	std::vector<StudentInfo> students[3] = {
		{StudentInfo {"Arianna", 90}, StudentInfo {"Kevin", 80}, StudentInfo {"Brian", 75}}
	};
	
	std::cout << "Stack Students: " << '\n';
	for (const auto& student : students[0]) {
		std::cout << student.name << " (" << student.grade << ")" << '\n';
	}
	
	StudentInfo *hstudents = new StudentInfo("", 0);
	do {
		std::cout << "Enter the name: ";
		getline(std::cin, hstudents->name);
	} while(hstudents->name.empty());
	
	std::cout << "Enter grades: ";
	std::cin >> hstudents->grade;
	
	std::cout << hstudents->name << " (" << hstudents->grade << ")"; 
	delete hstudents;
	return 0;
}
