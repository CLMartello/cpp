
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(): _name("Default"), _grade(1) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
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

const 	std::string Bureaucrat::getName() const {
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
	out << object.getName() << ", beraucrat grade "
		<< object.getGrade() << std::endl;
	return (out);
}

void Bureaucrat::signForm(AForm &object) {
	try
	{
		object.beSigned(*this);
		std::cout << this->getName() << " signed "
		          << object.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << this->getName() << " couldn’t sign "
		          << object.getName() << " because "
				  << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed "
			      << form.getName() << " successfully!" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << this->getName() << " couldn’t execute "
		          << form.getName() << " because "
				  << e.what() << std::endl;		
	}
}