/*
** my_script.h for  in /home/locque_d//rendu/proj/my_script
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Thu Feb 24 17:29:02 2011 damien locque
** Last update Sun Feb 27 14:27:06 2011 damien locque
*/

#ifndef __MY_SCRIPT_H__
#define __MY_SCRIPT_H__

#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <stdbool.h>
#include <sys/time.h>

#define MASK_A 1	// 0x00000001
#define MASK_C 2	// 0x00000010
#define MASK_F 4	// 0x00000100
#define MASK_Q 8	// 0x00001000
#define MASK_T 16	// 0x00010000
#define BUFF_SIZE 64
#define DEFAULT_NAME "typescript"

typedef struct	s_fd
{
  int		fdm;
  int		fds;
  int		filefd;
  char		opt;
  char		*fname;
} t_fd;

char		*ptsname(int fd);
struct termios	desactive_echo();
int		my_init_pty(t_fd *fd, bool term);
int		my_login_tty(int fds);
int		my_openpty(int *fdm, int *fds);
void		back_echo(struct termios old, int fd);
int		write_time(int fd, bool b);
int		child_pty(t_fd *fd);
void		father_pty(t_fd *fd, pid_t pid);
void		parse_arg(int argc, char **argv, char *opt);
void		check_file(int argc, char **argv, t_fd *fd);

/* xfunc */
void		*xmalloc(size_t size);
size_t		xwrite(int fd, void *buff, size_t nbytes);
int		xclose(int fd);
int		xioctl(int fd, int request, void * arg);
pid_t		xsetsid(void);
int		xselect(int nfds, fd_set *readfds, fd_set *writefds,
		fd_set *exceptfds, struct timeval *timeout);
int		xtcgetattr(int fd, struct termios *termios_p);
int		xtcsetattr(int fd, int optional_actions,
			   const struct termios *termios_p);

#endif /* !__MY_SCRIPT_H__ */
