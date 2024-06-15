#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
			PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& original);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm& original);

		virtual void specificExecute(void) const;
};