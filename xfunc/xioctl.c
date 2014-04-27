/*
** xioctl.c for  in /home/locque_d//rendu/proj/my_script/ESSAY/xfunc
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Sun Feb 27 13:01:33 2011 damien locque
** Last update Sun Feb 27 13:15:58 2011 damien locque
*/

#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdio.h>
#include "../my_script.h"

int		xioctl(int fd, int request, void * arg)
{
  int		ret;

  if ((ret = ioctl(fd, request, arg) == -1))
    {
      fprintf(stderr, "ioctl fail\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}
