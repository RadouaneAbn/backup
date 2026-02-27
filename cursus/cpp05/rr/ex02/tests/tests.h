#ifndef TESTS_H
#define TESTS_H

#include "../colors.h"

class Bureaucrat;
class AForm;
class ShrubberyCreationForm;
class PresidentialPardonForm;
class RobotomyRequestForm;
class Intern;

void sc_test_grade_not_high_enough_to_sign(Bureaucrat bureaucrat, ShrubberyCreationForm form);
void sc_test_grade_not_high_enough_to_execute(Bureaucrat bureaucrat, ShrubberyCreationForm form);
void sc_test_grade_ok_to_sign_and_execute(Bureaucrat bureaucrat, ShrubberyCreationForm form);

void pp_test_grade_not_high_enough_to_sign(Bureaucrat bureaucrat, PresidentialPardonForm form);
void pp_test_grade_not_high_enough_to_execute(Bureaucrat bureaucrat, PresidentialPardonForm form);
void pp_test_grade_ok_to_sign_and_execute(Bureaucrat bureaucrat, PresidentialPardonForm form);
void rr_test_grade_not_high_enough_to_sign(Bureaucrat bureaucrat, RobotomyRequestForm form);

void rr_test_grade_not_high_enough_to_sign(Bureaucrat bureaucrat, RobotomyRequestForm form);
void rr_test_grade_not_high_enough_to_execute(Bureaucrat bureaucrat, RobotomyRequestForm form);
void rr_test_grade_ok_to_sign_and_execute(Bureaucrat bureaucrat, RobotomyRequestForm form);
void rr_test_grade_ok_to_sign_and_execute_multi(Bureaucrat bureaucrat, RobotomyRequestForm form);

void intern_test_valid_shrubbery_creation(Intern intern);
void intern_test_valid_robotomy_request(Intern intern);
void intern_test_valid_presidential_pardon(Intern intern);
void intern_test_invalid_form_name(Intern intern);

#endif