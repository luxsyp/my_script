/*
** pty.c for  in /home/locque_d//rendu/proj/my_script
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Thu Feb 24 19:25:24 2011 damien locque
** Last update Sun Feb 27 14:25:16 2011 damien locque
*/

#include <stdlib.h>
#include <unistd.h>
#include <pty.h>
#include <stdio.h>
#include <utmp.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "my_script.h"

void		father_pty(t_fd *fd, pid_t pid)
{
  int		rc;
  fd_set	set;
  int		status;
  char		buffer[BUFF_SIZE];

  xclose(fd->fds);
  FD_ZERO(&set);
  while (waitpid(pid, &status, WNOHANG) != pid)
    {
      FD_SET(0, &set);
      FD_SET(fd->fdm, &set);
      xselect((fd->fdm + 1), &set, NULL, NULL, NULL);
      if ((FD_ISSET(0, &set)
	   && (rc = read(0, buffer, BUFF_SIZE)) > 0))
	xwrite(fd->fdm, buffer, rc);
      if (FD_ISSET(fd->fdm, &set) &&
	  ((rc = read(fd->fdm, buffer, BUFF_SIZE)) > 0))
	{
	  xwrite(1, buffer, rc);
	  xwrite(fd->filefd, buffer, rc);
	}
    }
}

int		child_pty(t_fd *fd)
{
  int		ret;

  close(fd->fdm);
  my_login_tty(fd->fds);
  if (getenv("SHELL"))
    ret = execl(getenv("SHELL"), getenv("SHELL"), NULL);
  else
    ret = execl("/bin/tcsh", "tcsh", NULL);
  if (ret == -1)
    {
      fprintf(stderr, "exec fail\n");
      exit(EXIT_FAILURE);
    }
  exit(EXIT_SUCCESS);
}
