/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:49:33 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/04/26 10:27:50 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*newstr;

	i = 0;
	if (!s || !f)
		return (NULL);
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!newstr)
		return (NULL);
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

/*

Ft_strmapi toma dos argumentos: la cadena de caracteres 
original (s) y un puntero a una función (f) que se aplicará
 a cada carácter de la cadena. Lafunción ft_strmapi crea una 
 nueva cadena (newstr) del mismo tamaño que la cadena
original y luego itera sobre cada carácter de la cadena 
original. En cada iteración, se llama a la función f con el
 índice del carácter y el carácter en sí mismo como
argumentos, y el valor devuelto por la función se utiliza
 para construir la nueva  cadena. Finalmente, se devuelve
  la nueva cadena de caracteres.
*/
