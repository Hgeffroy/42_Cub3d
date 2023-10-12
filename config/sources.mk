# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 12:38:03 by hgeffroy          #+#    #+#              #
#    Updated: 2023/10/12 09:09:32 by hgeffroy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = 	source/parsing/parsing.c \
			source/parsing/get_map.c \
			source/parsing/check_map.c \
			source/parsing/check_map_utils.c \
			source/parsing/get_textures.c \
			source/parsing/parsing_utils.c \
			source/display/minimap.c \
			source/display/raycasting.c \
			source/display/texturing.c \
			source/display/init_col.c \
			source/display/get_wall_color.c \
			source/play/movements.c \
			source/play/hook.c \
			source/play/play.c \
			source/main.c