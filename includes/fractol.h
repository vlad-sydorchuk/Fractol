/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:25:42 by vsydorch          #+#    #+#             */
/*   Updated: 2017/07/19 17:04:03 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <fcntl.h>
# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# define W 800
# define H 800
# define I 34
# define M 46

typedef struct	s_complex
{
	double	r;
	double	i;
}				t_complex;

/*
**	bg - bg for info
**	line - lines in bg;
**	fracts - list of fracts;
**	index_cf - index current fractol in fracts
**	fw_iter - max value for iteration
**	fw_max - max value for radius
**	info - flag for info, 0 - off, 1 - on
**	clr[126] - arr for colors
**	ms[2] - arr for coordinater Ox previous & current
**	cf_m - coef for scrolling
**	cf[8] - value for lines
*/

typedef struct	s_im
{
	void	*init;
	void	*win;
	void	*img;
	void	*fgd;
	int		bg;
	int		line;
	char	**fracts;
	int		index_cf;
	float	zoom;
	float	movex;
	float	movey;
	int		iter;
	int		max;
	int		fw_iter;
	int		fw_max;
	int		info;
	int		cof_clr;
	int		clr[126];
	int		flag_jul;
	float	cof_jul;
	int		ms[2];
	int		cf_m;
	int		cf[8];
}				t_im;

typedef struct	s_fract
{
	int			x;
	int			y;
	int			n;
	int			mx;
	int			my;
	t_complex	c;
	t_complex	new_c;
	t_complex	old_c;
}				t_fract;

/*
**				All hooks: 	ft_hooks.c
*/
int				ft_hook(int key, t_im *in);
int				ft_key_hook(int key, t_im *in);
int				ft_mouse_hook(int key, int x, int y, t_im *in);
int				ft_change_jul(int x, int y, t_im *in);
int				ft_exit(void *t);

/*
**				For one fractol: one_fractol.c
*/
void			ft_reimage(t_im *in);
void			ft_pxlimg(int x, int y, int rgb, t_im *in);
void			ft_continue_fr(t_im *in, t_fract *fr);
void			one_fract(char **fracts, char *cur_fract);

/*
**				Init structures: ft_init_st.c
*/
void			ft_fractal_init(t_fract *fractal);
void			ft_fr_init(t_im *in, char **fracts);
void			ft_fr_reinit(t_im *in);

/*
**				Mandatory part: mandatory.c
*/
void			ft_start_fr(t_im *in);
void			ft_julia_continue(t_im *in, t_fract *fr);
void			ft_mjb_continue(t_im *in, t_fract *fr);
void			ft_polikarp_continue(t_im *in, t_fract *fr);

/*
**				Bonus part: bonus.c
*/
void			ft_burningship_continue(t_im *in, t_fract *fr);
void			ft_bio_continue(t_im *in, t_fract *fr);
void			ft_frog_continue(t_im *in, t_fract *fr);
void			ft_newton_continue(t_im *in, t_fract *fr);
void			ft_star_continue(t_im *in, t_fract *fr);

/*
**				Draw menu: ft_info.c ft_menu.c
*/
void			ft_info(t_im *in);
void			ft_menu(t_im *in);

/*
**				Additional function's: additional.c
*/
double			mp(float num, int pow);
void			ft_color(t_im *in);
void			ft_change_fr(t_im *in, int key);
void			ft_create_bg(t_im *in);

/*
**				Additional (Part 2): ft_itoa_upd.c
*/
char			*ft_itoa_upd(int n, char **str);
#endif
