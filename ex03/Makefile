NAME		    =   intern
CXX			    =   c++
CXXFLAGS	    =   -Wall -Wextra -Werror -std=c++98 -I$(HEADERS_DIR)

RESET           =   \033[0m
RED             =   \033[31m
GREEN           =   \033[32m
BLUE            =   \033[34m

SRCS_FILES	    =   main.cpp \
                    Bureaucrat.cpp \
                    AForm.cpp \
                    ShrubberyCreationForm.cpp \
                    RobotomyRequestForm.cpp \
                    PresidentialPardonForm.cpp \
                    Intern.cpp

HEADERS_FILES   =   Bureaucrat.hpp \
                    AForm.hpp \
                    ShrubberyCreationForm.hpp \
                    RobotomyRequestForm.hpp \
                    PresidentialPardonForm.hpp \
                    Intern.hpp

SRCS_DIR	= src
HEADERS_DIR = inc
OBJ_DIR		= obj

SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
HEADERS     = $(addprefix $(HEADERS_DIR)/, $(HEADERS_FILES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)Successfully compiled [$(NAME)]$(RESET)"

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.cpp $(HEADERS) Makefile
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(BLUE)Compiling $<$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Executable [$(NAME)] removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re