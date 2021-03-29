/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:50:22 by isousa            #+#    #+#             */
/*   Updated: 2021/03/29 12:50:24 by isousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convper(char c, t_flags s_fl)
{
	int		counter;
	char	*str;

	counter = 0;
	str = malloc(sizeof(char) * 3);
	if (!str)
		return (0);
	str[0] = c;
	str[1] = '\0';
	if (s_fl.hiffen == 1)
		counter += ft_precision(str, 1);
	counter += ft_convwidth(s_fl.width, 1, s_fl.zero);
	if (s_fl.hiffen == 0)
		counter += ft_precision(str, 1);
	free(str);
	return (counter);
}

int	ft_convchar(char c, t_flags s_fl)
{
	int counter;

	counter = 0;
	if (s_fl.hiffen == 1)
		counter += ft_putchar(c);
	counter += ft_convwidth(s_fl.width, 1, 0);
	if (s_fl.hiffen == 0)
		counter += ft_putchar(c);
	return (counter);
}

int	ft_putstrdot(int dot, char *str)
{
	int counter;
	int i;

	i = 0;
	counter = 0;
	if (dot >= 0)
	{
		counter += ft_convwidth(dot, ft_strlen(str), 0);
		counter += ft_precision(str, dot);
	}
	else
		counter += ft_precision(str, ft_strlen(str));
	return (counter);
}

int	ft_convstr(char *str, t_flags s_fl)
{
	int counter;

	counter = 0;
	if (!str)
		str = "(null)";
	if (s_fl.width > ft_strlen(str) && s_fl.zero == 1)
	{
		counter += ft_convwidth(s_fl.width, ft_strlen(str), 1);
		counter += ft_putstrdot(ft_strlen(str), str);
		return (counter);
	}
	if (s_fl.dot >= 0 && (s_fl.dot > ft_strlen(str)))
		s_fl.dot = ft_strlen(str);
	if (s_fl.hiffen == 1)
		counter += ft_putstrdot(s_fl.dot, str);
	if (s_fl.dot >= 0)
		counter += ft_convwidth(s_fl.width, s_fl.dot, 0);
	else
		counter += ft_convwidth(s_fl.width, ft_strlen(str), 0);
	if (s_fl.hiffen == 0)
		counter += ft_putstrdot(s_fl.dot, str);
	return (counter);
}
