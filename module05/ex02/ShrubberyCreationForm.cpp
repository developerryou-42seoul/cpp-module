#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "none", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 145, 137)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref) : AForm("ShrubberyCreationForm", ref.getTarget(), 145, 137)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
	(void)ref;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() == false)
		throw NotSignedException();
	if (getExecuteGrade() < executor.getGrade())
		throw NotPermittedException();
	makeTree();
}

void ShrubberyCreationForm::makeTree() const 
{
	std::string filename = getTarget().append("_shrubbery");
	std::ofstream writeFile(filename);

	writeFile << 
	"\n" << 
	"                                                     .          \n" << 
    "                                          .         ;           \n" << 
    "             .              .              ;%     ;;            \n" << 
    "               ,           ,                :;%  %;             \n" << 
    "                :         ;                   :;%;'     .,      \n" << 
    "       ,.        %;     %;            ;        %;'    ,;        \n" << 
    "         ;       ;%;  %%;        ,     %;    ;%;    ,%'         \n" << 
    "          %;       %;%;      ,  ;       %;  ;%;   ,%;'          \n" << 
    "           ;%;      %;        ;%;        % ;%;  ,%;'            \n" << 
    "            `%;.     ;%;     %;'         `;%%;.%;'              \n" << 
    "             `:;%.    ;%%. %@;        %; ;@%;%'                 \n" << 
    "                `:%;.  :;bd%;          %;@%;'                   \n" << 
    "                  `@%:.  :;%.         ;@@%;'                    \n" << 
    "                    `@%.  `;@%.      ;@@%;                      \n" << 
    "                      `@%%. `@%%    ;@@%;                       \n" << 
    "                        ;@%. :@%%  %@@%;                        \n" << 
    "                          %@bd%%%bd%%:;                         \n" << 
    "                            #@%%%%%:;;                          \n" << 
    "                            %@@%%%::;                           \n" << 
    "                            %@@@%(o);  . '                      \n" << 
    "                            %@@@o%;:(.,'                        \n" << 
    "                        `.. %@@@o%::;                           \n" << 
    "                           `)@@@o%::;                           \n" << 
    "                            %@@(o)::;                           \n" << 
    "                           .%@@@@%::;                           \n" << 
    "                           ;%@@@@%::;.                          \n "<< 
    "                          ;%@@@@%%:;;;.                         \n" << 
    "                      ...;%@@@@@%%:;;;;,..                      \n";

	writeFile.close();
}
