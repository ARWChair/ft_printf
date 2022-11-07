SOURCES =	ft_printf.c	ft_printf_indi.c	ft_printf_hexa.c


OBJECTS =	$(SOURCES:.c=.o)

CC	=	cc
RM	=	rm -f
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libftprintf.a

all:	$(NAME)

$(NAME):
	$(CC)	$(CFLAGS)	-c	$(SOURCES)
	ar	rcs	$(NAME)	$(OBJECTS)

clean:
	$(RM)	$(OBJECTS)

fclean:	clean
	$(RM)	$(NAME)

re:	fclean	$(NAME)
