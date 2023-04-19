#include "PhoneBook.hpp"
#include <list>

int main(int ac, char **av)
{
	std::string input_string;
	std::string exit_string("exit");
	std::string add_string("add");
	std::string print_string("search");
	PhoneBook phbook;

	(void)av;
	if (ac > 1){
		std::cout << "Error, too many args\n";
		}
	std::cout << "\x1B[2J\x1B[H" << "Wellcome PhoneBook\n";
	while (1){
		std::cout << "> ";
		getline(std::cin, input_string);
		if (!input_string.compare(exit_string))
			exit(1);
		if (!input_string.compare(add_string))
			phbook.add_contact();
		if (!input_string.compare(print_string))
			phbook.full_printer();
	}
}