/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:17:07 by maricont          #+#    #+#             */
/*   Updated: 2023/05/12 17:32:07 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nro_hexa_min(unsigned long long n, int len)
{
	if (n >= 16)
	{
		len = len + ft_nro_hexa_min(n / 16, len);
		if (len == -1)
			return (-1);
		if (ft_putchar("0123456789abcdef"[n % 16]) == -1)
			return (-1);
		len ++;
	}
	if (n < 16)
	{
		if (ft_putchar("0123456789abcdef"[n % 16]) == -1)
			return (-1);
		len ++;
	}
	return (len);
}

int	ft_nro_hexa_may(unsigned long long n, int len)
{
	if (n >= 16)
	{
		len = len + ft_nro_hexa_may(n / 16, len);
		if (len == -1)
			return (-1);
		if (ft_putchar("0123456789ABCDEF"[n % 16]) == -1)
			return (-1);
		len ++;
	}
	if (n < 16)
	{
		if (ft_putchar("0123456789ABCDEF"[n % 16]) == -1)
			return (-1);
		len ++;
	}
	return (len);
}

int	ft_nro_hexa_min_neg(unsigned int n, int len)
{
	if (n >= 16)
	{
		len = len + ft_nro_hexa_min_neg(n / 16, len);
		if (len == -1)
			return (-1);
		if (ft_putchar("0123456789abcdef"[n % 16]) == -1)
			return (-1);
		len ++;
	}
	if (n < 16)
	{
		if (ft_putchar("0123456789abcdef"[n % 16]) == -1)
			return (-1);
		len ++;
	}
	return (len);
}

int	ft_nro_hexa_may_neg(unsigned int n, int len)
{
	if (n >= 16)
	{
		len = len + ft_nro_hexa_may_neg(n / 16, len);
		if (len == -1)
			return (-1);
		if (ft_putchar("0123456789ABCDEF"[n % 16]) == -1)
			return (-1);
		len ++;
	}
	if (n < 16)
	{
		if (ft_putchar("0123456789ABCDEF"[n % 16]) == -1)
			return (-1);
		len ++;
	}
	return (len);
}

int	ft_hexa(int nro, char c)
{
	int	len;

	len = 0;
	if (c == 'x')
	{
		if (nro >= 0)
			len = ft_nro_hexa_min(nro, len);
		else
			len = ft_nro_hexa_min_neg(nro, len);
	}
	if (c == 'X')
	{
		if (nro >= 0)
			len = ft_nro_hexa_may(nro, len);
		else
			len = ft_nro_hexa_may_neg(nro, len);
	}
	return (len);
}
