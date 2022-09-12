/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment < hepiment@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:12:41 by hepiment          #+#    #+#             */
/*   Updated: 2022/06/17 18:12:44 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	count_size;

	str = ft_strdup((char *)s);
	if (!s || !f || !str)
		return (0);
	count_size = 0;
	while (str[count_size])
	{
		str[count_size] = f(count_size, str[count_size]);
		count_size++;
	}
	return (str);
}
