
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("Default"), _signal(false), _gradeToSign(50), _gradeToExecute(100) {}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute)
    : _name(name),
      _signal(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &copy)
    : _name(copy._name),
      _signal(copy._signal),
      _gradeToSign(copy._gradeToSign),
      _gradeToExecute(copy._gradeToExecute) {}

Form &Form::operator=(const Form &copy) {
    if (this != &copy)
    {
        this->_signal = copy._signal;
    }
    return (*this);
}

Form::~Form() {}


const char * Form::GradeTooHighException::what() const throw()
{
    return "This grade is too high!";
}

const char * Form::GradeTooLowException::what() const throw()
{
    return "This grade is too low!";
}

const std::string &Form::getName() const {
    return (_name);
}

int Form::getSignal() const {
    return(_signal);
}

int Form::getGradeSign() const {
    return(_gradeToSign);
}

int Form::getGradeExecute() const {
    return(_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
    {
        throw Form::GradeTooLowException();
    }
    this->_signal = true;
}

std::ostream& operator<<(std::ostream &out, Form &object)
{
    out << object.getName() << ", form have the signal "
        << object.getSignal() << ", has grade to sign "
        << object.getGradeSign() << " and the grade to execute "
        << object.getGradeExecute() << std::endl;
    return (out);
}
