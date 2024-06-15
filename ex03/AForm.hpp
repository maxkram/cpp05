#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const int _reqToSign;
        const int _reqToExec;

    public:
        AForm();
        AForm(std::string name, int reqToSign, int reqToExec);
        AForm(const AForm& original);
        ~AForm();
        AForm &operator=(const AForm &original);

        std::string getName() const;
        bool getSigned() const;
        int getRequestToSign() const;
        int getRequestToExec() const;

        void beSigned(Bureaucrat& bur);

        void execute(const Bureaucrat& executor) const;

        virtual void specificExecute(void) const = 0;

        class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

        class FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

        class BureaucratGradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

};

std::ostream& operator<<(std::ostream& os, AForm& src);