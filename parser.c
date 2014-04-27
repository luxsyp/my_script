/*
** parser.c for  in /home/locque_d//rendu/proj/my_script/ESSAY
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Sun Feb 27 12:37:30 2011 damien locque
** Last update Sun Feb 27 12:23:45 2011 damien locque
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "my_script.h"

void		parse_arg(int argc, char **argv, char *opt)
{
  int		c;

  (*opt) = 0;
  while ((c = getopt(argc, argv, "ac:fqt")) != -1)
    {
      if (c == 'a')
	(*opt) |= MASK_A;
      else if (c == 'c')
	(*opt) |= MASK_C;
      else if (c == 'f')
	(*opt) |= MASK_F;
      else if (c == 'q')
	(*opt) |= MASK_Q;
      else if (c == 't')
	(*opt) |= MASK_T;
      else
	{
	  fprintf(stderr,
		  "usage: script [-a] [-c COMMAND] [-f] [-q] [-t] [file]\n");
          exit(EXIT_FAILURE);
	}
    }
}

static void	change_name(char *src, char **dest)
{
  (*dest) = src;
}

void		check_file(int argc, char **argv, t_fd *fd)
{
  int		i;
  int		j;
  bool		flag;

  j = 1;
  i = 1;
  fd->fname = DEFAULT_NAME;
  while (i < argc)
    {
      flag = false;
      if (argv[i] && argv[i][0] != '-')
	{
	  if (argv[i] && argv[i - 1] && argv[i - 1][0] == '-')
	    {
	      while (argv[i - 1][j])
		if (argv[i - 1][j++] == 'c')
		  flag = true;
	      if (!flag)
		return (change_name(argv[i], &(fd->fname)));
	    }
	  else
	    return (change_name(argv[i], &(fd->fname)));
	}
      ++i;
    }
}

