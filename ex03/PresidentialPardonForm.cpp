#include "PresidentialPardonForm.hpp"

// Required grades: sign 25, exec 5

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& original) : AForm(original), _target(original._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& original) {
	if (this != &original)
		this->_target = original._target;
	return (*this);
}

void PresidentialPardonForm::specificExecute(void) const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}