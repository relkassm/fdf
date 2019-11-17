/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:51:39 by relkassm          #+#    #+#             */
/*   Updated: 2019/11/15 16:53:45 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check(char *buff)
{
	t_map	xy;
	char	**lines;
	char	**line;

	xy.i = 0;
	while (buff[xy.i])
	{
		if (ft_isalnum(buff[xy.i]) == 0 && buff[xy.i] != ' '
				&& buff[xy.i] != ',' && buff[xy.i] != '\n' && buff[xy.i] != '-')
			return (0);
		xy.i++;
	}
	xy.x = count_width(buff);
	lines = ft_strsplit(buff, '\n');
	xy.i = 0;
	while (lines[xy.i])
	{
		line = ft_strsplit(lines[xy.i], ' ');
		xy.j = 0;
		while (line[xy.j])
			xy.j++;
		if ((xy.j) < xy.x)
			return (0);
		xy.i++;
	}
	return (1);
}

int		count_height(char *buff)
{
	int		i;
	char	**lines;

	i = 0;
	lines = ft_strsplit(buff, '\n');
	while (lines[i])
		i++;
	return (i);
}

int		count_width(char *buff)
{
	int		i;
	char	**lines;
	char	**fstline;

	i = 0;
	lines = ft_strsplit(buff, '\n');
	fstline = ft_strsplit(lines[0], ' ');
	while (fstline[i])
		i++;
	return (i);
}

int		**store(char *buff)
{
	char	**lines;
	char	**line;
	int		**table;
	t_map	xy;

	xy.i = 0;
	xy.x = count_width(buff);
	xy.y = count_height(buff);
	lines = ft_strsplit(buff, '\n');
	table = (int **)malloc(xy.y * sizeof(int *));
	while (lines[xy.i])
	{
		line = ft_strsplit(lines[xy.i], ' ');
		xy.j = 0;
		table[xy.i] = (int *)malloc(xy.x * sizeof(int));
		while (xy.j < xy.x)
		{
			table[xy.i][xy.j] = ft_atoi(line[xy.j]);
			xy.j++;
		}
		xy.i++;
	}
	return (table);
}

void	print(char *buff)
{
	int		**table;
	void	*mlx_ptr;
	void	*win_ptr;

	table = store(buff);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "fdf");
	
	mlx_loop(mlx_ptr);
}
