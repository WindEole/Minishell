/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:31:17 by iderighe          #+#    #+#             */
/*   Updated: 2022/02/25 12:25:56 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

////    ATTENTION : c'est du pseudo-code ! A modifier !    ////

int	ft_echo(char *s) // A lancer quand la commande est echo !
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (write(1, &s[i], 1) == -1)
		{
			perror("echo");
			return (-1);
		}
	}
//	if (!option -n)
		write(1, "\n", 1);
	return (0);
}

void	ft_cd(char *dirname, t_pip *p)
{
	char	*pathname;
	char	*buf;
	size_t	size;

	pathname = NULL;
	buf = NULL;
	size = 256;
	if (chdir(dirname) != 0)
	{
		perror("cd");
		return ;
	}
	pathname = getcwd(buf, size);
	if (pathname == NULL)
	{
		perror("pwd");
		return ;
	}
	ft_unset("PWD", p);
	ft_export(ft_strjoin("PWD=", pathname), p);
	return ;
}

void	ft_pwd(void)
{
	char	*pathname;
	char	*buf;
	size_t	size;

	pathname = NULL;
	buf = NULL;
	size = 256;
	pathname = getcwd(buf, size);
	if (pathname == NULL)
		perror("pwd");
	else
	{
		ft_putstr_fd(pathname, 1);
		write(1, "\n", 1);
	}
}

void	ft_export(char *s, t_pip *p)
{
	char	*tab_ev;
	int		s_ev;

	s_ev = 0;
	while (p->ev[s_ev])
		s_ev++;
	tab_ev = ft_strjoin_n(s_ev, p->ev);
	free(p->ev);
	tab_ev = ft_strjoin(tab_ev, "\n");
	tab_ev = ft_strjoin(tab_ev, s);
	p->ev = ft_split(tab_ev, '\n');
	free(tab_ev);
}

void	ft_unset(char *s, t_pip *p)
{
	int	i;

	i = 0;
	while (p->ev[i])
	{
printf(YELLOW"ev[%d] = [%s]"RESET"\n", i, p->ev[i]);
		if (strncmp(s, p->ev[i], ft_strlen(s)) == 0)
			p->ev[i] = NULL;
printf(PURPLE"ev[%d] = [%s]"RESET"\n", i, p->ev[i]);
		i++;
	}
}

void	ft_env(t_pip *p)
{
	int	i;

	i = -1;
	while (p->ev[++i])
		ft_putstr_fd(p->ev[i], 1);
}
