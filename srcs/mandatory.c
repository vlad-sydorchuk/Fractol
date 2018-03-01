/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 12:20:10 by vsydorch          #+#    #+#             */
/*   Updated: 2017/07/19 16:29:49 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_julia_continue(t_im *in, t_fract *fr)
{
	fr->new_c.r = (fr->x - fr->mx) / (0.1 * in->zoom * W) + in->movex;
	fr->new_c.i = (fr->y - fr->my) / (0.1 * in->zoom * H) + in->movey;
	fr->c.r = -0.7 + in->cof_jul;
	fr->c.i = 0.27015 + in->cof_jul;
	fr->n = 0;
	while ((mp(fr->new_c.r, 2) + mp(fr->new_c.i, 2)) < in->max &&
		fr->n < in->iter)
	{
		fr->old_c = fr->new_c;
		fr->new_c.r = mp(fr->old_c.r, 2) - mp(fr->old_c.i, 2) + fr->c.r;
		fr->new_c.i = 2 * fr->old_c.r * fr->old_c.i + fr->c.i;
		fr->n++;
	}
}

void	ft_mjb_continue(t_im *in, t_fract *fr)
{
	fr->c.i = (fr->y - fr->my) / (0.1 * in->zoom * H) + in->movey;
	fr->c.r = (fr->x - fr->mx) / (0.1 * in->zoom * W) + in->movex;
	fr->new_c.r = 0;
	fr->new_c.i = 0;
	fr->old_c.r = 0;
	fr->old_c.i = 0;
	fr->n = 0;
	while ((mp(fr->new_c.r, 2) + mp(fr->new_c.i, 2)) < in->max &&
		fr->n < in->iter)
	{
		fr->old_c = fr->new_c;
		fr->new_c.r = mp(fr->old_c.r, 2) - mp(fr->old_c.i, 2) + fr->c.r;
		fr->new_c.i = 2 * fr->old_c.r * fr->old_c.i + fr->c.i;
		fr->n++;
	}
}

void	ft_polikarp_continue(t_im *in, t_fract *fr)
{
	fr->new_c.r = (fr->x - fr->mx) / (0.1 * in->zoom * W) + in->movex;
	fr->new_c.i = (fr->y - fr->my) / (0.1 * in->zoom * H) + in->movey;
	fr->c.r = 0.11;
	fr->c.i = -0.65;
	fr->n = 0;
	while ((mp(fr->new_c.r, 2) + mp(fr->new_c.i, 2)) < in->max &&
		fr->n < in->iter)
	{
		fr->old_c = fr->new_c;
		fr->new_c.r = tan((mp(fr->old_c.r, 2) - mp(fr->old_c.i, 2)) + fr->c.r);
		fr->new_c.i = 2 * fr->old_c.r * fr->old_c.i + fr->c.i;
		fr->n++;
	}
}

void	ft_start_fr(t_im *in)
{
	t_fract		fr;

	ft_fractal_init(&fr);
	while (fr.y < H)
	{
		fr.x = 0;
		while (fr.x < W)
		{
			ft_continue_fr(in, &fr);
			if (fr.n < in->iter)
				ft_pxlimg(fr.x, fr.y, in->clr[fr.n], in);
			fr.x++;
		}
		fr.y++;
	}
}
