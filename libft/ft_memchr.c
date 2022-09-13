/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment < hepiment@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:40:40 by hepiment          #+#    #+#             */
/*   Updated: 2022/06/18 16:13:32 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	char_c;
	unsigned char	*cstr;

	char_c = (unsigned char)c;
	cstr = (unsigned char *)str;
	while (n--)
	{
		if (*cstr == char_c)
		{
			return (cstr);
		}
		cstr++;
	}
	return (0);
}
