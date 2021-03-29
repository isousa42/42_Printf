/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:49:14 by isousa            #+#    #+#             */
/*   Updated: 2021/03/29 12:49:23 by isousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen(long int n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

int		ft_unintlen(unsigned long long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char	*ft_unsigneditoa(unsigned long long n, int base)
{
	char				*res;
	unsigned long long	len;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_unintlen(n, base);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (0);
	res[len--] = '\0';
	while (n > 0)
	{
		if ((n % base) < 10)
			res[len] = (n % base) + '0';
		else
			res[len] = (n % base) + 55;
		n = n / base;
		len--;
	}
	return (res);
}

char	*ft_itoa(long int n)
{
	char	*res;
	size_t	len;

	len = ft_intlen(n, 10);
	res = (char *)malloc(len + 1 * sizeof(char));
	if (!res)
		return (0);
	res[len] = '\0';
	len--;
	if (n == 0)
		res[0] = '0';
	else if (n < 0)
	{
		res[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		res[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (res);
}
