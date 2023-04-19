#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cctype>
#include "Contact.hpp"

class PhoneBook{
	private:
		Contact contacts_[8];
		int num_contacts_;
	public:
		PhoneBook() : num_contacts_(0) {}
		~PhoneBook();
		void add_contact(void);
		bool is_number(const std::string& str);
		void full_printer(void);
};

#endif