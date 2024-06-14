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
    
    AForm* scf;
    
    try {
        scf = someRandomIntern.makeForm("shrubbery creation", "Richard");
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << *scf << std::endl;

    std::cout << std::endl;

    AForm* rrf;
    
    try {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << *rrf << std::endl;

    std::cout << std::endl;
    
    AForm* ppf;
    
    try {
        ppf = someRandomIntern.makeForm("presidential pardon", "Hector");
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << *ppf << std::endl;
}