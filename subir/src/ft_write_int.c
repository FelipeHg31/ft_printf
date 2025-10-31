/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 04:29:57 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/14 05:13:52 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	else if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned_fd(n / 10, fd);
	count += ft_putchar_fd((n % 10) + '0', fd);
	return (count);
}

int	ft_write_int(int n)
{
	int	i;

	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	ft_putnbr_fd(n, 1);
	i = ft_count(n);
	return (i);
}

int	ft_write_int_unsigned(unsigned int n)
{
	int	i;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = ft_putnbr_unsigned_fd(n, 1);
	return (i);
}
