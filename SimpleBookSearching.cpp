#include <iostream>
#include <vector>
#include <string>

void SetOfBooks(std::vector<std::string>&Books, const std::string &Search);

int main(){
	std::vector<std::string>Books = {"The Great Gatsby", "Pride and Prejudice", "One Hundred Years of Solitude","Ulysses", "To Kill a Mockingbird: A Graphic Model"};
	std::string Search;
	
	std::cout << "Searched for: ";
	std::getline(std::cin, Search);
	
	SetOfBooks(Books, Search);
}

void SetOfBooks(std::vector<std::string>&Books, const std::string &Search){
	bool found = false;
	for (const auto &Searching : Books) {
		if (Searching.find(Search) != std::string::npos) {
			if (!found) {
				std::cout << "Available books:\n"; 
				found = true;
			}
			std::cout << "* " <<  Searching << std::endl; 
		}
	}
	
	if (!found) {
		std::cout << "No books found matching your search!";
	}
}
