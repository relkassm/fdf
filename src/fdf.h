/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:38:35 by relkassm          #+#    #+#             */
/*   Updated: 2019/11/27 14:00:36 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# define BUFF_SIZE 6000000

typedef struct		s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;
	int		x;
	int		y;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		winx;
	int		winy;
	int		zm;
	char	*buff;
	int		**table;
	int		pr;
	int		z;
	int		rx;
	int		mx;
	int		my;
	int		hi;
	int		wi;
	int		jj;
	int		bpp;
	int		size_line;
	int		endian;
	char	*img_data;
	int		lr;
}					t_win;

typedef struct		s_map
{
	int		x;
	int		y;
	int		i;
	int		j;
	char	**lines;
	char	**line;
}					t_map;

int					char_check(char x);
int					check(char *buff);
int					count_height(char *buff);
int					count_width(char *fstline);
int					**store(char *buff);
void				free_table(char **table);
void				free_tablie(int **table, int y);
void				print(char *buff);
static void			rotation(int *x, int *y, int *z, t_win *w);
void				keypart(int key, t_win *w, int *a);
int					keypress(int key, t_win *w);
void				line(t_win *w, int cl);
static void			putimagein(int x, int y, int color, t_win *w);
void				iso(int *x, int *y, int z, t_win *w);
void				drawmap(char *buff, int **t, t_win *w);
void				drawlandd(int i, int j, t_win *w, int **t);
#endif
