/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:48:51 by maricont          #+#    #+#             */
/*   Updated: 2023/05/12 17:26:25 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_validator(char c, va_list arg)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(arg, int));
	if (c == '%')
		len = ft_putchar('%');
	if (c == 's')
		len = ft_putstr(va_arg(arg, char *));
	if (c == 'p')
		len = ft_ptr_hexa(va_arg(arg, void *));
	if (c == 'd' || c == 'i')
		len = ft_decimal(va_arg(arg, int));
	if (c == 'u')
		len = ft_decimal_uns(va_arg(arg, unsigned int));
	if (c == 'x' || c == 'X')
		len = ft_hexa(va_arg(arg, int), c);
	return (len);
}

int	ft_select(char const *str, va_list arg)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			len = len + ft_validator(str[i + 1], arg);
			if (len == -1)
				return (-1);
			i++;
		}
		else
		{
			if (ft_putchar(str[i]) == -1)
				return (-1);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(arg, str);
	len = ft_select(str, arg);
	va_end(arg);
	return (len);
}
/*int	main()
{
	int	cont;
	int	cont1;

	cont = 0;
	cont1 = 0;
//	cont1 = printf("%s","(char *)NULL");
//	cont = ft_printf("%s","(char *)NULL");
//	printf("%d", cont1);
//	printf("%d", cont);
//	cont1 = printf("%s","can it handle \t and \n?");
//	cont = ft_printf("%s","can it handle \t and \n?");
//	printf("%d\n", cont1);
//	printf("%d\n", cont);
	
	cont1 = printf("hola %d\n", -21);
	cont = ft_printf("hola %d\n", -21);
	printf("%d\n", cont1);
	printf("%d\n", cont);
   	return(0);

}*/
