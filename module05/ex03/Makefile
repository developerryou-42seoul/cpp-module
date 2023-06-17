NAME = intern
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = ./main.cpp \
		./Bureaucrat.cpp \
		./AForm.cpp \
		./PresidentialPardonForm.cpp \
		./RobotomyRequestForm.cpp \
		./ShrubberyCreationForm.cpp \
		./Intern.cpp

OBJS = $(SRCS:.cpp=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	
all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: 
	make fclean 
	make all

.PHONY: all clean fclean re
