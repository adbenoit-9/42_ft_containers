# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 14:50:21 by adbenoit          #+#    #+#              #
#    Updated: 2021/06/30 16:37:49 by adbenoit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	containers

SRC_PATH	=	src/
TEST_PATH	=	test/

SRC		=	main.cpp

TEST	=	testStack.cpp


CC			=	clang++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

OBJ_PATH	=	obj/

OBJ_NAME	=	$(SRC:.cpp=.o)
OBJ_NAME	+=	$(TEST:.cpp=.o)

OBJ		=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME) : $(OBJ)
	@printf "\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "Compilation of \033[33;1m$(NAME)\033[0;1m: [\033[1;32mOK\033[0;1m]\033[0m"

$(OBJ_PATH)%.o:	$(SRC_PATH)%.cpp
	@printf "\033[34;1m|\033[0;m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o:	$(TEST_PATH)%.cpp
	@printf "\033[34;1m|\033[0;m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< -o $@

run: all
	@./$(NAME)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)
	@echo "\033[33;1m$(NAME)\033[0;1m: objects deleted\033[0m"

fclean:	clean
	@rm -rf $(NAME)
	@echo "\033[33;1m$(NAME)\033[0;1m: $(NAME) deleted\033[0m"

re: fclean all

debug:
	@echo "\033[34;1mOBJ\033[0;m = $(OBJ)"
	@echo "\033[34;1mSRC\033[0;m = $(SRC)"

.PHONY: all clean fclean re run
