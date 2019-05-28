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

	if (n >= 0x10000)
		return (NULL);
	i = 0;
	str = (char*)ft_memalloc(sizeof(char) * (CHARS_IN_LINE + 1));
	ft_memset(str, '.', CHARS_IN_LINE);
	while (i < CHARS_IN_LINE)
	{
		if (is_newline_pos(i))
			str[i] = '\n';
		else if (is_toggled(n, i - (i / 5)))
			str[i] = '#';
		i++;
	}
	n++;
	return (str);
}

int				main(void)
{
	char	**str;
	int		i;
	int		j;

	str = (char**)malloc(sizeof(char*) * 2);
	str[1] = NULL;
	str[0] = input_gen();
	i = 0;
	j = 0;
	while (str[0] != NULL)
	{
		i++;
		if (validate_input(str))
		{
			ft_putstr(str[0]);
			j++;
		}
		free(str[0]);
		str[0] = input_gen();
	}
	ft_putnbr(i);
	ft_putchar('\n');
	ft_putnbr(j);
	return (0);
}
