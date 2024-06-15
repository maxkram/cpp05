#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _reqToSign(150), _reqToExec(150) {}

Form::Form(std::string name, int reqToSign, int reqToExec) : _name(name), _isSigned(false), _reqToSign(reqToSign), _reqToExec(reqToExec){
    if (this->_reqToSign > 150 || this->_reqToExec > 150)
        throw Form::GradeTooLowException();
    if (this->_reqToSign < 1 || this->_reqToExec < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form& original) : 
_name(original._name), _isSigned(original._isSigned), _reqToSign(original._reqToSign), _reqToExec(original._reqToExec) {}


Form::~Form() {}

Form &Form::operator=(const Form &original) {
    if (this != &original)
        this->_isSigned = original._isSigned;
    return (*this);
}

std::string Form::getName() {
    return (this->_name);
}

bool Form::getSigned() {
    return (this->_isSigned);
}

int Form::getRequestToSign() {
    return(this->_reqToSign);
}

int Form::getRequestToExec() {
    return (this->_reqToExec);
}

void Form::beSigned(Bureaucrat& bur) {
    if (this->_isSigned) {
        std::cout << "Already signed!" << "\n";
        return;
    }
    if (bur.getGrade() <= this->getRequestToSign()) {
        this->_isSigned = true;
        bur.signForm(*this);
    }
    else {
        bur.signForm(*this);
        throw Form::GradeTooLowException();
    }
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Form exception: too much of grad.\n");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Form exception: not enought of grade.\n");
}

std::ostream& operator<<(std::ostream& os, Form& src) {
    os << "Form " << src.getName() << ", needs the grade " << src.getRequestToSign() << " to be signed and the grade " << src.getRequestToExec() << " to be executed. ";
    if (src.getSigned())
        os << "The form is signed." << "\n";
    else
        os << "The NOT signed form." << "\n";
    return (os);
}