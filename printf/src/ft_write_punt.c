/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_punt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 03:25:52 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/13 03:30:45 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_change(uintptr_t n, char *base)
{
	uintptr_t		tmp;
	char	        num;

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

int	ft_write_punt(uintptr_t n)
{
	static char	hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
			'a', 'b', 'c', 'd', 'e', 'f'};
	int			len;

	write(1, "Ox", 2);
	ft_change(n, hexa);
	len = 2 + ft_counthex(n);
	return (len);
}