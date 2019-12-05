/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:09:09 by relkassm          #+#    #+#             */
/*   Updated: 2019/11/25 15:45:43 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_height(char *buff)
{
	int		i;
	char	**lines;

	i = 0;
	lines = ft_strsplit(buff, '\n');
	while (lines[i])
		i++;
	free_table(lines);
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
	free_table(lines);
	free_table(fstline);
	return (i);
}

int		char_check(char x)
{
	if (ft_isalnum(x) == 0 && x != ' ' &&\
			x != ',' && x != '\n' && x != '-')
		return (0);
	return (1);
}

int		check(char *buff, t_map xy)
{
	xy.i = -1;
	while (buff[++xy.i])
	{
		if (char_check(buff[xy.i] == 0))
			return (0);
	}
	xy.x = count_width(buff);
	xy.lines = ft_strsplit(buff, '\n');
	xy.i = -1;
	while (xy.lines[++xy.i])
	{
		xy.line = ft_strsplit(xy.lines[xy.i], ' ');
		xy.j = 0;
		while (xy.line[xy.j])
			xy.j++;
		free_table(xy.line);
		if ((xy.j) < xy.x)
		{
			free_table(xy.lines);
			return (0);
		}
	}
	free_table(xy.lines);
	return (1);
}

int		check_empty(char *buff)
{
	int		i;
	int		j;
	int		z;

	j = 0;
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			j++;
		i++;
	}
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		if (buff[i] > 32 && buff[i] < 127)
			break ;
		else
			i++;
	}
	if (buff[i] > 32 && buff[i] < 127)
		return (j > count_height(buff) ? 0 : 1);
	ft_putendl("No Data");
	exit(0);
}
