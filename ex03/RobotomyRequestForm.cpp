#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& original) : AForm(original), _target(original._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& original) {
	if (this != &original)
		this->_target = original._target;
	return (*this);
}

void RobotomyRequestForm::specificExecute(void) const {
	int randNum = std::rand();

	std::cout << "*DRILLING NOISES*" << "\n";
	if (randNum % 2 == 0) {
		std::cout << this->_target << " has been robotomized!" << "\n";
	}
	else
	{
		std::cout << "Robotomy of " << this->_target << " failed!" << "\n";
	}
}