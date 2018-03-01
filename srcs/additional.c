/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 13:21:50 by vsydorch          #+#    #+#             */
/*   Updated: 2017/07/07 15:25:54 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double		mp(float num, int pow)
{
	int		i;
	double	ans;

	ans = num;
	i = -1;
	while (++i < pow - 1)
		ans *= num;
	return (ans);
}

void		ft_color(t_im *in)
{
	int		i;
	float	f;
	int		red;
	int		green;
	int		blue;

	f = 0;
	i = 0;
	while (i < 126)
	{
		red = (-cos(f) + 1.0) * 127;
		green = (sin(f) + 1.0) * 127;
		blue = (cos(f) + 1.0) * 127;
		in->clr[i++] = red << 16 | green << 8 | blue;
		f += (in->cof_clr * M_PI / 126);
	}
}

void		ft_change_fr(t_im *in, int key)
{
	(key == 18) ? in->index_cf = 0 : 0;
	(key == 19) ? in->index_cf = 1 : 0;
	(key == 20) ? in->index_cf = 2 : 0;
	(key == 21) ? in->index_cf = 3 : 0;
	(key == 22) ? in->index_cf = 5 : 0;
	(key == 23) ? in->index_cf = 4 : 0;
	(key == 26) ? in->index_cf = 6 : 0;
	(key == 28) ? in->index_cf = 7 : 0;
	ft_fr_reinit(in);
	ft_reimage(in);
}

static void	ft_pxl_bg(int x, int y, int rgb, t_im *in)
{
	int				bitspp;
	int				slen;
	int				en;
	char			*image;
	unsigned int	tmp;

	image = mlx_get_data_addr(in->fgd, &bitspp, &slen, &en);
	tmp = (mlx_get_color_value(in->init, rgb));
	if (y > 0 && y < H && x > 0 && x < W)
		ft_memcpy((void *)(image + slen * y + x * sizeof(int)),
			(void *)&tmp, 4);
}

void		ft_create_bg(t_im *in)
{
	int		x;
	int		y;

	x = -1;
	while (++x <= W)
	{
		y = -1;
		while (++y <= H)
		{
			if ((x > 30 && x < 770) && (y == in->cf[0] + in->cf_m ||
				y == in->cf[1] + in->cf_m || y == in->cf[2] + in->cf_m ||
				y == in->cf[3] + in->cf_m || y == in->cf[4] + in->cf_m ||
				y == in->cf[5] + in->cf_m || y == in->cf[6] + in->cf_m ||
				y == in->cf[7] + in->cf_m))
				ft_pxl_bg(x, y, in->line, in);
			else
				ft_pxl_bg(x, y, in->bg, in);
		}
	}
}
