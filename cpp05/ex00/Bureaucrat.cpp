
#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(): _name("Default"), _grade(1) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
		//throw means stop execution and send this error to the catch block
		//throw raises an error and leave the current flow
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
	: _name(copy._name), _grade(copy._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	if (this != &copy)
	{
		this->_grade = copy._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const 	std::string &Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

void 	Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	--_grade;
} 

void 	Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	++_grade;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "This grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "This grade is too low!";
}

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &object)
{
	//to << works, it has to have std::cout << object (both arguments)
	//the function is call like std::cout (out argument) << a (object argument)
	out << object.getName() << ", beraucrat grade "
		<< object.getGrade() << std::endl;
	return (out);
}
//this functions teaches how to print your object

