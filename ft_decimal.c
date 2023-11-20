/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:02:27 by maricont          #+#    #+#             */
/*   Updated: 2023/05/12 16:47:35 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_positive(long int n, int len)
{
	if (n >= 10)
	{
		len = ft_positive(n / 10, len);
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

int	ft_decimal(long int n)
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
		len = ft_positive(n, len);
	return (len);
}
