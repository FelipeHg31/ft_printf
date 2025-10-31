/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 04:29:46 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/14 19:08:55 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_base(char c, va_list vars)
{
	int	len;

	len = 0;
	if ((c == 'i') || (c == 'd'))
		len = ft_write_int(va_arg(vars, int));
	else if (c == 'u')
		len = ft_write_int_unsigned(va_arg(vars, unsigned int));
	else if (c == 'x')
		len = ft_write_hex(va_arg(vars, unsigned int));
	else if (c == 'X')
		len = ft_write_hex_c(va_arg(vars, unsigned int));
	else if (c == 'p')
		len = ft_write_punt(va_arg(vars, unsigned long));
	else
	{
		write(1, &c, 1);
		len = 1;
	}
	return (len);
}

int	ft_type(char c, va_list vars)
{
	int		len;
	char	*str;

	str = NULL;
	len = 0;
	if (c == 'c')
		len = ft_write_char((char)va_arg(vars, int));
	else if (c == 's')
	{
		str = va_arg(vars, char *);
		if (str == NULL)
			str = "(null)";
		len = ft_write_str(str);
	}
	else
		len = ft_type_base(c, vars);
	return (len);
}

int	ft_search(char const *str, int *i, int *j, va_list vars)
{
	int	len;

	*i = *i + 1;
	len = 0;
	if (str[*i] == '%')
	{
		write(1, "%%", 1);
		*j = *j + 1;
	}
	else
	{
		len = ft_type(str[*i], vars);
		if (len < 0)
			return (0);
	}
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int		total;
	int		i;
	int		j;
	va_list	vars;

	va_start(vars, str);
	i = 0;
	j = 0;
	total = 0;
	while (str[i])
	{
		if (str[i] == '%')
			total = total + ft_search(str, &i, &j, vars);
		else
		{
			write(1, &str[i], 1);
			j++;
		}
		i++;
	}
	return (total + j);
}

/* int	main(void)
{
	long	test = LLONG_MAX;
	int i = ft_printf(" %x ", test);
	printf("\n Valor mio %i\n", i);
	int k = printf(" %x ", test);
	printf("\n Valor funcion %i", k);
	return (0);
} */
