/*
** my_init_pty.c for  in /home/locque_d//rendu/proj/my_script
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Thu Feb 24 18:47:44 2011 damien locque
** Last update Sun Feb 27 13:25:22 2011 damien locque
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "my_script.h"

int		my_init_pty(t_fd *fd, bool term)
{
  if (term && my_openpty(&(fd->fdm), &(fd->fds)) == -1)
    {
      fprintf(stderr, "openpty fail\n");
      exit(EXIT_FAILURE);
    }
  if (fd->opt & MASK_A)
    fd->filefd = open(fd->fname, (O_CREAT | O_APPEND | O_RDWR), 0644);
  else
    fd->filefd = open(fd->fname, (O_CREAT | O_TRUNC | O_RDWR), 0644);
  if (fd->filefd == -1)
    {
      fprintf(stderr, "open fail");
      exit(EXIT_FAILURE);
    }
  write_time(fd->filefd, true);
  return (0);
}
