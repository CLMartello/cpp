
#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	: _name(name)
{
	if (_grade < 1)
		throw GradeTooHighException;
	else if (_grade > 150)
		throw GradeTooLowException;
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
	this->_name = copy._name;
	this->_grade = copy._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	if (this != &copy) {
		this->_name = copy._name;
		this->_grade = copy._grade;
	}
	return (*this);
}

const 	std::string Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

void 	Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw GradeTooHighException;
	--_grade;
} 

void 	Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw GradeTooLowException;
	++_grade;
}

const char * Bureaucrat::GradeTooHighException::what() const noexcept {
	return "This grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept {
	return "This grade is too low!";
}

void	operator<<(Bureaucrat object) {
	std::cout << object.getName() << ", beraucrat grade "
		  << object.getGrade() << std::endl; 
}

