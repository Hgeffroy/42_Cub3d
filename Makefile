########################################################################################################################
#                                                       VARIABLE                                                       #
########################################################################################################################
SRCS		:=	\
				cub3D.c\
				display/get_wall_color.c\
				display/init_col.c\
				display/minimap.c\
				display/raycasting.c\
				display/texturing.c\
				parsing/check_map.c\
				parsing/check_map_utils.c\
				parsing/get_map.c\
				parsing/get_map_file.c\
				parsing/get_new_map.c\
				parsing/get_txr_and_rgb.c\
				parsing/parsing.c\
				parsing/utils.c\
				play/doors.c\
				play/hook.c\
				play/init_doors.c\
				play/init_walls.c\
				play/movements.c\
				play/play.c\
				play/rotation.c\

SRCS_B		=	$(SRCS)\
				parsing/parsing_bonus.c

HEAD		:=	\
				cub3D.h\
				colors.h\
				structs.h\
				cub3D.h\
				define.h\
				display.h\
				enum.h\
				parsing.h\
				play.h\

SRCS_D		:=	srcs/

HEAD_D		:=	incs/

OBJS_D		:=	objs/

OBJS_B_D	:=	objs_bonus/

OBJS		=	$(SRCS:%.c=$(OBJS_D)%.o)

OBJS_B		=	$(SRCS_B:%.c=$(OBJS_B_D)%.o)

HEAD_A		:=	$(addprefix $(HEAD_D), $(HEAD))

NAME		:=	cub3D

NAME_B		:=	cub3D_bonus

########################################################################################################################
#                                                         LIB                                                          #
########################################################################################################################
LIB			:=	libft.a

LIB_D		:=	libft/

LIB_I		:=	$(LIB_D)$(HEAD_D)

LIB_H		:=	$(LIB_I)libft.h

LIB_A		:=	$(LIB_D)$(LIB)

MLX			:=	libmlx.a

UNAME_S		:=	$(shell uname -s)
ifeq ($(UNAME_S),Linux)
MLX_D		:=	MLX_Linux/

MLX_F		:=	-L$(MLX_D) -L/usr/lib -lmlx -lXext -lX11 -lm -lz

endif
ifeq ($(UNAME_S),Darwin)
MLX_D		:=	MLX_MacOS/

MLX_F		:=	-framework OpenGL -framework AppKit

endif

MLX_I		:=	$(MLX_D)

MLX_H		:=	$(MLX_I)mlx.h

MLX_A		:=	$(MLX_D)$(MLX)

########################################################################################################################
#                                                        FLAGS                                                         #
########################################################################################################################
CC			:=	cc

RM			:=	rm -rf

CFLAGS		:=	-Wall -Wextra -Werror -g3

OPTI_F		:=	-O3 #-Ofast -march=native -fomit-frame-pointer -funroll-loops

BFLAGS		:=	-DIS_BONUS=true

MAPS		?=	maps/g_clean.cub

########################################################################################################################
#                                                        DEBUG                                                         #
########################################################################################################################
DEBUG		:=	no

ifeq ($(DEBUG), yes)
ASAN_F		:=	-fsanitize=address
endif

IGN_LEAK	:=	valgrind_ignore_leaks.txt

VALGRIND	:=	valgrind --leak-check=full --show-leak-kinds=all\
				--track-fds=yes --show-mismatched-frees=yes --read-var-info=yes -s

