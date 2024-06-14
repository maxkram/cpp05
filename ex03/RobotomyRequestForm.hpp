#pragma once

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& original);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(const RobotomyRequestForm& original);

        virtual void specificExecute(void) const;
};