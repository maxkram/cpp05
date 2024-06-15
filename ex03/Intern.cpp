#include "Intern.hpp"

Intern::Intern () {}

Intern::Intern (const Intern& original) {
    (void)original;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern& original) {
    (void)original;
    return (*this);
}

AForm *Intern::makeShrubberyCreation(const std::string& target) {
    std::cout << "Intern makes shrubbery creation form." << "\n";
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequest(const std::string& target) {
    std::cout << "Intern makes robotomy request form." << "\n";
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardon(const std::string& target) {
    std::cout << "Intern makes presidential pardon form." << "\n";
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string& name, const std::string& target) {
    const std::string forms[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm *(Intern::*conswhattors[3])(const std::string&) = {
        &Intern::makeShrubberyCreation,
        &Intern::makeRobotomyRequest,
        &Intern::makePresidentialPardon
    };

    for (int i = 0; i < 4; i++) {
        if (forms[i] == name)
            return ((this->*conswhattors[i])(target));
    }
    std::cout << "No Form for Intern" << "\n";
    throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
    return ("Intern exception: No Form was found.");
}