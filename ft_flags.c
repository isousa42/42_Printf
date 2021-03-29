/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:50:48 by isousa            #+#    #+#             */
/*   Updated: 2021/03/29 12:50:52 by isousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_startflags(void)
{
	t_flags s_fl;

	s_fl.dot = -1;
	s_fl.hiffen = 0;
	s_fl.width = 0;
	s_fl.star = 0;
	s_fl.letter = 0;
	s_fl.zero = 0;
	return (s_fl);
}

int		ft_dot(const char *format, va_list args, t_flags *s_fl, int i)
{
	i++;
	if (format[i] == '*')
	{
		s_fl->dot = va_arg(args, int);
		i++;
	}
	else
	{
		s_fl->dot = 0;
		while (ft_digit(format[i]))
		{
			s_fl->dot = (s_fl->dot * 10) + (format[i] - '0');
			i++;
		}
	}
	return (i);
}

void	ft_hiffen(t_flags *s_fl)
{
	s_fl->hiffen = 1;
	s_fl->zero = 0;
}

void	ft_star(va_list args, t_flags *s_fl)
{
	s_fl->star = 1;
	s_fl->width = va_arg(args, int);
	if (s_fl->width < 0)
	{
		s_fl->hiffen = 1;
		s_fl->width *= -1;
	}
}

void	ft_width(char c, t_flags *s_fl)
{
	if (s_fl->star == 1)
		s_fl->width = 0;
	s_fl->width = (s_fl->width * 10) + (c - '0');
}
