/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:19:31 by vsydorch          #+#    #+#             */
/*   Updated: 2017/06/28 15:19:32 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_iter_radius(t_im *in, int a)
{
	char *str;

	str = NULL;
	mlx_string_put(in->init, in->win, 30 + a, 80 + in->cf_m, 0xFFFFFF,
		"Iteration:");
	mlx_string_put(in->init, in->win, 140 + a, 80 + in->cf_m, 0xBCFF00,
		ft_itoa_upd(in->iter, &str));
	if (in->iter == 26)
		mlx_string_put(in->init, in->win, 170 + a, 80 + in->cf_m, 0xFF7373,
			"Warning: Minimal allowable iteration!");
	free(str);
	str = NULL;
	mlx_string_put(in->init, in->win, 30 + a, 100 + in->cf_m, 0xFFFFFF,
		"Radius:");
	mlx_string_put(in->init, in->win, 140 + a, 100 + in->cf_m, 0xBCFF00,
		ft_itoa_upd(in->max, &str));
	if (in->max == 4)
		mlx_string_put(in->init, in->win, 170 + a, 100 + in->cf_m, 0xFF7373,
			"Warning: Minimal allowable radius!");
	free(str);
	a = 200;
	mlx_string_put(in->init, in->win, 190 + a, 170 + in->cf_m, 0x00CCBE, "Up");
	mlx_string_put(in->init, in->win, 195 + a, 190 + in->cf_m, 0x00CCBE, "^");
	mlx_string_put(in->init, in->win, 100 + a, 210 + in->cf_m, 0x00CCBE,
		"Right <      > Left");
}

static void	ft_keys(t_im *in, int a)
{
	mlx_string_put(in->init, in->win, 100 + a, 350 + in->cf_m, 0xFFFFFF,
		"1:");
	mlx_string_put(in->init, in->win, 130 + a, 350 + in->cf_m, 0x00CCBE,
		"Julia");
	mlx_string_put(in->init, in->win, 230 + a, 350 + in->cf_m, 0xFFFFFF,
		"2:");
	mlx_string_put(in->init, in->win, 260 + a, 350 + in->cf_m, 0x00CCBE,
		"Mandelbrot");
	mlx_string_put(in->init, in->win, 380 + a, 350 + in->cf_m, 0xFFFFFF,
		"3:");
	mlx_string_put(in->init, in->win, 410 + a, 350 + in->cf_m, 0x00CCBE,
		"Polikarp");
	mlx_string_put(in->init, in->win, 510 + a, 350 + in->cf_m, 0xFFFFFF,
		"4:");
	mlx_string_put(in->init, in->win, 540 + a, 350 + in->cf_m, 0x00CCBE,
		"BurningShip");
	mlx_string_put(in->init, in->win, 100 + a, 370 + in->cf_m, 0xFFFFFF,
		"5:");
	mlx_string_put(in->init, in->win, 130 + a, 370 + in->cf_m, 0x00CCBE,
		"Biomorph");
	mlx_string_put(in->init, in->win, 230 + a, 370 + in->cf_m, 0xFFFFFF,
		"6:");
	mlx_string_put(in->init, in->win, 260 + a, 370 + in->cf_m, 0x00CCBE,
		"Frog");
}

static void	ft_color_info(t_im *in, int a)
{
	mlx_string_put(in->init, in->win, 190 + a, 450 + in->cf_m, 0x00CCBE,
		"\"Z\" <<");
	mlx_string_put(in->init, in->win, 280 + a, 450 + in->cf_m, 0xBCFF00,
		"Color");
	mlx_string_put(in->init, in->win, 360 + a, 450 + in->cf_m, 0x00CCBE,
		">> \"X\"");
	mlx_string_put(in->init, in->win, 170 + a, 540 + in->cf_m, 0x00CCBE,
		"\"I\" <<");
	mlx_string_put(in->init, in->win, 260 + a, 540 + in->cf_m, 0xBCFF00,
		"Iteration");
	mlx_string_put(in->init, in->win, 380 + a, 540 + in->cf_m, 0x00CCBE,
		">> \"O\"");
	mlx_string_put(in->init, in->win, 190 + a, 560 + in->cf_m, 0x00CCBE,
		"\"J\" <<");
	mlx_string_put(in->init, in->win, 280 + a, 560 + in->cf_m, 0xBCFF00,
		"Radius");
	mlx_string_put(in->init, in->win, 360 + a, 560 + in->cf_m, 0x00CCBE,
		">> \"K\"");
	a = 200;
	mlx_string_put(in->init, in->win, 195 + a, 230 + in->cf_m, 0x00CCBE,
		"v");
	mlx_string_put(in->init, in->win, 180 + a, 250 + in->cf_m, 0x00CCBE,
		"Down");
}

static void	ft_zoom_info(t_im *in, int a)
{
	mlx_string_put(in->init, in->win, 250 + a, 630 + in->cf_m, 0x00CCBE, "^");
	mlx_string_put(in->init, in->win, 250 + a, 640 + in->cf_m, 0x00CCBE, "^");
	mlx_string_put(in->init, in->win, 190 + a, 660 + in->cf_m, 0xBCFF00,
		"Scroll mouse");
	mlx_string_put(in->init, in->win, 250 + a, 680 + in->cf_m, 0x00CCBE, "v");
	mlx_string_put(in->init, in->win, 250 + a, 690 + in->cf_m, 0x00CCBE, "v");
	mlx_string_put(in->init, in->win, 60 + a, 760 + in->cf_m, 0x00CCBE,
		"Press once \"Q\" and move the mouse.");
	mlx_string_put(in->init, in->win, 60 + a, 785 + in->cf_m, 0x00CCBE,
		"Press again \"Q\", if you want to disable this.");
	mlx_string_put(in->init, in->win, 200 + a, 840 + in->cf_m, 0x00FF04,
		"vsydorch");
	a = 30;
	mlx_string_put(in->init, in->win, 380 + a, 370 + in->cf_m, 0xFFFFFF,
		"7:");
	mlx_string_put(in->init, in->win, 410 + a, 370 + in->cf_m, 0x00CCBE,
		"Newton");
	mlx_string_put(in->init, in->win, 510 + a, 370 + in->cf_m, 0xFFFFFF,
		"8:");
	mlx_string_put(in->init, in->win, 540 + a, 370 + in->cf_m, 0x00CCBE,
		"Star");
}

void		ft_info(t_im *in)
{
	mlx_clear_window(in->init, in->win);
	mlx_put_image_to_window(in->init, in->win, in->fgd, 0, 0);
	mlx_string_put(in->init, in->win, 370, 10 + in->cf_m, 0xFF7373, " MENU ");
	mlx_string_put(in->init, in->win, 60, 50 + in->cf_m, 0xF0FF00,
		"Frat'ol params");
	ft_iter_radius(in, 100);
	mlx_string_put(in->init, in->win, 60, 150 + in->cf_m, 0xF0FF00, "Move");
	mlx_string_put(in->init, in->win, 60, 315 + in->cf_m, 0xF0FF00,
		"Change frac'ol");
	ft_keys(in, 30);
	mlx_string_put(in->init, in->win, 60, 425 + in->cf_m, 0xF0FF00,
		"Change color pallete");
	mlx_string_put(in->init, in->win, 60, 505 + in->cf_m, 0xF0FF00,
		"Change fract'ol params");
	ft_color_info(in, 90);
	mlx_string_put(in->init, in->win, 60, 610 + in->cf_m, 0xF0FF00,
		"Zoom in dot");
	ft_zoom_info(in, 150);
	mlx_string_put(in->init, in->win, 60, 735 + in->cf_m, 0xF0FF00,
		"Additional params for Julia");
}
