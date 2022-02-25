/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:14:56 by iderighe          #+#    #+#             */
/*   Updated: 2022/02/25 12:24:58 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <term.h> //tgetent tgetflag tgetnum tgetstr tgoto tputs
# include <fcntl.h> //open
# include <stdio.h> //printf
# include <errno.h>
# include <unistd.h> //write access read close exit getcwd chdir unlink execve dup dup2 pipe isatty ttyname ttyslot
# include <stdlib.h> //malloc free getenv
# include <string.h> //strerror
# include <dirent.h> //opendir readdir closedir
# include <signal.h> //signal sigaction kill
# include <curses.h> //tgetent tgetflag tgetnum tgetstr tgoto tputs
# include <termios.h> //tcsetattr tcgetattr
# include <sys/wait.h> //wait waitpid
# include <sys/stat.h> //stat lstat fsqtat
# include <sys/time.h>
# include <sys/types.h> //fork opendir
# include <sys/ioctl.h> //ioctl
# include <sys/resource.h> //wait3 wait4
# include <readline/history.h> //readline to add_history
# include <readline/readline.h> //readline to add_history
# include "../Libft/libft.h"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"

typedef struct s_env
{
	char			*var;
	char			*def;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef struct s_lev
{
	struct s_env	*head;
	struct s_env	*tail;
}	t_lev;

typedef struct s_pip
{
	char	**pth;
//	char	**av;
	char	**ev;
//	char	**dir;
//	char	**exe1;
//	char	**exe2;
//	char	*cmd1;
//	char	*cmd2;
	int		i;
//	int		end[2];
//	int		pid[2];
//	int		fdo[2];
}	t_pip;

/*typedef struct s_elm
{
	char			*tmp_arg;
	struct s_elm	*next;
	struct s_elm	*prev;
}	t_elm;

typedef struct s_lst
{
	struct s_elm	*head;
	struct s_elm	*tail;
}	t_lst;*/

/////     builtin.c     /////

int		ft_echo(char *s);
void	ft_cd(char *dirname, t_pip *p);
void	ft_pwd(void);
void	ft_export(char *s, t_pip *p);
void	ft_unset(char *s, t_pip *p);
void	ft_env(t_pip *p);
//void	ft_exit(void);

#endif
