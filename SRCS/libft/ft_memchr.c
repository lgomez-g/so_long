/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 07:20:51 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/04/28 18:36:43 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)str)[i] == (char)c)
		{
			return ((void *)(str + i));
		}
		i++;
	}
	return (NULL);
}
/*
1. Verificamos que el puntero *str no sea NULL>

2. Hacemos un bucle while para iterar a travez de
 str sin exceder size_t n;

3. Hacemos conversiones explicitas del tipo int del 
caracter buscado 'c' a tipo char ya que esta funcion 
trabaja con bytes individuales y al convertir 'c' en 
tipo char se asegura que compare correctamente los bytes.

4. Devuelve un puntero tipo (void *) para apuntar a cualquier
 tipo de datos y con str + i  avanzamos en el puntero al byte en
la posicion i de la cadena str.
*/