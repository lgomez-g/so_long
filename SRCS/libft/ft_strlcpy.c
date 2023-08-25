/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franciscogomez <franciscogomez@student.42. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:54:39 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/04/25 15:31:47 by franciscogomez   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *source, size_t size)
{	
	size_t	len;
	size_t	i;

	len = ft_strlen(source);
	i = 0;
	if (size > 0)
	{
		while (*source && i < (size - 1))
		{
			*dest++ = *source++;
			i++;
		}
		*dest = '\0';
	}
	return (len);
}
