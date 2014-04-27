/*
** xclose.c for  in /home/locque_d//rendu/proj/my_script/ESSAY/xfunc
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Sun Feb 27 12:44:14 2011 damien locque
** Last update Sun Feb 27 12:47:17 2011 damien locque
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../my_script.h"

int		xclose(int fd)
{
  int		ok;

  if ((ok = close(fd) == -1))
    {
      fprintf(stderr, "Close fail\n");
      exit(EXIT_FAILURE);
    }
  return (ok);
}
