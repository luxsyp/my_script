/*
** xsetsid.c for  in /home/locque_d//rendu/proj/my_script/ESSAY/xfunc
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Sun Feb 27 13:16:35 2011 damien locque
** Last update Sun Feb 27 13:17:08 2011 damien locque
*/

#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdio.h>
#include "../my_script.h"

pid_t		xsetsid(void)
{
  pid_t		ret;

  if ((ret = setsid()) == -1)
    {
      fprintf(stderr, "setsid fail\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}
