# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 14:14:21 by hgeffroy          #+#    #+#              #
#    Updated: 2023/09/27 14:47:16 by hgeffroy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config/sources.mk

#--variables-------------------------------------------------------------------#

NAME            =       cub3D
DEBUG           =       yes

#--includes & libraries--------------------------------------------------------#

INC_DIR         =       include
LIBFT_DIR       =       source/libft
MLX_DIR			=		source/minilibx-linux

#--sources & objects-----------------------------------------------------------#

SRC_DIR         =       source
OBJ_DIR         =       .objs

#--flags-----------------------------------------------------------------------#

CFLAGS          =       -g3 -Wall -Wextra -O3 -I $(LIBFT_DIR)/header -I $(INC_DIR) -I /usr/include #-Werror
MLXFLAGS		=		-L $(MLX_DIR) -l mlx -l Xext -l X11 -l m -I $(MLX_DIR)

#--debug flags-----------------------------------------------------------------#

DFLAGS          =       -g3 -fsanitize=address

ifeq ($(DEBUG), yes)
CFLAGS          +=      $(DFLAGS)
endif

#--libs------------------------------------------------------------------------#

LIBFT   =       $(LIBFT_DIR)/libft.a

#--objects---------------------------------------------------------------------#

OBJECTS =       $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

#--global rules----------------------------------------------------------------#

.DEFAULT_GOAL = all

#--compilation rules-----------------------------------------------------------#

all:
		$(MAKE) -C ./source/minilibx-linux
		$(MAKE) -C ./source/libft
		$(MAKE) $(NAME) -j

$(NAME): $(OBJECTS) $(LIBFT)
		$(CC) $^ $(CFLAGS) $(MLXFLAGS) -o $@

$(OBJ_DIR)/%.o: %.c $(HEADERS) 
		mkdir -p $(dir $@)
		$(CC) $(CFLAGS) $(MLXFLAGS) -c $< -o $@

#--libs, debugs & bonus--------------------------------------------------------#

lib:
		$(MAKE) -C $(LIBFT_DIR)

debug:
		$(MAKE) re -j DEBUG=yes

#--re, clean & fclean----------------------------------------------------------#

re:
		clear
		$(MAKE) fclean
		$(MAKE) -j all

clean:
		$(MAKE) -C $(LIBFT_DIR) clean
		$(MAKE) -C $(MLX_DIR) clean
		$(RM) -rf $(OBJECTS)

fclean:
		clear
		$(MAKE) clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(RM) $(NAME)

#--PHONY-----------------------------------------------------------------------#

.PHONY: all lib debug re clean fclean
