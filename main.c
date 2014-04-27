/*
** tp2.c for  in /home/locque_d//rendu/proj/my_script
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Wed Feb 23 16:22:24 2011 damien locque
** Last update Sun Feb 27 12:47:36 2011 damien locque
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "my_script.h"

int		main(int argc, char **argv)
{
  t_fd		fd;
  pid_t		pid;
  struct termios old;

  check_file(argc, argv, &fd);
  parse_arg(argc, argv, &(fd.opt));
  if (!(fd.opt & MASK_Q))
    printf("Script started, file is %s\n", fd.fname);
  my_init_pty(&fd, true);
  if ((pid = fork()) < 0)
    exit(EXIT_FAILURE);
  if (!pid)
    child_pty(&fd);
  old = desactive_echo();
  father_pty(&fd, pid);
  write_time(fd.filefd, false);
  back_echo(old, fd.fdm);
  xclose(fd.filefd);
  if (!(fd.opt & MASK_Q))
    printf("Script done, file is %s\n", fd.fname);
  return (0);
}
