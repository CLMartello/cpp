
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "fstream"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137),
      _target("Default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("ShrubberyCreationForm", 145, 137),
      _target(target)
{}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm(copy),
      _target(copy._target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if (this != &copy)
        this->_target = copy._target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (this->getSignal() == false)
        throw AForm::FormNotSignedException();
    
    if (executor.getGrade() > this->getGradeExecute())
        throw AForm::GradeTooLowException();

    std::ofstream file;
    std::string filename = _target + "_shrubbery";
    file.open(filename.c_str());

    file << "      *       " << std::endl;
    file << "     ***      " << std::endl;
    file << "    *****     " << std::endl;
    file << "   *******    " << std::endl;
    file << "     |||      " << std::endl;

    file.close();
}
