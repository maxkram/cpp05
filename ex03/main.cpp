#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main(void) {
	std::srand(std::time(NULL));
    
    Intern someRandomIntern;
    
    AForm* form1;
    
    try {
        form1 = someRandomIntern.makeForm("shrubbery creation", "Anna");
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    std::cout << *form1 << "\n";

    std::cout << "\n";

    AForm* form2;
    
    try {
        form2 = someRandomIntern.makeForm("robotomy request", "Jane");
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    std::cout << *form2 << "\n";

    std::cout << "\n";
    
    AForm* form3;
    
    try {
        form3 = someRandomIntern.makeForm("presidential pardon", "Megan");
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    std::cout << *form3 << "\n";
}