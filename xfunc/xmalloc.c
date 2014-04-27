/*
** xmalloc.c for xmalloc in /u/all/locque_d/cu/rendu/lem-in
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Mon Apr 12 12:44:38 2010 damien locque
** Last update Sun Feb 27 13:12:04 2011 damien locque
*/

#include <stdlib.h>
#include <stdio.h>
#include "../my_script.h"

void		*xmalloc(size_t size)
{
  void		*str;

  if (!(str = malloc(size)))
    {
      fprintf(stderr, "Malloc fail\n");
      exit(EXIT_FAILURE);
    }
  return (str);
}

