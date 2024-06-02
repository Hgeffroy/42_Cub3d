########################################################################################################################
#                                                       VARIABLE                                                       #
########################################################################################################################
INCS		:=	\
				libft.h\

SRCS		:=	\
				ft_atoi.c\
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

INCS_D		:=	incs/

SRCS_D		:=	srcs/

OBJS_D		:=	objs/

DEPS_D		:=	deps/

OBJS		:=	$(SRCS:%.c=$(OBJS_D)%.o)

DEPS		:=	$(SRCS:%.c=$(DEPS_D)%.d)

NAME		:=	libft.a

########################################################################################################################
#                                                        FLAGS                                                         #
########################################################################################################################
CC			:=	cc

AR			:=	ar

RM			:=	rm -rf

IFLAGS		:=	-I $(INCS_D)

DFLAGS		=	-MMD -MP -MT $@ -MF $(DEPS_D)$*.d

CFLAGS		=	-Wall -Wextra -Werror -g3 $(IFLAGS)

ARFLAGS		=	rcs
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

all			:	$(NAME) banner

$(NAME)		:	$(OBJS)
			$(AR) $(ARFLAGS) -o $(NAME) $(OBJS)

$(OBJS)		:	$(OBJS_D)%.o: $(SRCS_D)%.c | $(OBJS_D) $(DEPS_D)
			$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

$(OBJS_D)	:
			mkdir -p $(OBJS_D)

$(DEPS_D)	:
			mkdir -p $(DEPS_D)

banner		:
			@echo -e '$(BLUE)'
			@echo -e '    __    _ __    ______ '
			@echo -e '   / /   (_) /_  / __/ /_'
			@echo -e '  / /   / / __ \/ /_/ __/'
			@echo -e ' / /___/ / /_/ / __/ /_  '
			@echo -e '/_____/_/_.___/_/  \__/  '
			@echo -e '$(BOLD)''$(ITALIC)'
			@echo -e '              🍦  xcharra'
			@echo -e '$(RESET)'

clean		:
			$(RM) $(OBJS) $(OBJS_D) $(DEPS_D)

fclean		:	clean
			$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all debug leaks re clean fclean
