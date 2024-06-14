#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _reqToSign;
        const int _reqToExec;

    public:
        Form();
        Form(std::string name, int reqToSign, int reqToExec);
        Form(const Form& original);
        ~Form();
        Form &operator=(const Form &original);

        std::string getName();
        bool getSigned();
        int getReqToSign();
        int getReqToExec();

        void beSigned(Bureaucrat& bur);

        class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Form& src);