/*
** term.c for  in /home/locque_d//rendu/proj/my_script
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Thu Feb 24 17:33:40 2011 damien locque
** Last update Sun Feb 27 14:14:06 2011 damien locque
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_script.h"

struct termios 	desactive_echo()
{
  struct termios	old;
  struct termios	new;

  xtcgetattr(0, &old);
  new = old;
  new.c_lflag &= ~(ECHO | ICANON);
  xtcsetattr(0, TCSANOW, &new);
  return (old);
}

void		back_echo(struct termios old, int fd)
{
  xtcsetattr(fd, TCSANOW, &old);
}
