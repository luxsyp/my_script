/*
** my_init_pty.c for  in /home/locque_d//rendu/proj/my_script
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Thu Feb 24 18:00:51 2011 damien locque
** Last update Sun Feb 27 13:20:50 2011 damien locque
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_script.h"

static void	my_unlockpt(int fd)
{
  int		tmp;

  tmp = 0;
  xioctl(fd, TIOCSPTLCK, &tmp);
}

static char *	my_ptsname(int fd)
{
  int		tmp;
  char		*str;

  tmp = 0;
  str = xmalloc(18 * sizeof(*str));
  memset(str, '\0', 18);
  xioctl(fd, TIOCGPTN, &tmp);
  sprintf(str, "/dev/pts/%i", tmp);
  return (str);
}

int		my_openpty(int *fdm, int *fds)
{

  (*fdm) = open("/dev/ptmx", O_RDWR);
  if  ((*fdm) == -1)
    return (-1);
  my_unlockpt(*fdm);
  (*fds) = open(my_ptsname((*fdm)), O_RDWR);
  if ((*fds) == -1)
    return (-1);
  return (0);
}
