#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cctype>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts_[8];
		int num_contacts_;
	public:
		PhoneBook();
		~PhoneBook();
		void add_contact(void);
		void full_printer(void);
};

#endif