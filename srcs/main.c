/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:25:50 by vsydorch          #+#    #+#             */
/*   Updated: 2017/07/19 16:20:35 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	void	show_list(char **fract)
{
	int		i;

	i = -1;
	ft_putendl("| # | Name of fract |");
	while (fract[++i])
	{
		ft_putstr(" [");
		ft_putstr(ft_itoa(i + 1));
		ft_putstr("]	");
		ft_putendl(fract[i]);
	}
	ft_putendl("Example: ./fractol Julia");
}

static	int		ft_check_list(char **fract, char *av)
{
	int		i;

	i = -1;
	while (fract[++i])
		if (ft_strcmp(fract[i], av) == 0)
			return (1);
	show_list(fract);
	exit(0);
	return (0);
}

static	void	ft_fill_names(char ***fract)
{
	(*fract)[0] = "Julia";
	(*fract)[1] = "Mandelbrot";
	(*fract)[2] = "Polikarp";
	(*fract)[3] = "BurningShip";
	(*fract)[4] = "Biomorph";
	(*fract)[5] = "Frog";
	(*fract)[6] = "Newton";
	(*fract)[7] = "Star";
	(*fract)[8] = NULL;
}

int				main(int ac, char **av)
{
	char	**fract;

	fract = (char **)malloc(sizeof(char *) * 9);
	ft_fill_names(&fract);
	if (ac < 2 || ac > 3)
		show_list(fract);
	else
	{
		if (ac == 2 && ft_check_list(fract, av[1]))
			one_fract(fract, av[1]);
		else
			show_list(fract);
	}
	free(fract);
	return (0);
}
