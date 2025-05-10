# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/10 18:24:44 by jorvarea          #+#    #+#              #
#    Updated: 2025/05/10 18:52:04 by jorvarea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################################################################
##                               COMPILATION INFO                             ##
################################################################################

NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

################################################################################
##                              SOURCES AND OBJECTS                           ##
################################################################################

SRC = megaphone.cpp

OBJECTS = $(SRC:.cpp=.o)

################################################################################
##                                    COLORS                                 ##
################################################################################

END=\033[0m
BOLD=\033[1m
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[33m
MAGENTA=\033[35m
TURQUOISE=\033[36m

################################################################################
##                                     RULES                                  ##
################################################################################

all : head $(NAME)

head :
	@echo " $(MAGENTA) 42MLG: $(BLUE) by jorvarea$(END)"
	@echo " $(MAGENTA) Executable: $(BLUE) $(NAME)$(END)"
	@echo " $(MAGENTA) Commands: $(BLUE)all clean fclean re$(END)"
	@echo " $(MAGENTA) 🛠   Compiler: $(BLUE) $(CC) $(CFLAGS) $(END)"

$(NAME) : $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o : %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)  ✓ Compiled: $(notdir $<)$(END)"

clean :
	@echo "$(RED)$(BOLD)  CLEANING...$(END)"
	@$(RM) $(OBJECTS)

fclean : clean
	@$(RM) $(NAME)
	@echo "$(RED)  ✓  Removed $(NAME) $(END)"

re : fclean all

.PHONY: all head clean fclean re
