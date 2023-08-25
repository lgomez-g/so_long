/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:33:22 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/04/26 18:05:51 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	*malloc_word(const char *s, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	char		**splited;

	splited = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!splited || !s)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			splited[i] = malloc_word(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	splited[i] = 0;
	return (splited);
}

/*

1. La función recibe una cadena s y un carácter delimitador
 c, y devuelve  un array de cadenas.

2.  Declara un entero i para llevar la cuenta de las subcadenas
 y un puntero a un array de cadenas splited que se inicializará
  más adelante.

3. splited = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));: 
Reserva memoria para splited. La cantidad de memoria reservada es igual 
al número de subcadenas más 1.

4. if (!splited || !s) return (0);: Si no se puede reservar memoria para 
splited o si s es nulo, la función devuelve 0.

5. while (*s && *s == c) s++;: Ignora todos los caracteres delimitadores
 consecutivos en la cadena s y se pone al principio por si esta en el 
 primer caracter.

6. if (*s && *s != c) , se escribe la primera cadena con malloc words y 
despues nos movemos a la segunda cadena con el i++. ej (s[0][s] / s[1][s]).

7. Con el ultimo bucle while volvemos a llegar al final de la cadena en la 
que estabamos trabajando y se vuelve a repetir el gran buche while(*s).

8. Agregamos el NULL character a nuestro array of pointers creado y 
devolvemos splited
*/
