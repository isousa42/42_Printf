/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convhexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:50:31 by isousa            #+#    #+#             */
/*   Updated: 2021/03/29 12:50:41 by isousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(t_flags s_fl, char *hexa)
{
	int counter;

	counter = 0;
	if (s_fl.dot >= 0)
	{
		s_fl.width -= s_fl.dot;
		counter += ft_convwidth(s_fl.width, 0, 0);
	}
	else
		counter += ft_convwidth(s_fl.width, ft_strlen(hexa), s_fl.zero);
	if (s_fl.hiffen == 0)
	{
		if (s_fl.dot >= 0)
			counter += ft_convwidth(s_fl.dot, ft_strlen(hexa), 1);
		counter += ft_precision(hexa, ft_strlen(hexa));
	}
	return (counter);
}

int	ft_convhexa(unsigned int num, int xtype, t_flags s_fl)
{
	int		counter;
	char	*hexa;

	counter = 0;
	if (num == 0 && s_fl.dot == 0)
	{
		counter += ft_convwidth(s_fl.width, 0, 0);
		return (counter);
	}
	hexa = ft_unsigneditoa(num, 16);
	if (xtype == 0)
		hexa = ft_tolower(hexa);
	if (s_fl.hiffen == 1)
	{
		if (s_fl.dot >= 0)
			counter += ft_convwidth(s_fl.dot, ft_strlen(hexa), 1);
		counter += ft_precision(hexa, ft_strlen(hexa));
	}
	if (s_fl.dot >= 0 && (s_fl.dot < ft_strlen(hexa)))
		s_fl.dot = ft_strlen(hexa);
	counter += ft_printhexa(s_fl, hexa);
	free(hexa);
	return (counter);
}
