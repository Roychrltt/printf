/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:24:29 by xiaxu             #+#    #+#             */
/*   Updated: 2024/05/29 14:41:09 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	print_c(char c)
{
	write (1, &c, 1);
	return (1);
}

int	print_s(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	print_percent(void)
{
	write (1, '%', 1);
	return (1);
}

int	ft_format(const char c, va_list args)
{
	int	print_len;

	print_len = 0;
	if (c == 'c')
		print_len += print_c(va_arg(args, char));
	else if (c == 's')
		print_len += print_s(va_arg(args, char *));
	else if (c == 'p')
		print_len += print_p(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		print_len += print_d(va_arg(args, int));
	else if (c == 'u')
		print_len += print_u(va_arg(args, unsigned int));
	else if (c == 'x')
		print_len += print_x(va_arg(args, unsigned int));
	else if (c == 'X')
		print_len += print_hex(va_arg(args, unsigned int));
	else if (c == '%')
		print_len += print_percent();
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print_len;
	va_list	agrs;

	i = 0;
	print_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			print_len += ft_format(str[i + 1], args);
			i++;
		}
		else
			print_len += print_c(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}
