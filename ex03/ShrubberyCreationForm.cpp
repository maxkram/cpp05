#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& original) : AForm(original), _target(original._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& original) {
	if (this != &original)
		this->_target = original._target;
	return (*this);
}

void ShrubberyCreationForm::specificExecute(void) const {
	std::ofstream outfile;
	outfile.open((this->_target + "_shrubbery").c_str());

	if (outfile.is_open()) {
		outfile << "     /\\      " << "\n";
		outfile << "    /  \\     " << "\n";
		outfile << "   /    \\    " << "\n";
		outfile << "  /______\\   " << "\n";
		outfile << "     ||      " << "\n";
		outfile << "     ||      " << "\n";
		outfile.close();
	}
}
