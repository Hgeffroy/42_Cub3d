SRCS			=	ft_atoi.c\
					ft_atoi_safe.c\
					ft_atoll.c\
					ft_bzero.c\
					ft_calloc.c\
					ft_dtoa.c\
					ft_fdprintf.c\
					ft_isalnum.c\
					ft_isalpha.c\
					ft_isascii.c\
					ft_ischarset.c\
					ft_isdigit.c\
					ft_isprint.c\
					ft_itoa.c\
					ft_lstadd_back.c\
					ft_lstadd_front.c\
					ft_lstclear.c\
					ft_lstdelone.c\
					ft_lstiter.c\
					ft_lstlast.c\
					ft_lstmap.c\
					ft_lstnew.c\
					ft_lstsize.c\
					ft_memchr.c\
					ft_memcmp.c\
					ft_memcpy.c\
					ft_memmove.c\
					ft_memset.c\
					ft_printf.c\
					ft_putchar_fd.c\
					ft_putchar.c\
					ft_putendl_fd.c\
					ft_putnbr_base.c\
					ft_putnbr_fd.c\
					ft_putnbr.c\
					ft_putstr_fd.c\
					ft_putstr.c\
					ft_putunbr.c\
					ft_split.c\
					ft_strchr.c\
					ft_strdup.c\
					ft_strndup.c\
					ft_strischarset.c\
					ft_striteri.c\
					ft_strjoin.c\
					ft_strlcat.c\
					ft_strlcpy.c\
					ft_strlen.c\
					ft_strmapi.c\
					ft_strcmp.c\
					ft_strncmp.c\
					ft_strnstr.c\
					ft_strrchr.c\
					ft_strtrim.c\
					ft_substr.c\
					ft_tabdup.c\
					ft_tabfree.c\
					ft_tolower.c\
					ft_toupper.c\
					get_next_line.c\

SRCS_D			=	srcs/

OBJS			=	$(SRCS:%.c=$(OBJS_D)%.o)

OBJS_D			=	objs/

HEAD			=	libft.h

HEAD_D			=	incs/

NAME			=	libft.a

AR				=	ar

ARFLAGS			=	rcs

CC				=	cc

RM				=	rm -rf

CFLAGS			=	-Wall -Wextra -Werror -g3

all				:	$(NAME)

$(NAME)			:	$(OBJS_D) $(OBJS) $(HEAD_D)$(HEAD)
				$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJS)			:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD_D)$(HEAD)
				$(CC) $(CFLAGS) -I$(HEAD_D) -c $< -o $@

clean			:
				$(RM) $(OBJS) $(OBJS_B) $(OBJS_D)

fclean			:	clean
				$(RM) $(NAME) $(OBJS_B)

$(OBJS_D)		:
				mkdir -p $(OBJS_D)

re				:	fclean all

.PHONY			:	all clean fclean re
