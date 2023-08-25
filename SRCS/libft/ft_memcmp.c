/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:57:24 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/04/26 17:37:19 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	while ((*s1 == *s2) && ((n -1) > 0))
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}
/*
s1 = (unsigned char *)str1;
s2 = (unsigned char *)str2;

: convierte un puntero a un puntero de bytes unsigned.
  Se hace para poder comparar los bytes de las 2 zonas
  de memoria.

*/