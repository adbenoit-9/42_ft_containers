# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 14:50:21 by adbenoit          #+#    #+#              #
#    Updated: 2021/09/25 01:48:42 by adbenoit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_NAME 	=	ft_containers
STL_NAME 	=	stl_containers


SRCS_PATH	=	test_srcs/
SRCS		=	main.cpp 

CC			=	clang++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

OBJ_PATH	=	obj/
OBJ_NAME	=	$(SRCS:.cpp=.o)
OBJ			=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

all:
	@sed -i '' 's/0/1/' "$(SRCS_PATH)test.hpp"
	@echo "\033[33m$(STL_NAME)\033[0m: tests ajusted\033[0m"
	@$(MAKE) stl
	@sed -i '' 's/1/0/' "test_srcs/test.hpp"
	@echo "\n\033[33m$(FT_NAME)\033[0m: tests ajusted\033[0m"
	@$(MAKE) ft

ft: clean $(FT_NAME)

stl: clean $(STL_NAME)

$(FT_NAME) : $(OBJ)
	@printf "\n"
	@$(CC) $(CFLAGS) -o $(FT_NAME) $(OBJ) && ([ $$? -eq 0 ] && \
	echo "Compilation of \033[33;1m$(FT_NAME)\033[0;1m: [\033[1;32mOK\033[0;1m]\033[0m") \
	|| echo "Compilation of \033[33;1m$(FT_NAME)\033[0;1m: [\033[1;31mKO\033[0;1m]\033[0m"

$(STL_NAME) : $(OBJ)
	@printf "\n"
	@$(CC) $(CFLAGS) -o $(STL_NAME) $(OBJ) && ([ $$? -eq 0 ] && \
	echo "Compilation of \033[33;1m$(STL_NAME)\033[0;1m: [\033[1;32mOK\033[0;1m]\033[0m") \
	|| echo "Compilation of \033[33;1m$(STL_NAME)\033[0;1m: [\033[1;31mKO\033[0;1m]\033[0m"
	
$(OBJ_PATH)%.o:	$(SRCS_PATH)%.cpp
	@printf "\033[34;1m|\033[0;m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< -o $@

# **************************************************************************************** #
#										RUN TESTS										   #
# **************************************************************************************** #

FT_FILE		=	ft.out.txt
STL_FILE	=	stl.out.txt
DIFF_FILE	=	diff.txt
SUCCESS		=	"\033[1m✅ Sucess ! \033[0mNo difference."
FAILURE		=	"\033[1m❌ Failure ! \033[0mDifference in \033[4m$(DIFF_FILE).\033[0m"

run: re
	@echo "\033[1m"
	@echo "# ************************************************************************ #"
	@echo "#  ____ ____ _  _ ___ ____ _ _  _ ____ ____ ____   ___ ____ ____ ___ ____  #"
	@echo "#  |    |  | |\ |  |  |__| | |\ | |__  |__/ [__     |  |__  [__   |  [__   #"
	@echo "#  |___ |__| | \|  |  |  | | | \| |___ |  \ ___]    |  |___ ___]  |  ___]  #"
	@echo "#                                                                          #"
	@echo "# ************************************************************************ #"
	@echo "\033[0m"
	@./$(FT_NAME) > $(FT_FILE)
	@echo "\033[34m$(FT_NAME)\033[0m: outputs in \033[4m$(FT_FILE)\033[0m"
	@./$(STL_NAME) > $(STL_FILE)
	@echo "\033[34m$(STL_NAME)\033[0m: outputs in \033[4m$(STL_FILE)\033[0m\n"
	@diff $(STL_FILE) $(FT_FILE) > $(DIFF_FILE) \
	&& ([ $$? -eq 0 ] && echo $(SUCCESS); rm $(DIFF_FILE)) || echo $(FAILURE)
	@echo

# **************************************************************************************** #
#											UTILS										   #
# **************************************************************************************** #

clean:
	@rm -rf $(OBJ) $(OBJ_PATH)
	@echo "\033[33mContainers\033[0m: objects deleted\033[0m"

fclean:	clean
	@echo
	@rm -rf $(STL_FILE) $(FT_FILE) $(DIFF_FILE)
	@echo "\033[33mContainers\033[0m: outputs files deleted\033[0m"
	@rm -rf $(FT_NAME)
	@echo "\033[33m$(FT_NAME)\033[0m: $(FT_NAME) deleted\033[0m"
	@rm -rf $(STL_NAME)
	@echo "\033[33m$(STL_NAME)\033[0m: $(STL_NAME) deleted\033[0m"

re: fclean all

debug:
	@echo "\033[34;1mOBJ\033[0;m\t\t= $(OBJ)"
	@echo "\033[34;1mSRCS PATH\033[0;m\t= $(SRCS_PATH)"
	@echo "\033[34;1mSRCS\033[0;m\t\t= $(SRCS)"
	@echo "\033[34;1mls $(SRCS_PATH)\033[0;m\t= $(shell ls $(SRCS_PATH))"

help:
	@echo Usage:
	@echo "\t[make]        : compile FT containers and STL containers tests"
	@echo "\t[make stl]    : compile STL containers tests"
	@echo "\t[make ft]     : compile FT containers tests"
	@echo "\t[make run]    : run all tests and compare results"
	@echo "\t[make clean]  : delete objects"
	@echo "\t[make fclean] : [make clean] + delete executables and outputs files"
	@echo "\t[make re]     : [make fclean] and [make]"

.PHONY: all clean fclean re run stl ft getFt getStl help

# .IGNORE:
