#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cctype>
#include "PhoneBook.hpp"

class Contact
{
	private:
		std::string first_name_;
		std::string last_name_;
		std::string nickname_;
		std::string darkest_secret_;
		std::string phone_number_;
		int			index_;
	public:
		Contact(std::string first_name, std::string last_name, std::string nickname,
				std::string drk_secret, std::string phone_number, int index)
				: first_name_(first_name), last_name_(last_name), nickname_(nickname),
				darkest_secret_(drk_secret), phone_number_(phone_number), index_(index) {}
		Contact(){};
		void contact_printer_tab(void){
			std::cout.width(10);
			std::cout << std::right << index_;
			std::cout.width(11);
			std::cout << std::right << first_name_;
			std::cout.width(11);
			std::cout << std::right << last_name_;
			std::cout.width(11);
			std::cout << std::right << nickname_;
			std::cout << "\n";
		}
		void contact_printer_line(void){
			std::cout << "FIRST NAME:        " << first_name_ << "\n";
			std::cout << "LAST NAME:         " << last_name_ << "\n";
			std::cout << "NICKNAME:          " << nickname_ << "\n";
			std::cout << "DARKEST SECRET:    " << darkest_secret_ << "\n";
			std::cout << "PHONE NUMBER:      " << phone_number_ << "\n";
			std::cout << "\n";
		}
};

#endif