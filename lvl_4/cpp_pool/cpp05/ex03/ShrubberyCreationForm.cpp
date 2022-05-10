/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:13:09 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/10 18:51:26 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationForm", 0, 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm:: ShrubberyCreationForm(ShrubberyCreationForm &F){
	std::cout << "Copy ShrubberyCreationForm constructor called" << std::endl;
	*this = F;
}

ShrubberyCreationForm & ShrubberyCreationForm:: operator=(const ShrubberyCreationForm &F){
	std::cout  << "Copy assignment ShrubberyCreationForm constructor called" <<  std::endl;
	(void)F;
	return *this;
}

void ShrubberyCreationForm:: execute(Bureaucrat const & executor) const{
	std::ofstream	myfile;
	std::string		fileName = this->target + "_shrubbery";
	if (this->getbool() != true){
		std::cout << "is not signed" << std::endl;
		return;
	}
	if (executor.getGrade() > this->getexec()){
		throw GradeTooLowException();
	}
	if (executor.getGrade() < 1)
		throw GradeTooHighException();
	myfile.open(fileName, std::ios::out);
	myfile << "      ,.," << std::endl;
	myfile << "      MMMM_    ,..," << std::endl;
	myfile << "        \"_ \"__\"MMMMM          ,...,," << std::endl;
	myfile << " ,..., __.\" --\"    ,.,     _-\"MMMMMMM" << std::endl;
	myfile << "MMMMMM\"___ \"_._   MMM\"_.\"\" _ \"\"\"\"\"\"" << std::endl;
	myfile << " \"\"\"\"\"    \"\" , \\_.   \"_. .\"" << std::endl;
	myfile << "        ,., _\"__ \\__./ .\"" << std::endl;
	myfile << "       MMMMM_\"  \"_    ./" << std::endl;
	myfile << "        ''''      (    )" << std::endl;
	myfile << " ._______________.-'____\"---._." << std::endl;
	myfile << "  \\                          /" << std::endl;
	myfile << "   \\________________________/" << std::endl;
	myfile << "   (_)                    (_)" << std::endl;
	myfile.close();
	std::cout << "Created the shrug in " << this->target << "_shrubbery"
		<< std::endl;
}

ShrubberyCreationForm:: ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 0, 145, 137){
	this->target = target;
}
