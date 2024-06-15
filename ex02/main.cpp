#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>


int main(void)
{
	std::srand(std::time(NULL));

	std::cout << "======(ShrubberyCreationForm)======" << "\n";
	std::cout << "Required grades: sign 145, exec 137" << "\n";
	std::cout << "\n";
	std::cout << "\n";

	Bureaucrat bur11("bur11", 1);
	Bureaucrat bur12("bur12", 140);
	Bureaucrat bur13("bur13", 150);

	ShrubberyCreationForm a("form");
	ShrubberyCreationForm a2("test2");

	try {
		std::cout << a << "\n";
		a.execute(bur11);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";

	try {
		std::cout << bur13 << "\n";
		std::cout << a << "\n";
		a.beSigned(bur13);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";

	try {
		std::cout << bur12 << "\n";
		std::cout << a << "\n";
		a.beSigned(bur12);
		bur12.executeForm(a);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";

	try {
		std::cout << bur11 << "\n";
		a.execute(bur11);
		a2.beSigned(bur11);
		bur11.executeForm(a2);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";
	std::cout << "\n";
	std::cout << "RobotomyRequestForm" << "\n";
	std::cout << "Grades must bt: sign 72, exec 45" << "\n";
	std::cout << "\n";
	std::cout << "\n";

	Bureaucrat bur21("bur21", 1);
	Bureaucrat bur22("bur22", 70);
	Bureaucrat bur23("bur23", 100);

	RobotomyRequestForm b("Cori");
	RobotomyRequestForm b2("Thoma");

	try {
		std::cout << b << "\n";
		b.execute(bur21);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";

	try {
		std::cout << bur23 << "\n";
		std::cout << b << "\n";
		b.beSigned(bur23);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";

	try {
		std::cout << bur22 << "\n";
		std::cout << b << "\n";
		b.beSigned(bur22);
		bur22.executeForm(b);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";

	try {
		std::cout << bur21 << "\n";
		b.execute(bur21);
		b2.beSigned(bur21);
		bur21.executeForm(b2);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";
	std::cout << "\n";
	std::cout << "PresidentialPardonForm" << "\n";
	std::cout << "The grades must be: sign 25, exec 5" << "\n";
	std::cout << "\n";
	std::cout << "\n";

	Bureaucrat bur31("bur31", 1);
	Bureaucrat bur32("bur32", 20);
	Bureaucrat bur33("bur33", 30);

	PresidentialPardonForm c("Bob");
	PresidentialPardonForm c2("Mike");

	try {
		std::cout << c << "\n";
		c.execute(bur31);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";

	try {
		std::cout << bur33 << "\n";
		std::cout << c << "\n";
		c.beSigned(bur33);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";

	try {
		std::cout << bur32 << "\n";
		std::cout << c << "\n";
		c.beSigned(bur32);
		bur32.executeForm(c);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";

	try {
		std::cout << bur31 << "\n";
		c.execute(bur31);
		c2.beSigned(bur31);
		bur31.executeForm(c2);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
}