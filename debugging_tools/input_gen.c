#include "../fillit.h"

static int		is_newline_pos(int pos)
{
	return ((((pos + 1) % 5 == 0) || pos == 20) ? TRUE : FALSE);
}

static int		is_toggled(int stock, int pos)
{
	return (stock & (1 << pos));
}

static char		*input_gen()
{
	static int	n;
	int			i;
	char		*str;

	i = 0;
	str = (char*)ft_memalloc(sizeof(char) * (CHARS_IN_LINE + 1));
	ft_memset(str, '.', CHARS_IN_LINE);
	if (n > 0x10)
		return (NULL);
	while (i < CHARS_IN_LINE)
	{
		if (is_newline_pos(i))
			str[i] = '\n';
		else if (is_toggled(n, i))
			str[i] = '#';
		i++;
	}
	n++;
	return (str);
}

int				main(void)
{
	char	*str;

	str = input_gen();
	while (str != NULL)
	{
		ft_putstr(str);
		free(str);
		str = input_gen();
	}
	return (0);
}
