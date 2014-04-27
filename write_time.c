/*
** write_time.c for  in /home/locque_d//rendu/proj/my_script
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Thu Feb 24 19:20:34 2011 damien locque
** Last update Sun Feb 27 12:23:38 2011 damien locque
*/

#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "my_script.h"

int		write_time(int fd, bool b)
{
  char		buffer[512];
  time_t	timestamp;

  memset(buffer, '0', 512);
  timestamp = time(NULL);
  strftime(buffer, sizeof(buffer),
	   "%a %d %b %Y %X %p %Z\n", localtime(&timestamp));
  if (b)
    {
      xwrite(fd, "Script started on ", 18);
      xwrite(fd, buffer, strlen(buffer));
      return (0);
    }
  xwrite(fd, "\nScript done on ", 16);
  xwrite(fd, buffer, strlen(buffer));
  return (0);
}

