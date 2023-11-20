/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:22:13 by maricont          #+#    #+#             */
/*   Updated: 2023/05/12 17:31:21 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned long long c, int len)
{
	if (c >= 16)
	{
		len = len + ft_print_hexa(c / 16, len);
		if (len == -1)
			return (-1);
		if (ft_putchar("0123456789abcdef"[c % 16]) == -1)
			return (-1);
		len ++;
	}
	if (c < 16)
	{
		if (ft_putchar("0123456789abcdef"[c % 16]) == -1)
			return (-1);
		len ++;
	}
	return (len);
}

int	ft_ptr_hexa(void *ptr)
{
	unsigned long long	nro;
	int					len;

	len = 0;
	nro = (unsigned long long)ptr;
	if (ptr)
	{
		if (ft_putstr("0x") != 2)
			return (-1);
		len = ft_print_hexa(nro, len);
		if (len == -1)
			return (-1);
		len = len + 2;
	}
	else
	{
		len = ft_putstr("0x0");
	}
	return (len);
}
