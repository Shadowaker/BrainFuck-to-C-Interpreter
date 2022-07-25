/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:15:49 by dridolfo          #+#    #+#             */
/*   Updated: 2022/07/25 17:08:08 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bf.h"

/* Compare S1 with S2 for N bytes or untill one char is different.
RETURNS: 0 or != 0 if they are not identical.*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	else
	{
		while (s1[i] == s2[i] && i < n - 1)
		{
			if (s1[i] == '\0' || s2[i] == '\0')
				break ;
			i++;
		}
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
