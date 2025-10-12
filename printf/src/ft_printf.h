/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 04:29:50 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/12 21:36:11 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int	ft_printf(char const *str, ...);
int	ft_write_char(char c);
int	ft_write_str(char *str);
int	ft_write_int(int n);
int	ft_write_int_unsigned(int n);
int	ft_write_hex(int n);
int	ft_write_hex_c(int n);

#endif
