/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment < hepiment@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:30:55 by hepiment          #+#    #+#             */
/*   Updated: 2022/06/18 17:01:26 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	lenght_s1;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1) != NULL)
		s1++;
	lenght_s1 = ft_strlen(s1);
	while (lenght_s1 && ft_strchr(set, s1[lenght_s1]))
		lenght_s1--;
	return (ft_substr((char *)s1, 0, lenght_s1 + 1));
}
