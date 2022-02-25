/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:28:01 by iderighe          #+#    #+#             */
/*   Updated: 2022/02/11 13:17:27 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	ft_free_all(t_lst *lst)
{
	t_elm	*now;

	if (!lst)
		return (1);
	now = lst->head;
//	if (lst && lst->head)
//	{
		while (now->next != NULL)
		{
			now = now->next;
			free(now->prev);
		}
		free(now);
		free(lst);
//	}
	return (1);
}

int	ft_add_elm(t_lst *lst, char *s)
{
	t_elm	*elm;
//printf("On entre ici ?\n");
	elm = malloc(sizeof(*elm));
	if (elm == NULL)
		return (1);
	elm->tmp_arg = s;

/*	if (i == 1)
	{
		ls->head = elm;
		lst->tail = elm;
		elm->next = elm;
	}*/
//	else
//	{
	elm->prev = lst->tail;
	lst->tail->next = elm;
	lst->tail = elm;
//	}
	return (0);
}

t_lst	*ft_init_list_arg(int ac, char **av, t_lst *lst)
{
	int		i;
	t_elm	*elm;

	i = 1;
	lst = malloc(sizeof(*lst));
	if (lst == NULL)
	{
		free(lst);
		return (NULL);
	}
	elm = malloc(sizeof(*elm));
	if (elm == NULL)
	{
		free(elm);
		free(lst);
		return (NULL);
	}
/*	if (lst == NULL || elm == NULL)
	{
		if (elm != NULL)
			free(elm);
		if (lst != NULL)
			free(lst);
		perror("init list ");
		return (NULL);
	}*/
	lst->head = elm;
	lst->tail = elm;
	elm->tmp_arg = av[1];
	elm->next = NULL;
	elm->prev = NULL;
printf(RED"tmp_arg = [%s]"RESET"\n", elm->tmp_arg);
//	elm->next = adm->head;
//	elm->prev = lst->tail;
	while (++i < ac)
	{
		if (ft_add_elm(lst, av[i]))
			return (NULL);
//printf(RED"tmp_arg = [%s]"RESET"\n", elm->tmp_arg);
	}
/*while(elm->next)
{
printf(CYAN"tmp_arg = [%s]"RESET"\n", elm->tmp_arg);
elm = elm->next;
}*/
	return (lst);
}

int	main(int ac, char **av)
{
	char	*arg;
	int		i;
	int		j;
	t_lst	*lst;
//	DIR		*dir;
//	struct dirent	*file_en_cours;

//	dir = NULL;
/*	file_en_cours = NULL;
	dir = opendir("/usr/bin/");
	if (dir == NULL)
	{
		perror("Error ");
		return (1);
	}
	file_en_cours = readdir(dir);
	if (closedir(dir) == -1)
	{
		perror("Error ");
		return (1);
	}*/
	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '&' || av[i][j] == '\'' || av[i][j] == ';')
				return (1);
			j++;
		}
	}
	i = 0;
	while (++i < ac)
	{
		arg = readline(av[i]);
		add_history(av[i]);
printf(GREEN"ac = %d"RESET" | "RED"arg %d = [%s]"RESET"\n", ac, i, arg);
	}
	lst = NULL;
	lst = ft_init_list_arg(ac, av, lst);
	if (lst == NULL)
		return (ft_free_all(lst));
	ft_free_all(lst);
	return (0);
}