########################################################################################################################
#                                                        COLORS                                                        #
########################################################################################################################
BLUE		:=	\001\033[34m\002

BOLD		:=	\001\033[1m\002

ITALIC		:=	\001\033[3m\002

RESET		:=	\001\033[0m\002

########################################################################################################################
#                                                        RULES                                                         #
########################################################################################################################
all			:	$(NAME) banner

$(NAME)		:	$(OBJS_D) $(OBJS) $(LIB_A) $(MLX_A) Makefile
			$(CC) $(CFLAGS) $(ASAN_F) $(OPTI_F) -o $(NAME) $(OBJS) $(MLX_A) $(LIB_A) $(MLX_F)

$(OBJS)		:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD_A) $(LIB_H) $(MLX_H)
			$(CC) $(CFLAGS) $(ASAN_F) $(OPTI_F) -I$(HEAD_D) -I$(LIB_I) -I$(MLX_I) -c $< -o $@

$(OBJS_D)	:
			mkdir -p $(OBJS_D)
			mkdir -p $(OBJS_D)display
			mkdir -p $(OBJS_D)parsing
			mkdir -p $(OBJS_D)play

$(LIB_A)	:	$(LIB_D)
			$(MAKE) -C $(LIB_D)

$(MLX_A)	:	$(MLX_D)
			$(MAKE) -j -C $(MLX_D) 2>/dev/null

leaks		:	all
			$(VALGRIND) ./$(NAME) $(MAPS)

run			:	all
			./$(NAME) $(MAPS)

fsan		:
			$(MAKE) re DEBUG=yes

########################################################################################################################
#                                                     BONUS RULES                                                      #
########################################################################################################################
bonus		:	$(NAME_B) banner

$(NAME_B)	:	$(OBJS_B_D) $(OBJS_B) $(LIB_A) $(MLX_A) Makefile
			$(CC) $(CFLAGS) $(ASAN_F) $(OPTI_F) $(BFLAGS) -o $(NAME_B) $(OBJS_B) $(MLX_A) $(LIB_A) $(MLX_F)

$(OBJS_B)	:	$(OBJS_B_D)%.o: $(SRCS_D)%.c $(HEAD_A) $(LIB_H) $(MLX_H)
			$(CC) $(CFLAGS) $(ASAN_F) $(OPTI_F) $(BFLAGS) -I$(HEAD_D) -I$(LIB_I) -I$(MLX_I) -c $< -o $@

$(OBJS_B_D)	:
			mkdir -p $(OBJS_B_D)
			mkdir -p $(OBJS_B_D)display
			mkdir -p $(OBJS_B_D)parsing
			mkdir -p $(OBJS_B_D)play

bleaks		:	bonus
			$(VALGRIND) ./$(NAME_B) $(MAPS)

brun		:	all
			./$(NAME_B) $(MAPS)

bfsan		:
			$(MAKE) fclean bonus DEBUG=yes

banner		:
			@echo -e '$(BLUE)'
			@echo -e '   ______        __    _____  ____ '
			@echo -e '  / ____/__  __ / /_  |__  / / __ \'
			@echo -e ' / /    / / / // __ \  /_ < / / / /'
			@echo -e '/ /___ / /_/ // /_/ /___/ // /_/ / '
			@echo -e '\____/ \__,_//_.___//____//_____/  '
			@echo -e '     _/_/_/            _/        _/_/_/    _/_/_/    '
			@echo -e '  _/        _/    _/  _/_/_/          _/  _/    _/   '
			@echo -e ' _/        _/    _/  _/    _/    _/_/    _/    _/    '
			@echo -e '_/        _/    _/  _/    _/        _/  _/    _/     '
			@echo -e ' _/_/_/   _/_/_/   _/_/_/    _/_/_/    _/_/_/        '
			@echo -e '$(BOLD)''$(ITALIC)'
			@echo -e '                           🙃  hgeffroy   🍦  xcharra'
			@echo -e '$(RESET)'

clean		:
			$(RM) $(OBJS) $(OBJS_D) $(OBJS_B) $(OBJS_B_D)
			$(MAKE) clean -C $(LIB_D)

fclean		:	clean
			$(RM) $(NAME) $(NAME_B)
			$(MAKE) fclean -C $(LIB_D)
			$(MAKE) clean -C $(MLX_D)

re			:	fclean all

.PHONY		:	all bonus leaks run fsan banner clean fclean re