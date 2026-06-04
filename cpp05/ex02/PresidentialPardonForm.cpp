
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5),
      _target("Default")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : AForm("PresidentialPardonForm", 25, 5),
      _target(target)
{}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
    : AForm(copy),
      _target(copy._target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    if (this != &copy)
        this->_target = copy._target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string &PresidentialPardonForm::getTarget() const
{
    return(_target);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (this->getSignal() == false)
        throw AForm::FormNotSignedException();
    
    if (executor.getGrade() > this->getGradeExecute())
        throw AForm::GradeTooLowException();

    std::cout << this->getTarget()
              << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
