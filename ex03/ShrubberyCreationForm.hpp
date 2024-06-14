#pragma once

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    private:
		std::string _target;

    public:
        ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& original);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm& original);

		virtual void specificExecute(void) const;
};