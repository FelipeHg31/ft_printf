/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 04:29:46 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/13 03:51:31 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <cstdint>

int	ft_type(char c, va_list vars)
{
	int			len;
	//uintptr_t	h;

	if (c == 'c')
		len = ft_write_char((char)va_arg(vars, int));
	else if (c == 's')
		len = ft_write_str((char *)va_arg(vars, char *));
	else if ((c == 'i') || (c == 'd'))
		len = ft_write_int(va_arg(vars, int));
	else if (c == 'u')
		len = ft_write_int_unsigned(va_arg(vars, int));
	else if (c == 'x')
		len = ft_write_hex(va_arg(vars, int));
	else if (c == 'X')
		len = ft_write_hex_c(va_arg(vars, int));
	else if (c == 'p')
		len = ft_write_punt(va_arg(vars, int));
	printf("%i\n", len);
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int		total;
	int		i;
	int		len;
	va_list	vars;

	va_start(vars, str);
	len = ft_strlen(str) + 1;
	i = 0;
	total = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				write(1, "%%", 1);
			else
			{
				len = ft_type(str[i], vars);
				if (len <= 0)
					return (-1);
				total = total + len;
			}
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	return (total + i);
}

int	main(void)
{
	char	*hola;
	char	c;
	int		num;
	int		num2;
	int		base;
	int		base1;
	int cant;
	int cant2;
	
	hola = "hola";
	c = '\n';
	num = -312454454;
	num2 = -312454454;
	base = 42;
	base1 = 42;
	cant = ft_printf("esto es un \n%s \n%c \n%i \n%d \n%x \n%X \n%% \n%p", hola, c, num, num,
		base, base, &c);
	/* cant2 = printf("esto es un \n%s \n%c \n%i \n%d \n%x \n%X \n%% \n%p", hola, c, num, num,
		base, base, &c); */
	ft_printf("\n%d   %i", cant, (int)cant2);
}
