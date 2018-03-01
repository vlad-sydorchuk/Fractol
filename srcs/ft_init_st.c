/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_st.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 14:05:42 by vsydorch          #+#    #+#             */
/*   Updated: 2017/07/02 14:05:47 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_fractal_init(t_fract *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->n = 0;
	fractal->mx = W / 2;
	fractal->my = H / 2;
}

static void	ft_fr_init_more(t_im *in)
{
	in->flag_jul = 0;
	in->cof_jul = 0;
	in->ms[0] = 0;
	in->ms[1] = 400;
	in->cf_m = 0;
	in->cf[0] = 40;
	in->cf[1] = 140;
	in->cf[2] = 300;
	in->cf[3] = 410;
	in->cf[4] = 490;
	in->cf[5] = 595;
	in->cf[6] = 720;
	in->cf[7] = 820;
	ft_create_bg(in);
}

void		ft_fr_init(t_im *in, char **fracts)
{
	in->init = mlx_init();
	in->win = mlx_new_window(in->init, W, H, "Fract'ol");
	in->img = mlx_new_image(in->init, W, H);
	in->fgd = mlx_new_image(in->init, W, H);
	in->bg = 0x333230;
	in->line = 0xFF7373;
	in->fracts = fracts;
	in->zoom = 1;
	in->movex = 0;
	in->movey = 0;
	in->iter = 126;
	in->max = 16;
	in->fw_iter = 0;
	in->fw_max = 0;
	in->info = 0;
	in->cof_clr = 2;
	ft_color(in);
	ft_fr_init_more(in);
}

void		ft_fr_reinit(t_im *in)
{
	in->zoom = 1;
	in->movex = 0;
	in->movey = 0;
	in->iter = 126;
	in->max = 16;
	in->fw_iter = 0;
	in->fw_max = 0;
	in->info = 0;
	in->cof_clr = 2;
	in->flag_jul = 0;
	in->cof_jul = 0;
	in->ms[0] = 400;
	in->ms[1] = 400;
	in->cf_m = 0;
}
