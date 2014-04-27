/*
** xselect.c for  in /home/locque_d//rendu/proj/my_script/ESSAY
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Sun Feb 27 13:49:53 2011 damien locque
** Last update Sun Feb 27 13:52:56 2011 damien locque
*/

#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../my_script.h"

int	xselect(int nfds, fd_set *readfds, fd_set *writefds,
	   fd_set *exceptfds, struct timeval *timeout)
{
  int	ret;

  if ((ret = select(nfds, readfds, writefds, exceptfds, timeout)) == -1)
    {
      fprintf(stderr, "select fail");
      exit(EXIT_FAILURE);
    }
  return (ret);
}
