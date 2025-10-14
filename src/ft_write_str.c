/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 04:30:00 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/13 18:04:59 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_str(char *str)
{
	write (1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_write_char(char c)
{
	write (1, &c, 1);
	return (1);
}
