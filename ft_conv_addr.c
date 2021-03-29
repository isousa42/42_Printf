/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convaddr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:50:11 by isousa            #+#    #+#             */
/*   Updated: 2021/03/29 12:50:15 by isousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_negexep(t_flags s_fl)
{
	int counter;

	counter = 0;
	if (s_fl.dot == 0)
	{
		counter += ft_precision("0x", 2);
		counter += ft_convwidth(s_fl.width, 2, 0);
	}
	else
	{
		counter += ft_precision("0x0", 3);
		counter += ft_convwidth(s_fl.width, 3, 0);
	}
	return (counter);
}

int	ft_addrexep(t_flags s_fl)
{
	int counter;

	counter = 0;
	if (s_fl.hiffen == 1)
		counter += ft_negexep(s_fl);
	else
	{
		if (s_fl.dot == 0)
		{
			counter += ft_convwidth(s_fl.width, 2, 0);
			counter += ft_precision("0x", 2);
		}
		else
		{
			counter += ft_convwidth(s_fl.width, 3, 0);
			counter += ft_precision("0x0", 3);
		}
	}
	return (counter);
}

int	ft_negwidth(t_flags s_fl, char *str)
{
	int counter;

	counter = 0;
	if (s_fl.dot >= 0)
	{
		counter += ft_precision("0x", 2);
		counter += ft_convwidth(s_fl.dot, ft_strlen(str) + 2, 1);
		counter += ft_precision(str, s_fl.dot);
	}
	else
	{
		counter += ft_precision("0x", 2);
		counter += ft_precision(str, ft_strlen(str) + 2);
	}
	return (counter);
}

int	ft_addrwidth(t_flags s_fl, char *str)
{
	int counter;

	counter = 0;
	if (s_fl.dot >= 0)
	{
		counter += ft_precision("0x", 2);
		counter += ft_convwidth(s_fl.dot, ft_strlen(str), 1);
		counter += ft_precision(str, s_fl.dot);
	}
	else
	{
		counter += ft_precision("0x", 2);
		counter += ft_precision(str, ft_strlen(str) + 2);
	}
	return (counter);
}

int	ft_convpointer(unsigned long long ptr, t_flags s_fl)
{
	int		counter;
	char	*str;

	counter = 0;
	if (ptr == 0 && (s_fl.dot == -1 || s_fl.dot == 0))
		return (ft_addrexep(s_fl));
	str = ft_unsigneditoa(ptr, 16);
	str = ft_tolower(str);
	if (s_fl.dot < ft_strlen(str))
		s_fl.dot = ft_strlen(str);
	if (s_fl.hiffen == 1)
		counter += ft_negwidth(s_fl, str);
	counter += ft_convwidth(s_fl.width, ft_strlen(str) + 2, 0);
	if (s_fl.hiffen == 0)
		counter += ft_addrwidth(s_fl, str);
	free(str);
	return (counter);
}
