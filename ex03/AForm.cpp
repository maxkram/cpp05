#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _reqToSign(150), _reqToExec(150) {}

AForm::AForm(std::string name, int reqToSign, int reqToExec) : _name(name), _isSigned(false), _reqToSign(reqToSign), _reqToExec(reqToExec){
	if (this->_reqToSign > 150 || this->_reqToExec > 150)
		throw AForm::GradeTooLowException();
	if (this->_reqToSign < 1 || this->_reqToExec < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& original) : 
_name(original._name), _isSigned(original._isSigned), _reqToSign(original._reqToSign), _reqToExec(original._reqToExec) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &original) {
	if (this != &original)
		this->_isSigned = original._isSigned;
	return (*this);
}

std::string AForm::getName() const {
	return (this->_name);
}

bool AForm::getSigned() const {
	return (this->_isSigned);
}

int AForm::getRequestToSign() const {
	return(this->_reqToSign);
}

int AForm::getRequestToExec() const {
	return (this->_reqToExec);
}

void AForm::beSigned(Bureaucrat& bur) {
	if (this->_isSigned) {
		std::cout << "Form is already signed!" << "\n";
		return;
	}
	if (bur.getGrade() <= this->getRequestToSign()) {
		this->_isSigned = true;
		bur.signForm(*this);
	}
	else {
		bur.signForm(*this);
		throw AForm::GradeTooLowException();
	}
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Form exception: grade too high.\n");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Form exception: grade too low.\n");
}

const char *AForm::FormNotSignedException::what() const throw() {
	return ("Form exception: form is not signed.");
}

const char *AForm::BureaucratGradeTooLowException::what() const throw() {
	return ("Form exception: Bureaucrat grade is too low.");
}

void AForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->getRequestToExec())
		throw AForm::BureaucratGradeTooLowException();
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	this->specificExecute();
}

std::ostream& operator<<(std::ostream& os, AForm& src) {
	os << "Form " << src.getName() << ", requires grade " << src.getRequestToSign() << " to be signed and grade " << src.getRequestToExec() << " to be executed. ";
	os << (src.getSigned() ? "Signed." : "NOT signed.") << "\n";
	return (os);
}