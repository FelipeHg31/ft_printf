/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_punt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 03:25:52 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/14 04:46:21 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbase(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putnbase(n / 16, base);
	count += ft_write_char(base[n % 16]);
	return (count);
}

int	ft_write_punt(unsigned long n)
{
	int			len;

	len = 0;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		len = 2 + ft_putnbase(n, "0123456789abcdef");
	}
	return (len);
}
