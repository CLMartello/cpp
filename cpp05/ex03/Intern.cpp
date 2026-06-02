
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern &copy) 
{
    (void)copy;
}

Intern &Intern::operator=(Intern &copy)
{
    (void)copy;
    return (*this);
}

Intern::~Intern() {}

const char * Intern::NoValidFormException::what() const throw()
{
    return "This is not a valid form!";
}

static AForm *createShrubberyCreation(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

static AForm *createRobotomyRequest(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *createPresidentialForm(const std::string &target)
//static function is a membr function that do not belong to the object of the class
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &form, const std::string &target)
{
    const std::string validInputs[3] = {
        "shrubbery creation", "robotomy request", "presidential pardon"
    };

    AForm* (*validFuntions[3])(const std::string&) = {
    //array of 3 functions , each element is a pointer to a function
    //the array has 3 functions, not 3 objects with a function inside (the case to Intern::function)
        &createShrubberyCreation,
        &createRobotomyRequest,
        &createPresidentialForm
    };

    for (int i = 0; i < 3; i++) {
        if (form == validInputs[i]) {
            std::cout << "Intern creates " << form << std::endl;
            return (validFuntions[i](target));
        }
    }

    throw NoValidFormException();
}

