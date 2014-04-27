/*
** xattr.c for  in /home/locque_d//rendu/proj/my_script/ESSAY
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Sun Feb 27 14:07:21 2011 damien locque
** Last update Sun Feb 27 14:12:37 2011 damien locque
*/

#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include "../my_script.h"

int	xtcgetattr(int fd, struct termios *termios_p)
{
  int		ret;

  if ((ret = tcgetattr(fd, termios_p)) == -1)
    {
      fprintf(stderr, "tcgetattr fail\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}

int	xtcsetattr(int fd, int optional_actions,
	      const struct termios *termios_p)
{
  int		ret;

  if ((ret = tcsetattr(fd, optional_actions, termios_p)) == -1)
    {
      fprintf(stderr, "tcsetattr fail\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}

