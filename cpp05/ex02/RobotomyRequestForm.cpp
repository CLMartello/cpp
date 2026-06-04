
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45),
      _target("Default")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("RobotomyRequestForm", 72, 45),
      _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : AForm(copy),
      _target(copy._target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if (this != &copy)
        this->_target = copy._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string &RobotomyRequestForm::getTarget() const
{
    return(_target);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    srand(std::time(0));
    if (this->getSignal() == false)
        throw AForm::FormNotSignedException();
    
    if (executor.getGrade() > this->getGradeExecute())
        throw AForm::GradeTooLowException();

    std::cout << "DRLLL DRLLLLL DRLLLZZZZZ" << std::endl;

    if (rand() % 2)
        std::cout << this->getTarget() << " has been robotomized" << std::endl;
    else
        std::cout << this->getTarget() << " robotomy failed." << std::endl;

}
