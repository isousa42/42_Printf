/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_un.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:49:58 by isousa            #+#    #+#             */
/*   Updated: 2021/03/29 12:50:03 by isousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convunint(unsigned num, t_flags s_fl)
{
	int		counter;
	int		nb;
	char	*str;

	counter = 0;
	nb = num;
	if (s_fl.hiffen == 1)
		s_fl.zero = 0;
	if (s_fl.dot == 0 && num == 0)
	{
		counter += ft_convwidth(s_fl.width, 0, 0);
		return (counter);
	}
	str = ft_itoa(num);
	counter += ft_printun(s_fl, str);
	free(str);
	return (counter);
}

int	ft_printun(t_flags s_fl, char *str)
{
	int counter;

	counter = 0;
	if (s_fl.hiffen == 1)
	{
		if (s_fl.dot >= 0)
			counter += ft_convwidth(s_fl.dot, ft_strlen(str), 1);
		counter += ft_precision(str, ft_strlen(str));
	}
	if (s_fl.dot >= 0 && (s_fl.dot < ft_strlen(str)))
		s_fl.dot = ft_strlen(str);
	if (s_fl.dot >= 0)
	{
		s_fl.width -= s_fl.dot;
		counter += ft_convwidth(s_fl.width, 0, 0);
	}
	else
		counter += ft_convwidth(s_fl.width, ft_strlen(str), s_fl.zero);
	if (s_fl.hiffen == 0)
	{
		if (s_fl.dot >= 0)
			counter += ft_convwidth(s_fl.dot, ft_strlen(str), 1);
		counter += ft_precision(str, ft_strlen(str));
	}
	return (counter);
}
