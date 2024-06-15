#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat test;
    Bureaucrat Trudeau("Trudeau", 150);
    Bureaucrat Legault(Trudeau);
    Bureaucrat Marchand("Marchand", 100);

    std::cout << test << "\n";
    std::cout << Trudeau << "\n";
    std::cout << Legault << "\n";
    std::cout << Marchand << "\n";
    std::cout << "\n";
    
    test = Marchand;

    std::cout << test << "\n";

    Marchand.incrementGrade();

    std::cout << test << "\n";
    std::cout << Marchand << "\n";

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "test exceptions" << "\n";
    std::cout << "\n";
    std::cout << "\n";

    try {
        Bureaucrat Wrong("wrong", 300);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }

	std::cout << Trudeau << "\n";

	try {
		Trudeau.decrementGrade();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }

	std::cout << "\n";
	std::cout << "\n";

	try {
        Bureaucrat BigMistake("BigMistake", 0);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }


	Marchand.setGrade(1);
	std::cout << Marchand << "\n";

	try {
        Marchand.incrementGrade();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }
	
	std::cout << "\n\n";
	std::cout << "increment test" << "\n";
	std::cout << "\n\n";

	Bureaucrat b1("1ne", 1);
	Bureaucrat b2("2wo", 150);
	Bureaucrat b3("3hre", 5);
	Bureaucrat b4("4our", 125);

	std::cout << b1 << "\n";
	std::cout << b2 << "\n";
	std::cout << b3 << "\n";
	std::cout << b4 << "\n";
	std::cout << "\n";
	b1.decrementGrade();
	b2.incrementGrade();
	b3.incrementGrade();
	b4.decrementGrade();
	std::cout << "\n";
	std::cout << b1 << "\n";
	std::cout << b2 << "\n";
	std::cout << b3 << "\n";
	std::cout << b4 << "\n";
}