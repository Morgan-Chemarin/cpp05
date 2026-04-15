NAME		= intern
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS_FILES	= main.cpp \
              Bureaucrat.cpp \
              AForm.cpp \
              ShrubberyCreationForm.cpp \
              RobotomyRequestForm.cpp \
              PresidentialPardonForm.cpp \
              Intern.cpp

HEADERS		= Bureaucrat.hpp \
              AForm.hpp \
              ShrubberyCreationForm.hpp \
              RobotomyRequestForm.hpp \
              PresidentialPardonForm.hpp \
              Intern.hpp

SRCS_DIR	= .
OBJ_DIR		= obj

SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "\033[32mSuccessfully compiled [$(NAME)]\033[0m"

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.cpp $(HEADERS) Makefile
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "\033[34mCompiling $<\033[0m"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[31mObject files removed.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mExecutable [$(NAME)] removed.\033[0m"

re: fclean all

.PHONY: all clean fclean re