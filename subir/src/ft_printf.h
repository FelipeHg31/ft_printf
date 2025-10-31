/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 04:29:50 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/14 19:22:24 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

int		ft_printf(char const *str, ...);
int		ft_write_char(char c);
int		ft_write_str(char *str);
int		ft_write_int(int n);
int		ft_write_int_unsigned(unsigned int n);
int		ft_write_hex(unsigned int n);
int		ft_write_hex_c(unsigned int n);
int		ft_write_punt(unsigned long n);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_putchar_fd(char c, int fd);

#endif
