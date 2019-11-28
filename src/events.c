/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:17:03 by relkassm          #+#    #+#             */
/*   Updated: 2019/11/28 15:46:56 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_press(int b, int x, int y, t_win *w)
{
	if (b == 4)
		w->zm = w->zm + 4;
	if (b == 5 && w->zm > 1)
		w->zm = w->zm - 4;
	if (b == 1)
		w->m = !w->m;
	w->xk = x - 322 - w->x;
	w->yk = y - w->y;
	ft_bzero(w->img_data, w->winx * w->winy * 4);
	drawmap(w->buff, w->table, w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 322, 0);
	return (0);
}

int		mouse_move(int x, int y, t_win *w)
{
	if (w->m == 1)
	{
		w->x = x - 322 - w->xk;
		w->y = y - w->yk;
		ft_bzero(w->img_data, w->winx * w->winy * 4);
		drawmap(w->buff, w->table, w);
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 322, 0);
	}
	return (0);
}

void	keypart(int key, t_win *w, int *a)
{
	if (key == 34)
		w->pr = w->pr * -1;
	else if (key == 12)
		w->m = !w->m;
	else if (key == 7 && w->zm > 1)
		w->zm = w->zm - 1;
	else if (key == 124)
		w->x = w->x + 10;
	else if (key == 125)
		w->y = w->y + 10;
	else if (key == 123)
		w->x = w->x - 10;
	else if (key == 126)
		w->y = w->y - 10;
	else
		*a = 1;
}

int		keypress(int key, t_win *w)
{
	int a;

	a = 0;
	if (key == 13)
		w->jj = 1 - w->jj;
	else if (key == 6)
		w->zm = w->zm + 1;
	else if (key == 0)
		w->z = w->z + 1;
	else if (key == 1)
		w->z = w->z - 1;
	else if (key == 53)
		exit(0);
	else
		keypart(key, w, &a);
	if (a == 0)
	{
		ft_bzero(w->img_data, w->winx * w->winy * 4);
		drawmap(w->buff, w->table, w);
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 322, 0);
	}
	return (0);
}

void	drawmenu(t_win *w)
{
	drawrect(w, 322, 800, 0x4d80e4);
	drawrect(w, 322, 700, 0x5e8ce6);
	drawrect(w, 322, 600, 0x7099e9);
	drawrect(w, 322, 500, 0x82a6ec);
	drawrect(w, 322, 400, 0x94b2ee);
	drawrect(w, 322, 300, 0xa6bff1);
	drawrect(w, 322, 200, 0xb7ccf4);
	drawrect(w, 322, 100, 0x4573CD);
	mlx_string_put(w->mlx_ptr, w->win_ptr,\
			322 / 2 - 40, 40, 0xFFFFFF, "Fdf Menu");
	mlx_string_put(w->mlx_ptr, w->win_ptr,\
			20, 140, 0x4d80e4, "Arrow : Move The Map.");
	mlx_string_put(w->mlx_ptr, w->win_ptr,\
			20, 240, 0x5e8ce6, "Z / X : Zoom In / Out.");
	mlx_string_put(w->mlx_ptr, w->win_ptr,\
			20, 440, 0x4573CD, "A / S : In / Decrease Z Value.");
	mlx_string_put(w->mlx_ptr, w->win_ptr,\
			20, 620, 0xa6bff1, "I     : Switch Between");
	mlx_string_put(w->mlx_ptr, w->win_ptr,\
			20, 640, 0xa6bff1, "        Projections.");
	mlx_string_put(w->mlx_ptr, w->win_ptr,\
			20, 720, 0xb7ccf4, "W     : Switch Between");
	mlx_string_put(w->mlx_ptr, w->win_ptr,\
			20, 740, 0xb7ccf4, "        Projections.");
}
