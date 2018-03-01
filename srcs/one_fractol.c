/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_fractol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 12:52:46 by vsydorch          #+#    #+#             */
/*   Updated: 2017/07/19 12:40:05 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_reimage(t_im *in)
{
	mlx_destroy_image(in->init, in->img);
	in->img = mlx_new_image(in->init, W, H);
	ft_start_fr(in);
	mlx_clear_window(in->init, in->win);
	mlx_put_image_to_window(in->init, in->win, in->img, 0, 0);
	if (in->info == 1)
		ft_info(in);
}

void	ft_pxlimg(int x, int y, int rgb, t_im *in)
{
	int				bitspp;
	int				slen;
	int				en;
	char			*image;
	unsigned int	tmp;

	image = mlx_get_data_addr(in->img, &bitspp, &slen, &en);
	tmp = (mlx_get_color_value(in->init, rgb));
	if (y > 0 && y < H && x > 0 && x < W)
		ft_memcpy((void *)(image + slen * y + x * sizeof(int)),
			(void *)&tmp, 4);
}

void	ft_continue_fr(t_im *in, t_fract *fr)
{
	(in->index_cf == 0) ? ft_julia_continue(in, fr) : 0;
	(in->index_cf == 1) ? ft_mjb_continue(in, fr) : 0;
	(in->index_cf == 2) ? ft_polikarp_continue(in, fr) : 0;
	(in->index_cf == 3) ? ft_burningship_continue(in, fr) : 0;
	(in->index_cf == 4) ? ft_bio_continue(in, fr) : 0;
	(in->index_cf == 5) ? ft_frog_continue(in, fr) : 0;
	(in->index_cf == 6) ? ft_newton_continue(in, fr) : 0;
	(in->index_cf == 7) ? ft_star_continue(in, fr) : 0;
}

void	one_fract(char **fracts, char *cur_fract)
{
	int		i;
	t_im	*in;

	in = (t_im *)malloc(sizeof(t_im));
	i = -1;
	while (++i < 8)
		if (ft_strcmp(cur_fract, fracts[i]) == 0)
			break ;
	in->index_cf = i;
	ft_fr_init(in, fracts);
	ft_start_fr(in);
	mlx_put_image_to_window(in->init, in->win, in->img, 0, 0);
	mlx_mouse_hook(in->win, ft_mouse_hook, in);
	mlx_key_hook(in->win, ft_key_hook, in);
	mlx_hook(in->win, 2, 5, ft_hook, in);
	mlx_hook(in->win, 17, 0L, ft_exit, NULL);
	mlx_loop(in->init);
	free(in);
}
