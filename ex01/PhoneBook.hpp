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
		void add_contact(void){
			std::string fn;
			std::string ln;
			std::string nick;
			std::string sec;
			std::string num;
			if (num_contacts_ < 8){
				std::cout << "\x1B[2J\x1B[H";
				std::cout << "Insert first name > ";
				getline(std::cin, fn);
				std::cout << "Insert last name > ";
				getline(std::cin, ln);
				std::cout << "Insert nickname > ";
				getline(std::cin, nick);
				std::cout << "Insert darkest secret > ";
				getline(std::cin, sec);
				std::cout << "Insert phone number > ";
				getline(std::cin, num);
				if (fn == "" || ln == "" || nick == "" || sec == "" | num == "")
					std::cout << "\x1B[2J\x1B[H" << "No field can be empty!\n";
				else{
					contacts_[num_contacts_] = Contact (fn, ln, nick, sec, num, (num_contacts_ + 1));
					num_contacts_ ++;
				}
			}
			else
				std::cout << "tas pasao fiera\n";
		}
		void full_printer(void){
			std::string str_num;
			std::cout << "\x1B[2J\x1B[H";
			std::cout << "Index     |First name|Last name |Nickname  " << std::endl;
			std::cout << "----------|----------|----------|----------" << std::endl;
			for (int i = 0; i < num_contacts_; i++) {
				contacts_[i].contact_printer_tab();
			}
			std::cout << "\n Insert index > ";
			getline(std::cin, str_num);
			int num = std::stoi(str_num) - 1;
			contacts_[num].contact_printer_line();
		}
};

#endif