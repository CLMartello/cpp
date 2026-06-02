
#ifndef AFORM_HPP

#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool _signal;
    const int _gradeToSign;
    const int _gradeToExecute;
public:
	AForm();
	AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &copy);
	~AForm();

	const std::string &getName() const;
	int getSignal() const;
    int getGradeSign() const;
    int getGradeExecute() const;
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(const Bureaucrat &bureaucrat) const = 0;


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

	class	FormNotSignedException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream &out, AForm &object);

#endif