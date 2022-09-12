/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment < hepiment@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 08:29:32 by hepiment          #+#    #+#             */
/*   Updated: 2022/06/18 16:41:33 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_l;
	size_t	src_l;

	i = 0;
	dest_l = ft_strlen(dest);
	src_l = ft_strlen(src);
	if (size < dest_l + 1)
		return (size + src_l);
	if (size >= dest_l + 1)
	{
		while (dest_l + i < size - 1 && src[i] != '\0')
		{
			dest[dest_l + i] = src[i];
			i++;
		}
	}
	dest[dest_l + i] = '\0';
	return (dest_l + src_l);
}
