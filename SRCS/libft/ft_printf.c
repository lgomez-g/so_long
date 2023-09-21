<<<<<<< HEAD

=======
>>>>>>> d18e74f9a0c63f4ce7efb508becaece888e0e01b
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:29:17 by franciscogomez    #+#    #+#             */
/*   Updated: 2023/09/21 12:19:35 by lgomez-g         ###   ########.fr       */
=======
/*   By: franciscogomez <franciscogomez@student.42. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:29:17 by franciscogomez    #+#    #+#             */
/*   Updated: 2023/09/19 15:08:55 by franciscogomez   ###   ########.fr       */
>>>>>>> d18e74f9a0c63f4ce7efb508becaece888e0e01b
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_printf(const char *format, ...)
{
	va_list	args;
	int	ret;
	
	ret = 0;
	va_start (args, format);
	while (*format)
	{
		if (*format == '%')
			ret += ft_printfselect(*(++format), args);
<<<<<<< HEAD
		else
			ret += ft_printfc(*format);
		format++;
	}
	va_end (args);
	return (ret);
=======
		else 
			ret += ft_printfc(*format);
			format++;
	}
	va_end (args);
	return (ret);
		
>>>>>>> d18e74f9a0c63f4ce7efb508becaece888e0e01b
}

int ft_printfselect (char c, va_list args)
{
	if (c == 'c')
		return (ft_printfc(va_arg(args, int)));
	else if (c == 's')
		return (ft_printfs(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_printfn(va_arg(args, int)));
	else if (c == 'u')
		return (ft_printfun(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_printfx(va_arg(args, unsigned int), HEXMIN));
	else if (c == 'X')
		return (ft_printfx(va_arg(args, unsigned int), HEXMAX));
	else if (c == 'p')
		return (ft_printfp(va_arg(args, unsigned long long)));
	else if (c == '%')
		return (ft_printfc('%'));
	return (0);
}

int	ft_printfc(char c)
{
	return (write (1, &c, 1));
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}