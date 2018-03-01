/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 12:20:14 by vsydorch          #+#    #+#             */
/*   Updated: 2017/07/19 17:04:04 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_burningship_continue(t_im *in, t_fract *fr)
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
		fr->new_c.r = mp(fr->old_c.r, 2) - mp(fr->old_c.i, 2) - fr->c.r;
		fr->new_c.i = 2 * fabs(fr->old_c.r * fr->old_c.i) + fr->c.i;
		fr->n++;
	}
}

void	ft_bio_continue(t_im *in, t_fract *fr)
{
	fr->new_c.i = (fr->y - fr->my) / (0.1 * in->zoom * H) + in->movey;
	fr->new_c.r = (fr->x - fr->mx) / (0.1 * in->zoom * W) + in->movex;
	fr->c.r = 0.11;
	fr->c.i = -0.65;
	fr->n = 0;
	while ((mp(fr->new_c.r, 2) + mp(fr->new_c.i, 2)) < in->max &&
		fr->n < in->iter)
	{
		fr->old_c = fr->new_c;
		fr->new_c.r = mp(fr->old_c.r, 4) - mp(fr->old_c.i, 4) - 6 *
		mp(fr->old_c.r, 2) * mp(fr->old_c.i, 2) + fr->c.r;
		fr->new_c.i = (4 * mp(fr->old_c.r, 3) * fr->old_c.i) -
		(4 * fr->old_c.r * mp(fr->old_c.i, 3)) + fr->c.i;
		fr->n++;
	}
}

void	ft_frog_continue(t_im *in, t_fract *fr)
{
	fr->new_c.i = (fr->y - fr->my) / (0.1 * in->zoom * H) + in->movey;
	fr->new_c.r = (fr->x - fr->mx) / (0.1 * in->zoom * W) + in->movex;
	fr->c.r = 0.11;
	fr->c.i = -0.65;
	fr->n = 0;
	while ((mp(fr->new_c.r, 2) + mp(fr->new_c.i, 2)) < in->max &&
		fr->n < in->iter)
	{
		fr->old_c = fr->new_c;
		fr->new_c.r = fabs(mp(fr->old_c.r, 2) - mp(fr->old_c.i, 2)) + fr->c.r;
		fr->new_c.i = (2 * fr->old_c.r * fr->old_c.i) + fr->c.i;
		fr->n++;
	}
}

void	ft_newton_continue(t_im *in, t_fract *fr)
{
	float		p;
	t_complex	d;

	fr->new_c.i = (fr->y - fr->my) / (0.1 * in->zoom * H) + in->movey;
	fr->new_c.r = (fr->x - fr->mx) / (0.1 * in->zoom * W) + in->movex;
	fr->n = 0;
	d = fr->new_c;
	while ((mp(fr->new_c.r, 2) + mp(fr->new_c.i, 2)) < in->max &&
		(mp(d.r, 2) + mp(d.i, 2)) < in->max && fr->n < in->iter)
	{
		fr->old_c = fr->new_c;
		p = mp((mp(fr->old_c.r, 2) + mp(fr->old_c.i, 2)), 2);
		fr->new_c.r = 2 * fr->old_c.r / 3 + (mp(fr->old_c.r, 2) -
		mp(fr->old_c.i, 2)) / (3 * p);
		fr->new_c.i = (2 * fr->old_c.i) * (1 - fr->old_c.r / p) / 3;
		d.r = fabs(fr->old_c.r - fr->new_c.r);
		d.i = fabs(fr->old_c.i - fr->new_c.i);
		fr->n++;
	}
}

void	ft_star_continue(t_im *in, t_fract *fr)
{
	float		p;
	t_complex	d;

	fr->new_c.i = (fr->y - fr->my) / (0.1 * in->zoom * H) + in->movey;
	fr->new_c.r = (fr->x - fr->mx) / (0.1 * in->zoom * W) + in->movex;
	fr->n = 0;
	d = fr->new_c;
	while ((mp(fr->new_c.r, 2) + mp(fr->new_c.i, 2)) < in->max &&
		(mp(d.r, 2) + mp(d.i, 2)) < in->max && fr->n < in->iter)
	{
		fr->old_c = fr->new_c;
		p = mp((mp(fr->old_c.r, 2) + mp(fr->old_c.i, 2)), 2);
		fr->new_c.r = 2 * fr->old_c.r / 3 + sin(mp(fr->old_c.r, 2) -
		mp(fr->old_c.i, 2)) / (3 * p);
		fr->new_c.i = (2 * fr->old_c.i) * tan(1 - fr->old_c.r / p) / 3;
		d.r = fabs(fr->old_c.r - fr->new_c.r);
		d.i = fabs(fr->old_c.i - fr->new_c.i);
		fr->n++;
	}
}
