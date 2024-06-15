#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Form form;
	Form f1("f1", 50, 25);
	Form f2("f2", 100, 100);
	Form copy(f1);

	std::cout << form << "\n";
	std::cout << f1 << "\n";
	std::cout << f2 << "\n";
	std::cout << copy << "\n";
	std::cout << "\n";

	std::cout << form << "\n";
	form = f1;
	std::cout << "\n";
	std::cout << form << "\n";
	std::cout << f1 << "\n";

	std::cout << "\n";
	std::cout << "\n";
	std::cout << "Testing exceptions" << "\n";
	std::cout << "\n";
	std::cout << "\n";

	try {
        Form BigMistake1("BigMistake1", 200, 25);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }

	try {
        Form BigMistake2("BigMistake2", 42, -15);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }

	try {
        Form BigMistake3("BigMistake3", -3, 243);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }

	std::cout << "\n";
	std::cout << "\n";

	Bureaucrat bur1("bur1", 150);
	Bureaucrat bur2("bur2", 1);
	Bureaucrat bur3("bur3", 42);

	Form f3("f3", 100, 100);
	Form f32(f3);
	Form f33(f3);
	Form f4("f4", 42, 50);
	Form f42(f4);
	Form f43(f4);

	try {
		f3.beSigned(bur2);
		f32.beSigned(bur3);
		f33.beSigned(bur1);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";
	
	try {
		f4.beSigned(bur2);
		f42.beSigned(bur3);
		f43.beSigned(bur1);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";
	std::cout << "\n";

	Form f5("f5", 100, 100);
	Form f52(f5);
	Form f53(f5);

	try {
		bur2.signForm(f5);
		std::cout << f5 << "\n";
		bur3.signForm(f52);
		std::cout << f52 << "\n";
		bur1.signForm(f53);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";

	Form f6("f6", 100, 100);
	Form f44(f6);
	Form f45(f6);

	try {
		bur2.signForm(f6);
		std::cout << f6 << "\n";
		bur3.signForm(f44);
		std::cout << f44 << "\n";
		bur1.signForm(f45);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

}