/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:34:21 by xiaxu             #+#    #+#             */
/*   Updated: 2024/05/29 14:40:15 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_d(int	nb)
{
	int		print_len;
	char	*s;

	s = ft_itoa(nb);
	print_len = print_s(s);
	free(s);
	return (print_len);
}
