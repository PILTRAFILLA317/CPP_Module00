#include "Contact.hpp"
#include "PhoneBook.hpp"

void Contact::contact_printer_tab(void){
	std::cout.width(10);
	std::cout << std::right << index_ << "|";
	std::cout.width(10);
	if (first_name_.length() > 10){
		std::string temp = first_name_;
		temp.resize(9);
		temp.replace(9, temp.length() - 9, ".");
		std::cout << std::right << temp << "|";
	}
	else
		std::cout << std::right << first_name_ << "|";
	std::cout.width(10);
	if (last_name_.length() > 10){
		std::string temp = last_name_;
		temp.resize(9);
		temp.replace(9, temp.length() - 9, ".");
		std::cout << std::right << temp << "|";
	}
	else
		std::cout << std::right << last_name_ << "|";
	std::cout.width(10);
	if (nickname_.length() > 10){
		std::string temp = nickname_;
		temp.resize(9);
		temp.replace(9, temp.length() - 9, ".");
		std::cout << std::right << temp;
	}
	else
		std::cout << std::right << nickname_;
	std::cout << "\n";
}

void Contact::contact_printer_line(void){
	std::cout << "FIRST NAME:        " << first_name_ << "\n";
	std::cout << "LAST NAME:         " << last_name_ << "\n";
	std::cout << "NICKNAME:          " << nickname_ << "\n";
	std::cout << "DARKEST SECRET:    " << darkest_secret_ << "\n";
	std::cout << "PHONE NUMBER:      " << phone_number_ << "\n";
	std::cout << "\n";
}

void Contact::index_updater(void){
	index_ = index_ - 1;
}