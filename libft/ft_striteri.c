/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment < hepiment@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:15:24 by hepiment          #+#    #+#             */
/*   Updated: 2022/06/18 16:37:35 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int,
char*))
{
	size_t	count_size;

	count_size = 0;
	if (s == 0 || f == 0)
		return ;
	while (s[count_size] != '\0')
	{
		f(count_size, s + count_size);
		count_size++;
	}
}
