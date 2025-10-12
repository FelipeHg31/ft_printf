/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 04:29:57 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/12 21:36:56 by juan-her         ###   ########.fr       */
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
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_write_int(int n)
{
	int	i;

	ft_putnbr_fd(n, 1);
	i = ft_count(n);
	return (i);
}

int	ft_write_int_unsigned(int n)
{
	int	i;

	if (n < 0)
		n = n * -1;
	ft_putnbr_fd(n, 1);
	i = ft_count(n);
	printf("\n%i", i);
	return (i);
}
