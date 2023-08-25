/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franciscogomez <franciscogomez@student.42. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:18:21 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/04/20 15:41:39 by franciscogomez   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	strsize;

	strsize = ft_strlen(s);
	d = (char *)malloc(strsize + 1);
	if (!d)
		return (0);
	ft_memcpy(d, s, strsize);
	d[strsize] = 0;
	return (d);
}
