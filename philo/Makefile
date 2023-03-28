# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victofer <victofer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 18:07:00 by victofer          #+#    #+#              #
#    Updated: 2023/03/28 10:43:07 by victofer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	philo
CFLAGS 	= 	-Wall -Wextra -Werror -pthread

SRC 	= 	main.c \
			ft_atoi.c \
			ft_errors.c \
			checks.c \
			free_structs.c \
			leaks.c \
			time.c \
			init_structs.c \
			
OBJS		= $(SRC:.c=.o)

# T E X T   S T U F F
G = \033[0;92m
R = \033[0;31m
B = \033[0;96m	
Y = \033[0;33m
WY = \033[0;93m
M = \033[0;95m
BOLD = \033[0;1m

E = \033[0m

all: nice_text $(NAME)

nice_text:
	@echo "$(B)"
	@echo " ___   _   _ ___ _      _   ____    _   ___   _   _ _____ ___    ___   "
	@echo "|  _ \| | | |_ _| |   / _ \/ ___| / _ \|  _ \| | | | ____|  _ \/ ___|  "
	@echo "| |_) | |_| || || |  | | | \___ \| | | | |_) | |_| |  _| | |_) \___ \  "
	@echo "|  __/|  _  || || |__| |_| |___) | |_| |  __/|  _  | |___|  _ < ___) | "
	@echo "|_|   |_| |_|___|_____\___/|____/ \___/|_|   |_| |_|_____|_| \_|____/  "
	@echo "___________________________________________________________________"
	@echo "\___________________________________________________________________\ "
	@echo "$(E)"

norminette:
	@echo ""
	@echo "$(Y) ---- N O R M I N E T T E ----$(E)"
	@sleep 1
	@echo "$(BOLD)"
	@norminette
	@echo "$(Y)------- $(G)EVERITHING OK$(Y) -------$(E)"

$(NAME): $(OBJS)
	@gcc $(CFLAGS) $(OBJS) -o philo 
	@echo "$(Y)0-----------------------0"
	@echo "$(Y)|$(G)     PHILO CREATED    $(Y) |"
	@echo "$(Y)0-----------------------0"
	@echo "$(E)"

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@echo ""
	@echo "$(Y)0------------------------0"
	@echo "$(Y)|$(M)  EVERYTHING CLEANED   $(Y) |"
	@echo "$(Y)0------------------------0"
	@echo "$(E)"
	@/bin/rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
.SILENT: $(OBJS)