#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
    this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& original) : _name(original._name), _grade(original._grade) {}   

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& original) {
	if (this != &original)
		this->setGrade(original._grade);
	return (*this);
}

const std::string Bureaucrat::getName() {
	return (this->_name);
}

int Bureaucrat::getGrade() {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	this->_grade -= 1;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	this->_grade += 1;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::setGrade(int grade) {
	this->_grade = grade;
	if (this->_grade < 1)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::signForm(Form& form) {
	if (form.getSigned())
		std::cout << this->getName() << " signed " << form.getName() << "." << "\n";
	else {
		if (this->_grade <= form.getRequestToSign())
			form.beSigned(*this);
		else {
			std::cout << this->getName() << " no sign " << form.getName() << " not enough grade." << "\n";
			throw Form::GradeTooLowException();
		}
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat exception: too much of the grade.\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat exception: the grade is below the level.\n");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& src) {
	os << src.getName()	<< ", bureaucrat grade " << src.getGrade() << "." << "\n";
	return (os);
}