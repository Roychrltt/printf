/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:56:24 by xiaxu             #+#    #+#             */
/*   Updated: 2024/05/30 12:30:32 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	print_di(int nb)
{
	int		print_len;
	char	*s;

	s = ft_itoa(nb);
	print_len = print_s(s);
	free(s);
	return (print_len);
}

static int	unsigned_num_len(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char	*unsigned_itoa(unsigned int nb)
{
	int		len;
	char	*result;

	len = unsigned_num_len(nb);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = 0;
	if (nb == 0)
		result[0] = '0';
	else
	{
		while (nb)
		{
			result[--len] = nb % 10 + '0';
			nb /= 10;
		}
	}
	return (result);
}

int	print_u(unsigned int nb)
{
	int		print_len;
	char	*s;

	print_len = unsigned_num_len(nb);
	s = unsigned_itoa(nb);
	print_s(s);
	free(s);
	return (print_len);
}
