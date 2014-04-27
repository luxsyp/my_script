/*
** xwrite.c for  in /home/locque_d//rendu/proj/my_script/ESSAY/xfunc
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Sun Feb 27 12:51:42 2011 damien locque
** Last update Sun Feb 27 14:02:01 2011 damien locque
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../my_script.h"

size_t		xwrite(int fd, void *buff, size_t nbytes)
{
  int		nb_read;

  if ((nb_read = write(fd, buff, nbytes)) == -1)
    {
      fprintf(stderr, "Can't write\n");
      exit(EXIT_FAILURE);
    }
  return ((size_t)nb_read);
}

