/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:51:33 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/04/26 18:06:58 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chech_if_trimable(char const *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static void	ft_put_in_arr(char *arr, const char *str, int start, int end)
{
	int	i;

	i = 0;
	while (start <= end)
	{
		arr[i++] = str[start++];
	}
	arr[i] = '\0';
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*newstr;
	int		start;
	int		end;

	start = 0;
	if (!str || !set)
		return (NULL);
	while (str[start] && ft_chech_if_trimable(set, str[start]))
		start++;
	end = ft_strlen(str) - 1;
	while (end > start && ft_chech_if_trimable(set, str[end]))
		end--;
	newstr = malloc(sizeof(char) * (end - start + 2));
	if (!newstr)
		return (NULL);
	ft_put_in_arr(newstr, str, start, end);
	return (newstr);
}
/*
PASO A PASO 

1. ft_chech_if_trimable = verifica si un caracter dado esta presente en
 un conjunto de  caracteres especificados en el argumento 'char c' de la 
 funcion. Si en algun momento *str = char c return(1); y sigue aumentando str++.
Despues de el while loop return (0);

2. void ft_put_in_arr = se usa para copiar una cadena de origen en una cadena
 de destino, la cadena de origen , el indice de inicio y el indice final de la 
 subcadena.

3. ft_strrim = se utiliza para recortar una cadena de caracteres especificada
 eliminando los caracteres especificados del principio y del final de la cadena.
La funcion toma como argumentos la cadena a recortar y el conjunto de caracteres
 que se debe eliminar. 

 4. newstr = malloc(sizeof(char) * (end - start + 2)); / end - start + 2 se usa
 para calcular el tamano de la cadena y reservar espacio para el caracter nulo.

ejemplo:

ft_strrim(" HelloWorld ", " ")

output: "HelloWorld"

Elimina los espacios de al frente y de atras.
*/