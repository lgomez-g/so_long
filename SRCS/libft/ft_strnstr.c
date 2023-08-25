/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:06:05 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/04/27 17:12:11 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

/*
1. Primero verificamos que *little no sea NULL.

2. Hacemos un bucle while para iterar a traves de
 *big sin pasarnos del limite size_t len.

3. Hacemos otro bucle while para comparar cada caracter 
de la subcadena little con el correspondiente de big. 
((while (big[i + j] == little[j] && i + j < len)))

4. Si se ha encontrado la subcadena dentro de big se 
devuelve un puntero a la posicion de inicio dentro de big.
*/