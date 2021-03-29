/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:51:01 by isousa            #+#    #+#             */
/*   Updated: 2021/03/29 12:51:07 by isousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_letter(t_flags s_fl, va_list args)
{
	int counter;

	counter = 0;
	if (s_fl.letter == 'c')
		counter = ft_convchar(va_arg(args, int), s_fl);
	else if (s_fl.letter == '%')
		counter = ft_convper('%', s_fl);
	else if (s_fl.letter == 's')
		counter = ft_convstr(va_arg(args, char *), s_fl);
	else if (s_fl.letter == 'i' || s_fl.letter == 'd')
		counter = ft_convint(va_arg(args, int), s_fl);
	else if (s_fl.letter == 'u')
		counter = ft_convunint(va_arg(args, unsigned int), s_fl);
	else if (s_fl.letter == 'x')
		counter = ft_convhexa(va_arg(args, unsigned int), 0, s_fl);
	else if (s_fl.letter == 'X')
		counter = ft_convhexa(va_arg(args, unsigned int), 1, s_fl);
	else if (s_fl.letter == 'p')
		counter = ft_convpointer(va_arg(args, unsigned long long), s_fl);
	return (counter);
}

int	ft_spec(const char *format, va_list args, t_flags *s_fl, int i)
{
	while (format[i] != '\0')
	{
		if (!ft_digit(format[i]) && !ft_let(format[i]) && !ft_flag(format[i]))
			break ;
		if (format[i] == '0' && s_fl->width == 0 && s_fl->hiffen == 0)
			s_fl->zero = 1;
		if (format[i] == '.')
			i = ft_dot(format, args, s_fl, i);
		if (format[i] == '-')
			ft_hiffen(s_fl);
		if (format[i] == '*')
			ft_star(args, s_fl);
		if (ft_digit(format[i]))
			ft_width(format[i], s_fl);
		if (ft_let(format[i]))
		{
			s_fl->letter = format[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	ft_start(const char *format, va_list args)
{
	int		i;
	int		counter;
	t_flags	s_fl;

	i = 0;
	counter = 0;
	while (1)
	{
		s_fl = ft_startflags();
		if (!format[i])
			return (counter);
		else if (format[i] == '%' && format[i + 1] != '\0')
		{
			i = ft_spec(format, args, &s_fl, i + 1);
			if (s_fl.letter == 0)
				return (counter);
			if (ft_let(format[i]))
				counter += ft_letter(s_fl, args);
			else
				counter += ft_putchar(format[i]);
		}
		else if (format[i] != '%')
			counter += ft_putchar(format[i]);
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	va_start(args, format);
	counter = ft_start(format, args);
	va_end(args);
	return (counter);
}
