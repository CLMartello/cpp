
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("Default"), _signal(false), _gradeToSign(50), _gradeToExecute(100) {}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute)
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

AForm::AForm(const AForm &copy)
    : _name(copy._name),
      _signal(copy._signal),
      _gradeToSign(copy._gradeToSign),
      _gradeToExecute(copy._gradeToExecute) {}

AForm &AForm::operator=(const AForm &copy) {
    if (this != &copy)
    {
        this->_signal = copy._signal;
    }
    return (*this);
}

AForm::~AForm() {}


const char * AForm::GradeTooHighException::what() const throw()
{
    return "This grade is too high!";
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return "This grade is too low!";
}

const char * AForm::FormNotSignedException::what() const throw()
{
    return "This form was not signed!";
}

const std::string &AForm::getName() const {
    return (_name);
}

int AForm::getSignal() const {
    return(_signal);
}

int AForm::getGradeSign() const {
    return(_gradeToSign);
}

int AForm::getGradeExecute() const {
    return(_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
    {
        throw AForm::GradeTooLowException();
    }
    this->_signal = true;
}

std::ostream& operator<<(std::ostream &out, AForm &object)
{
    out << object.getName() << ", form have the signal "
        << object.getSignal() << ", has grade to sign "
        << object.getGradeSign() << " and the grade to execute "
        << object.getGradeExecute() << std::endl;
    return (out);
}
