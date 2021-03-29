/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:51:28 by isousa            #+#    #+#             */
/*   Updated: 2021/03/29 12:51:30 by isousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convwidth(int width, int size, int zero)
{
	int counter;

	counter = 0;
	while (width - size > 0)
	{
		if (zero)
			counter += ft_putchar('0');
		else
			counter += ft_putchar(' ');
		width--;
	}
	return (counter);
}

int	ft_precision(char *str, int dot)
{
	int counter;
	int i;

	counter = 0;
	i = 0;
	while (str[i] != '\0' && i < dot)
	{
		counter += ft_putchar(str[i]);
		i++;
	}
	return (counter);
}
