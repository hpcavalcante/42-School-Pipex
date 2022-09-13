/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment < hepiment@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:24:42 by hepiment          #+#    #+#             */
/*   Updated: 2022/06/18 16:23:26 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
