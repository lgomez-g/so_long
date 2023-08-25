/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franciscogomez <franciscogomez@student.42. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:07:02 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/04/25 12:45:27 by franciscogomez   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
1. 's' es un puntero a una cadena de caracteres (string) en 
la cual queremos aplicar una función.

2. 'f'  Esta función es la que se aplicará a cada uno 
de los caracteres de la cadena s. Puede ser cualquier funcion que
tome los mismos argumentos.

La función ft_striteri itera sobre cada carácter de la cadena s y llama 
a la función f para aplicarla a cada caracter de *s.
*/