/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment < hepiment@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 21:57:22 by hepiment          #+#    #+#             */
/*   Updated: 2022/06/15 13:16:22 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	count_size;

	count_size = 0;
	if (str == NULL)
		return (0);
	while (str[count_size])
		count_size++;
	return (count_size);
}
