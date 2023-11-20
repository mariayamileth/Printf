/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_uns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:00:07 by maricont          #+#    #+#             */
/*   Updated: 2023/05/12 16:37:18 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int n, int len)
{
	if (n >= 10)
	{
		len = ft_unsigned(n / 10, len);
		if (len == -1)
			return (-1);
		if (ft_putchar((n % 10) + '0') == -1)
			return (-1);
		len ++;
	}
	if (n < 10)
	{
		if (ft_putchar(n + '0') == -1)
			return (-1);
		len ++;
	}
	return (len);
}

int	ft_decimal_uns(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		n = -n;
		len ++;
	}
	if (n >= 0)
		len = ft_unsigned(n, len);
	return (len);
}
