########################################################################################################################
#                                                       VARIABLE                                                       #
########################################################################################################################
INCS		:=	\
				cub3D.h\
				colors.h\
				structs.h\
				cub3D.h\
				define.h\
				display.h\
				enum.h\
				parsing.h\
				play.h\

SRCS		:=	\
				cub3D.c\
				\
				display/get_wall_color.c\
				display/init_col.c\
				display/mlx_utils.c\
				display/raycasting.c\
				display/texturing.c\
				\
				parsing/check_map.c\
				parsing/check_map_utils.c\
				parsing/get_map.c\
				parsing/get_map_file.c\
				parsing/get_new_map.c\
				parsing/get_txr_and_rgb.c\
				parsing/parsing.c\
				parsing/utils.c\
				\
				play/doors.c\
				play/hook.c\
				play/init_doors.c\
				play/init_walls.c\
				play/movements.c\
				play/play.c\
				play/rotation.c

SRCS_B		=	\
				$(SRCS)\
				\
				display/doors_display.c\
				display/minimap.c\
				display/minimap_utils.c\
				display/raycasting_doors.c\
				parsing/parsing_bonus.c\
				play/hook_bonus.c

INCS_D		:=	incs/

SRCS_D		:=	srcs/

OBJS_D		:=	objs/

DEPS_D		:=	deps/

OBJS		:=	$(SRCS:%.c=$(OBJS_D)%.o)

DEPS		:=	$(SRCS:%.c=$(DEPS_D)%.d)

NAME		:=	cub3D

SRCS_B_D	:=	deps_bonus/

OBJS_B_D	:=	objs_bonus/

DEPS_B_D	:=	deps_bonus/

NAME_B		:=	cub3D_bonus

OBJS_B		:=	$(SRCS_B:%.c=$(OBJS_B_D)%.o)

DEPS_B		:=	$(SRCS_B:%.c=$(DEPS_B_D)%.d)

########################################################################################################################
#                                                         LIB                                                          #
########################################################################################################################
LIB			:=	libft.a

LIB_D		:=	libft/

LIB_I		:=	$(LIB_D)$(INCS_D)

LIB_H		:=	$(LIB_I)libft.h

LIB_A		:=	$(LIB_D)$(LIB)

MLX			:=	libmlx.a

MLX_D		:=	MLX_Linux/

MLX_F		:=	-L$(MLX_D) -L/usr/lib -lmlx -lXext -lX11 -lm -lz

MLX_I		:=	$(MLX_D)

MLX_H		:=	$(MLX_I)mlx.h

MLX_A		:=	$(MLX_D)$(MLX)

########################################################################################################################
#                                                        FLAGS                                                         #
########################################################################################################################
CC			:=	cc

RM			:=	rm -rf

IFLAGS		:=	-I$(INCS_D) -I$(LIB_I) -I$(MLX_I)

DFLAGS		=	-MMD -MP -MT $@ -MF $(DEPS_D)$*.d

DFLAGS_B	=	-MMD -MP -MT $@ -MF $(DEPS_B_D)$*.d

CFLAGS		=	-Wall -Wextra -Werror -g3 $(IFLAGS)

OFLAGS		:=	-O3 #-Ofast -march=native -fomit-frame-pointer -funroll-loops

BFLAGS		:=	-DIS_BONUS=true

MAPS		?=	assets/maps_test/g_clean.cub

########################################################################################################################
#                                                        DEBUG                                                         #
########################################################################################################################
DEBUG		=	no

ifeq ($(DEBUG), yes)
	CFLAGS	+=	-fsanitize=address
endif

IGN_LEAK	:=	valgrind_ignore_leaks.txt

VALGRIND	:=	valgrind --leak-check=full --show-leak-kinds=all\
				--track-fds=yes --show-mismatched-frees=yes --read-var-info=yes --track-origins=yes -s
#				--default-suppressions=no

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
-include $(DEPS)

.DEFAULT_GOAL = all

all			:	$(NAME) $(BONUS) banner

