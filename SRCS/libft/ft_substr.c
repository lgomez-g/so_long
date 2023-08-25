/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franciscogomez <franciscogomez@student.42. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:04:41 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/04/25 13:07:52 by franciscogomez   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	substr_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	substr_len = ft_strlen(s + start);
	if (substr_len > len)
			substr_len = len;
	substr = (char *)malloc(sizeof(char) * (substr_len + 1));
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s + start, substr_len);
	substr[substr_len] = '\0';
	return (substr);
}

/*
1. substr_len = ft_strlen(s + start) ? / Se usa para desplazar s a start.

2. if (substr_len > len)
		substr_len = len; ? / Se usa por que si substr_len > len hay que
		                      recortarlo para poder que entre en la cadena.
*/
