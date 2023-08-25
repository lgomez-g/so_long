/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franciscogomez <franciscogomez@student.42. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:00:14 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/04/25 15:27:53 by franciscogomez   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	j = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	j = dest_len;
	if (size == 0 || size <= dest_len)
		return (src_len + size);
	while (src[i] && i < size - dest_len - 1)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = 0;
	return (dest_len + src_len);
}

/*
1. Se mide el tamanho de las dos cadenas verificando que den espacio al
caracter nulo que se va a agregar al final.

2. En el segundo ciclo while se empieza a copiar las dos cadenas y con el
size -1 nos aseguramos que no tengan espacio suficiente para'\0'.

3. Agregamos el caracter nulo al final de las 2 cadenas.

4.Devolvemos el tamanho de las dos cadenas.
*/