/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_upd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 12:08:39 by vsydorch          #+#    #+#             */
/*   Updated: 2017/07/07 12:08:41 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int			num(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int			ft_pow(int num, int len)
{
	int res;

	if (len <= 0)
		return (1);
	res = 1;
	while (len--)
		res *= num;
	return (res);
}

char				*ft_itoa_upd(int n, char **str)
{
	int		len;
	int		i;

	len = num(n);
	if (n <= 0)
		(*str) = (char*)malloc(sizeof(char) * (len + 2));
	else
		(*str) = (char*)malloc(sizeof(char) * (len + 1));
	if (!(*str))
		return (0);
	i = 0;
	if (n < 0 && ++i)
		(*str)[0] = '-';
	if (n == 0 && ++i)
		(*str)[0] = '0';
	while (--len >= 0)
	{
		if (n < 0)
			(*str)[i++] = '0' - (n / ft_pow(10, len)) % 10;
		else
			(*str)[i++] = '0' + (n / ft_pow(10, len)) % 10;
	}
	(*str)[i] = 0;
	return ((*str));
}
