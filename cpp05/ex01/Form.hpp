
#ifndef FORM_HPP

#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form {
private:
    const std::string _name;
    bool _signal;
    const int _gradeToSign;
    const int _gradeToExecute;
public:
	Form();
	Form(const std::string name, const int gradeToSign, const int gradeToExecute);
	Form(const Form &copy);
	Form &operator=(const Form &copy);
	~Form();

	const std::string getName() const;
	int getSignal() const;
    int getGradeSign() const;
    int getGradeExecute() const;
    void beSigned(const Bureaucrat &bureaucrat);

	class   GradeTooHighException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class   GradeTooLowException: public std::exception
	{	
	public:
	    virtual const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream &out, Form &object);

#endif