
/*

while (ttrs[n] != NULL)
{
	while (i < 4)
	{
		pos = ttrs[n]->pos[i].x;
		do_something(pos.x);
		do_something_else(pos.y + (something / 5));
		do_something_with_letter(ttrs[n]->letter);
		i++;
	}
	n++;
}

while (ttrs[n] != NULL)
{
	while (i < 4)
	{
		pos = ttrs[n]->pos[i].x;
		do_something(pos.x);
		do_something_else(pos.y + (something / 5));
		do_something_with_letter(n);
		i++;
	}
	n++;
}

while (ttrs[n] != NULL)
{
	while (i < 4)
	{
		do_something(ttrs[n]->pos[i].x);
		do_something_else(ttrs[n]->pos[i].y + (something / 5));
		do_something_with_letter(n);
		i++;
	}
	n++;
}

while (ttrs[n] != NULL)
{
	while (i < 4)
	{
		do_something(get_x_pos(ttrs, n, i));
		do_something_else(get_y_pos(ttrs, n, i) + (something / 5));
		do_something_with_letter(n);
		i++;
	}
	n++;
}
while (ttrs[n] != NULL)
{
	while (pos < 4)
	{
		coords = ttrs[n][pos];
		do_something(coords.x);
		do_something_else(coords.y + (something / 5));
		do_something_with_letter('A' + n);
		pos++;
	}
	n++;
}

*/

static void put_coord(t_coord coords)
{
	printf("(%d, %d)", coords.x, coords.y)
}

static void put_ttr(t_coord *ttr)
{
	int i;

	i = 0;
	ft_putstr('[');
	while (i < 4)
	{
		put_coord(ttr[i]);
		if (i < 3)
			ft_putchar(' ');
		i++;
	}
	ft_putstr(']');
}
