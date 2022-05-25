/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buil_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:07:26 by iderighe          #+#    #+#             */
/*   Updated: 2022/05/21 14:07:54 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_aff_export(t_adm *adm, char **e)
{
	int		i;
	t_env	*ev;

	i = -1;
	while (e[++i])
	{
		ev = adm->envh;
		while (ev != NULL)
		{
			if (!ft_strncmp(ev->var, e[i], (ft_strchr('=', e[i]) - &e[i][0])))
				break ;
			ev = ev->next;
		}
		write(1, "export ", 7);
		write(1, ev->var, ft_strlen(ev->var));
		write(1, "=\"", 2);
		write(1, ev->val, ft_strlen(ev->val));
		write(1, "\"\n", 2);
	}
}

int	ft_export_alpha(t_adm *adm)
{
	char	**ev;
	char	*swap;
	int		i;
	int		j;

	ev = adm->ev;
	swap = NULL;
	i = -1;
	j = 0;
	while (ev[++i])
	{
		j = i + 1;
		while (ev[j])
		{
			if (ft_strcmp(ev[i], ev[j]) > 0)
			{
				swap = ev[i];
				ev[i] = ev[j];
				ev[j] = swap;
			}
			j++;
		}
	}
	ft_aff_export(adm, ev);
	return (0);
}

void	ft_export_exist(t_adm *adm, char *s)
{
	t_env	*ev;

	ev = adm->envh;
	while (ev != NULL)
	{
		if (!ft_strncmp(ev->var, s, (ft_strchr('=', s) - &s[0])))
		{
			ft_unset(ev->var, adm);
			break ;
		}
		ev = ev->next;
	}
}

void	ft_export_bis(t_adm *adm, char *var)
{
	t_env	*ev;

	ev = adm->envh;
	while (ev != NULL)
	{
		if (ft_strchr('=', var))
		{
			if (var[0] == '=')
			{
				write(1, &EKONVEU, 34);
				return ;
			}
			ft_create_ev(adm, var);
			break ;
		}
		ev = ev->next;
	}
}

int	ft_export(char *s, t_adm *adm)
{
	int		i;
	char	**vars;

	vars = ft_split_lib(s, ' ');
	if (vars == NULL)
		return (-1);
	i = -1;
	while (vars && vars[++i])
	{
		if (vars[i][0] >= '0' && vars[i][0] <= '9')
			return (ft_free_split(vars), write(1, &EKONVEU, 34), 0);
		ft_export_exist(adm, vars[i]);
		ft_export_bis(adm, vars[i]);
	}
	return (ft_free_split(vars), 0);
}
