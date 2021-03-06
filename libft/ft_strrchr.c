/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:13:18 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/01 10:22:38 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	k;

	i = 0;
	k = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			k = i;
		i++;
	}
	if (k != -1)
		return ((char *)&s[k]);
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}
