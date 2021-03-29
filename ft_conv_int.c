/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:49:47 by isousa            #+#    #+#             */
/*   Updated: 2021/03/29 12:49:51 by isousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intexep(t_flags s_fl)
{
	int counter;

	counter = 0;
	if (s_fl.zero == 1 && s_fl.dot <= -1)
		counter += ft_precision("-", 1);
	if (s_fl.hiffen == 1)
		s_fl.zero = 0;
	return (counter);
}

int	ft_callfun(t_flags s_fl, int nb, int sign, char *str)
{
	int counter;

	counter = 0;
	if (s_fl.hiffen == 1)
		counter += ft_printint(s_fl, sign, nb, str);
	if (s_fl.dot >= 0 && (s_fl.dot < ft_strlen(str)))
		s_fl.dot = ft_strlen(str);
	counter += ft_intwidth(s_fl, str, sign, nb);
	if (s_fl.hiffen == 0)
		counter += ft_printint(s_fl, sign, nb, str);
	return (counter);
}

int	ft_printint(t_flags s_fl, int sign, int nb, char *str)
{
	int counter;

	counter = 0;
	{
		if (nb < 0 && sign == 0)
		{
			counter += ft_putchar('-');
			if (s_fl.hiffen == 1)
				sign = 1;
		}
		if (s_fl.dot >= 0)
			counter += ft_convwidth(s_fl.dot, ft_strlen(str), 1);
		counter += ft_precision(str, ft_strlen(str));
	}
	return (counter);
}

int	ft_intwidth(t_flags s_fl, char *str, int sign, int nb)
{
	int count;

	count = 0;
	if (s_fl.dot >= 0)
	{
		s_fl.width -= s_fl.dot;
		count += ft_convwidth(s_fl.width, 0, 0);
	}
	else if (nb < 0 && sign == 1 && s_fl.zero == 1)
		count += ft_convwidth(s_fl.width + 1, ft_strlen(str) + 1, s_fl.zero);
	else if (nb < 0)
		count += ft_convwidth(s_fl.width, ft_strlen(str) + 1, s_fl.zero);
	else
		count += ft_convwidth(s_fl.width, ft_strlen(str), s_fl.zero);
	return (count);
}

int	ft_convint(int num, t_flags s_fl)
{
	int		counter;
	char	*str;
	int		sign;

	counter = 0;
	sign = 0;
	if (s_fl.hiffen == 1)
		s_fl.zero = 0;
	if (s_fl.dot == 0 && num == 0)
	{
		counter += ft_convwidth(s_fl.width, 0, 0);
		return (counter);
	}
	if (num < 0 && (s_fl.dot >= 0 || s_fl.zero == 1))
	{
		counter += ft_intexep(s_fl);
		if (s_fl.zero == 1 && s_fl.dot <= -1)
			sign = 1;
		s_fl.width--;
	}
	str = ft_itoa(num * -1);
	counter += ft_callfun(s_fl, num, sign, str);
	free(str);
	return (counter);
}
