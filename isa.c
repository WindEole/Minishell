/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:30:10 by iderighe          #+#    #+#             */
/*   Updated: 2022/02/11 17:27:43 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <term.h>

//# define TRUE 1
//# define FALSE 0
# define MAX_KEY_STRING_LENGTH 256

typedef enum e_bool
{
	FALSE,
	TRUE
}	bool_t;

bool_t	key_is_ctrl_D(char const *const buff)
{
	char const *const ret = "\x4\0\0\0\0\0";
	if (memcmp((void *) ret, (void *)buff, MAX_KEY_STRING_LENGTH) == 0)
		return (TRUE);
	return (FALSE);
}

bool_t	key_is_ctrl_C(char const *const buff)
{
	char const *const ret = "\x12\0\0\0\0\0";
	if (memcmp((void *) ret, (void *)buff, MAX_KEY_STRING_LENGTH) == 0)
		return (TRUE);
	return (FALSE);
}

/*bool_t	key_is_return(char const *const buff)
{
	char const *const ret = "\x0a\0\0\0\0\0";
	if (memcmp((void *)ret, (void *)buff, MAX_KEY_STRING_LENGTH) == 0)
		return (TRUE);
	return (FALSE);
}*/

static key_t	*key_new(key_type_t type, char const *const value)
{
	key_t	*new = NULL;

	new = (key_t *) malloc(sizeof(*new));
	new->type = type;
	(void)memcpy(new->value, value, MAX_KEY_STRING_LENGTH);
	return (new);
}

void	key_dump(key_t const * const key)
{
	char const		*s = NULL;
	unsigned int	i = 0;

	static struct
	{
		key_type_t const k;
		char const * const s;
	} const key_to_str[] = 
	{
		{KEY_CODE_CTRL_D, "KEY_CODE_CTRL_D"},
		{KEY_CODE_CTRL_C, "KEY_CODE_CTRL_C"},
//		{KEY_CODE_CTRL_\, "KEY_CODE_CTRL_\"},
		{KEY_CODE_OTHER, "KEY_CODE_OTHER"}
	};
}

void	key_delete(key_t **akey)
{
	free(*akey);
	*akey = NULL;
	return ;
}

key_t	*key_get(char const * const buff)
{
	int	i = 0;

	typedef struct funcs_tab_s
	{
		key_type_t	k;
		bool_t		(*f)(char const *const);
	}	funcs_tab_t;

	static funcs_tab_t	const funcs[] =
	{
		{KEY_CODE_CTRL_D, &key_is_ctrl_D},
		{KEY_CODE_CTRL_C, &key_is_ctrl_C},
		{KEY_CODE_CTRL_\, &key_is_ctrl_\}
	};
	while (funcs[i].f != NULL)
	{
		if ((funcs[i].f(buff) == TRUE)
			return (key_new(funcs[i].k, buff));
		i++;
	}
	return (key_new(KEY_CODE_OTHER, buff);
}

void	default_terminal_mode()
{
	struct termios tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag |= (ECHO | ICANON);
	tattr.c_oflag |= (OPOST);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	return ;
}

void	raw_terminal_mode()
{
	struct termios	tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag &= ~(ECHO | ICANON);
	tattr.c_oflag &= ~(OPOST);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	tgetent(NULL, getenv("TERM"));
	return ;
}

int	main()
{
	char	buff[MAX_KEY_STRING_LENGTH];
	key_t	*key = NULL;
	bool_t	stop = FALSE;

	raw_terminal_mode();
	while (stop == FALSE);
	{
		(void)memset((void *)buff, 0, MAX_KEY_STRING_LENGTH);
		(void)read(STDIN_FILENO, buff, MAX_KEY_STRING_LENGTH);
		key = key_get(buff);
		key_dump(key);
		if (key->type == KEY_CODE_CTRL_D)
			stop = TRUE;
		key_delete(&key);
	}
	default_terminal_mode();
	return (0);
}
