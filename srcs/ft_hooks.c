/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:46:45 by vsydorch          #+#    #+#             */
/*   Updated: 2017/07/17 14:00:16 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_hook(int key, t_im *in)
{
	if (key == 124)
		in->movex -= 0.02 / in->zoom;
	if (key == 123)
		in->movex += 0.02 / in->zoom;
	if (key == 126)
		in->movey += 0.02 / in->zoom;
	if (key == 125)
		in->movey -= 0.02 / in->zoom;
	(key == 6) ? in->cof_clr += 1 : 0;
	(key == 7) ? in->cof_clr -= 1 : 0;
	(key == 6 || key == 7) ? ft_color(in) : 0;
	ft_reimage(in);
	return (0);
}

int		ft_change_jul(int x, int y, t_im *in)
{
	if (x >= 0 && y >= 0 && x <= W && y <= H && in->flag_jul % 2 == 1)
	{
		in->ms[0] = x;
		mlx_destroy_image(in->init, in->img);
		in->img = mlx_new_image(in->init, W, H);
		if (in->ms[0] > in->ms[1] && in->cof_jul < 1)
			in->cof_jul += 0.02;
		else if (in->ms[0] < in->ms[1] && in->cof_jul > -1)
			in->cof_jul -= 0.02;
		ft_reimage(in);
		in->ms[1] = in->ms[0];
	}
	return (1);
}

int		ft_key_hook(int key, t_im *in)
{
	static int	flag_i = 0;

	(key == 53) ? exit(0) : 0;
	if (key == 12 && in->index_cf == 0 && in->info == 0)
	{
		in->flag_jul++;
		if (in->flag_jul % 2 == 1)
			mlx_hook(in->win, 6, 1L << 6, ft_change_jul, in);
	}
	((key >= 18 && key <= 23) ||
		key == 26 || key == 28) ? ft_change_fr(in, key) : 0;
	(key == 31 && in->iter < 126) ? in->iter += 5 : 0;
	(key == 34 && in->iter > 26) ? in->iter -= 5 : 0;
	(key == 40 && in->max < 18) ? in->max += 2 : 0;
	(key == 38 && in->max > 4) ? in->max -= 2 : 0;
	if (key == M)
	{
		flag_i++;
		if (flag_i % 2 == 1)
			in->info = 1;
		else
			in->info = 0;
	}
	(in->info == 1) ? ft_info(in) : ft_reimage(in);
	return (0);
}

int		ft_exit(void *t)
{
	if (!t)
		exit(0);
	return (0);
}

int		ft_mouse_hook(int key, int x, int y, t_im *in)
{
	if ((key == 4 || key == 5) && in->info == 1)
	{
		(key == 4) ? in->cf_m -= 25 : 0;
		(key == 5) ? in->cf_m += 25 : 0;
		ft_create_bg(in);
		ft_info(in);
	}
	if ((key == 4 || key == 5) && in->info == 0)
	{
		x -= W / 2;
		y -= H / 2;
		in->movex += x / in->zoom / W * 10;
		in->movey += y / in->zoom / H * 10;
		(key == 5) ? in->zoom *= 1.1 : 0;
		(key == 4) ? in->zoom /= 1.1 : 0;
		in->movex -= x / in->zoom / W * 10;
		in->movey -= y / in->zoom / H * 10;
		ft_reimage(in);
	}
	return (0);
}
