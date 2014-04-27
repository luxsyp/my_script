/*
** my_login_tty.c for  in /home/locque_d//rendu/proj/my_script
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Thu Feb 24 10:52:10 2011 damien locque
** Last update Sun Feb 27 13:18:25 2011 damien locque
*/

#include <unistd.h>
#include <sys/ioctl.h>
#include "my_script.h"

int		my_login_tty(int fds)
{
  xsetsid();
  xioctl(fds, TIOCSCTTY, NULL);
  dup2(fds, 0);
  dup2(fds, 1);
  dup2(fds, 2);
  return (0);
}
