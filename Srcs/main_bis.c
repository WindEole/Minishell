/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:31:27 by iderighe          #+#    #+#             */
/*   Updated: 2022/02/25 12:48:02 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*char	**ft_splitting(arg)
{
	return (split);
}*/

/*int	ft_insert_env(t_lev *lev, char *ev)
{
	t_env	*tev;
	char	**tab_ev;

int	j;

	tev = malloc(sizeof(*tev));
	if (tev == NULL)
		return (1);
	tab_ev = ft_split(ev, '=');

j = 0;
while (tab_ev[j])
{
//	k = 0;
//	while (tab_ev[j][k])
		printf(RED"tab_ev[%d] = [%s]"RESET"\n", j, tab_ev[j]);
		j++;
}

	tev->var = tab_ev[0];
	tev->def = tab_ev[1];
	free(tab_ev);
	lev->tail->next = tev;
	lev->tail = tev;
	return (0);
}

t_lev	*ft_recup_env(t_lev *lev, char **ev)
{
	t_env	*tev;
	char	**tab_ev;
	int		i;

	int		j;
//	int		k;

	tev = malloc(sizeof(*tev));
	if (tev == NULL)
	{
		free(tev);
		perror("malloc element d'environnement");
		return (NULL);
	}
	lev->head = tev;
	lev->tail = tev;
	tab_ev = ft_split(ev[0], '=');
j = 0;
while (tab_ev[j])
{
//	k = 0;
//	while (tab_ev[j][k])
		printf(RED"tab_ev[%d] = [%s]"RESET"\n", j, tab_ev[j]);
		j++;
}
	tev->var = tab_ev[0];
	tev->def = tab_ev[1];
	free(tab_ev);
	i = 0;
	while (ev[++i])
		if (ft_insert_env(lev, ev[i]))
			return (NULL); // ATTENTION Fct free !
	return (lev);
}*/

void	ft_recup_env(char **ev, t_pip *p)
{
	char	*tab_ev;
	int		s_ev;

	s_ev = 0;
	while (ev[s_ev])
		s_ev++;
	tab_ev = ft_strjoin_n(s_ev, ev);
	p->ev = ft_split(tab_ev, '\n');
	free(tab_ev);
}

int	main(int ac, char **av, char **ev)
{
	char	*arg;
	char	*prompt;
	int		i;
	int		quot1;
	int		quot2;
	t_pip	p;
//	t_lev	*lev;
//	char	**split;

	av = NULL;
/*	lev = malloc(sizeof(*lev));
	lev = ft_recup_env(lev, ev);
	if (lev == NULL)
	{
		perror("malloc liste d'environnement");
		return (1);
	}*/
	
	ft_recup_env(ev, &p);
//	ft_recup_env(p.ev);
	prompt = "minishell $> ";
	if (ac != 1)
	{
		errno = 2;
		perror("minishell");
		return (1);
	}
/*	p.i = -1;
	while (ev[++p.i])
		if (ev[p.i][0] == 'P' && ev[p.i][1] == 'A' && ev[p.i][2] == 'T'
			&& ev[p.i][3] == 'H' && ev[p.i][4] == '=')
			p.pth = ft_split_add(&ev[p.i][5], ':');
	if (p.pth == NULL)
		return (1);*/
	while (1)
	{
		i = 0;
		quot1 = 0;
		quot2 = 0;
		arg = readline(prompt);
		add_history(arg);
//		printf(RED"arg = [%s] | i = %d"RESET"\n", arg, i);
		while (arg[i])
		{
//			printf(YELLOW"[%c]"RESET"\n", arg[i]);
			if (arg[i] == '\'' && quot2 % 2 == 0)
				quot1++;
			if (arg[i] == '\"' && quot1 % 2 == 0)
				quot2++;
			i++;
		}
//		printf(GREEN"quot1 = [%d] | quot2 = [%d]"RESET"\n", quot1, quot2);
		if (quot1 % 2 != 0 || quot2 % 2 != 0)
			printf(CYAN"please verify your quotes !"RESET"\n");
		if (ft_strcmp(arg, "pwd") == 0)
			ft_pwd();
//		i = -1;
//		while (p.ev[++i])
//			printf(YELLOW"ev[%d] = [%s]"RESET"\n", i, p.ev[i]);
		if (ft_strncmp(arg, "unset", 5) == 0)
			ft_unset(&arg[6], &p);
		if (ft_strcmp(arg, "env") == 0)
			ft_env(&p);
		if (ft_strncmp(arg, "export", 6) == 0)
			ft_export(&arg[7], &p);
//		i = -1;
//		while (p.ev[++i])
//			printf(PURPLE"ev[%d] = [%s]"RESET"\n", i, p.ev[i]);
//		if (ft_strcmp(arg, "exit") == 0)
//			ft_exit();
/*		spl = ft_split(arg, ' ');
		i = -1;
		while (spl[++i])
			printf(YELLOW"spl[%d] = [%s]"RESET"\n", i, spl[i]);*/
	}
	free(p.ev);
	return (0);
}
