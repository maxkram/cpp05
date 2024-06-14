#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& original);
        Intern&    operator=(const Intern& original);
        ~Intern();
        
        AForm *makeForm(const std::string& name, const std::string& target);

        AForm *makeShrubberyCreation(const std::string& target);
        AForm *makeRobotomyRequest(const std::string& target);
        AForm *makePresidentialPardon(const std::string& target);

        class FormNotFoundException : public std::exception {
            virtual const char *what() const throw();
        };
};