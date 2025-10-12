/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 04:29:37 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/12 21:48:52 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_change(int n, char *base)
{
	int		tmp;
	char	num;

	num = 0;
	tmp = n / 16;
	if (n >= 16)
		ft_change(tmp, base);
	num = base[n % 16];
	write(1, &num, 1);
}

static int	ft_counthex(int n)
{
	int	i;

	i = 0;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_write_hex(int n)
{
	static char	hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
			'a', 'b', 'c', 'd', 'e', 'f'};
	int			len;

	while (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		len++;
	}
	ft_change(n, hexa);
	len = len + ft_counthex(n);
	return (len);
}

int	ft_write_hex_c(int n)
{
	char	*hexa;
	int		len;

	hexa = ft_strdup("0123456789ABCDEF");
	while (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		len++;
	}
	ft_change(n, hexa);
	free(hexa);
	len = len + ft_counthex(n);
	return (len);
}