$(NAME)		:	$(OBJS) $(LIB_A) $(MLX_A)
			$(CC) $(CFLAGS) $(OFLAGS) -o $(NAME) $(OBJS) $(MLX_A) $(LIB_A) $(MLX_F)

$(OBJS)		:	$(OBJS_D)%.o: $(SRCS_D)%.c | $(OBJS_D) $(DEPS_D)
			$(CC) $(CFLAGS) $(OFLAGS) $(DFLAGS) -c $< -o $@

$(OBJS_D)	:
			mkdir -p $(OBJS_D)
			mkdir -p $(OBJS_D)display
			mkdir -p $(OBJS_D)parsing
			mkdir -p $(OBJS_D)play

$(DEPS_D)	:
			mkdir -p $(DEPS_D)
			mkdir -p $(DEPS_D)display
			mkdir -p $(DEPS_D)parsing
			mkdir -p $(DEPS_D)play

$(LIB_A)	:	FORCE
			$(MAKE) -C $(LIB_D)

$(MLX_A)	:	FORCE
			$(MAKE) -C $(MLX_D) 2>/dev/null

leaks		:	$(NAME)
			$(VALGRIND) ./$(NAME_B) $(MAPS)

run			:	$(NAME)
			./$(NAME) $(MAPS)

fsan		:
			$(MAKE) fclean $(NAME) DEBUG=yes

########################################################################################################################
#                                                     BONUS RULES                                                      #
########################################################################################################################
-include $(DEPS_B)

bonus		:	$(NAME_B) banner

$(NAME_B)	:	$(OBJS_B) $(LIB_A) $(MLX_A)
			$(CC) $(CFLAGS) $(OFLAGS) $(BFLAGS) -o $(NAME_B) $(OBJS_B) $(MLX_A) $(LIB_A) $(MLX_F)

$(OBJS_B)	:	$(OBJS_B_D)%.o: $(SRCS_D)%.c | $(OBJS_B_D) $(DEPS_B_D)
			$(CC) $(CFLAGS) $(OFLAGS) $(BFLAGS) $(DFLAGS_B) -c $< -o $@

$(OBJS_B_D)	:
			mkdir -p $(OBJS_B_D)
			mkdir -p $(OBJS_B_D)display
			mkdir -p $(OBJS_B_D)parsing
			mkdir -p $(OBJS_B_D)play

$(DEPS_B_D)	:
			mkdir -p $(DEPS_B_D)
			mkdir -p $(DEPS_B_D)display
			mkdir -p $(DEPS_B_D)parsing
			mkdir -p $(DEPS_B_D)play

bleaks		:	$(NAME_B)
			$(VALGRIND) ./$(NAME_B) $(MAPS)

brun		:	$(NAME_B)
			./$(NAME_B) $(MAPS)

bfsan		:
			$(MAKE) fclean bonus DEBUG=yes

########################################################################################################################
#                                                    MISCELLANEOUS                                                     #
########################################################################################################################
banner		:
			@echo -e '$(BLUE)'
			@echo -e '   ______        __    _____  ____ '
			@echo -e '  / ____/__  __ / /_  |__  / / __ \'
			@echo -e ' / /    / / / // __ \  /_ < / / / /'
			@echo -e '/ /___ / /_/ // /_/ /___/ // /_/ / '
			@echo -e '\____/ \__,_//_.___//____//_____/  '
			@echo -e '$(BOLD)''$(ITALIC)'
			@echo -e '                        🙃  hgeffroy'
			@echo -e '                        🍦   xcharra'
			@echo -e '$(RESET)'

clean		:
			$(RM) $(OBJS) $(OBJS_D) $(DEPS_D) $(OBJS_B_D) $(DEPS_B_D)

fclean		:	clean
			$(RM) $(NAME) $(NAME_B)
			$(MAKE) fclean -C $(LIB_D)
			$(MAKE) clean -C $(MLX_D)

re			:	fclean all

FORCE		:

.PHONY		:	all debug leaks re clean fclean FORCE
