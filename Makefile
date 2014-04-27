##
## Makefile for  in /u/all/locque_d/cu/rendu/proj/malloc
##
## Made by damien locque
## Login   <locque_d@epitech.net>
##
## Started on  Mon Jan 31 22:57:43 2011 damien locque
## Last update Sun Feb 27 14:26:13 2011 damien locque
##

NAME	= my_script

SRCS	= my_openpty.c		\
	  my_init_pty.c		\
	  my_login_tty.c	\
	  write_time.c		\
	  parser.c		\
	  term.c		\
	  pty.c			\
	  main.c

XSRCS	= xfunc/xmalloc.c	\
	  xfunc/xwrite.c	\
	  xfunc/xioctl.c	\
	  xfunc/xsetsid.c	\
	  xfunc/xselect.c	\
	  xfunc/xattr.c		\
	  xfunc/xclose.c

OBJS	= $(SRCS:.c=.o)		\
	  $(XSRCS:.c=.o)

CC	= gcc
RM	= rm -f

CFLAGS	+= -W -Wall -Wextra -Werror
LDFLAGS = -lutil

.c.o	:
	$(CC) $(CFLAGS) -c $< -o $@

all	: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

clean	:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re	: fclean all
