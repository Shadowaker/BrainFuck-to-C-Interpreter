/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:21:09 by dridolfo          #+#    #+#             */
/*   Updated: 2022/07/25 19:07:26 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bf.h"

/*
RETURNS: 0 if C not in STACK else 1. */
int	ft_isinstr(const char *stack, char c)
{
	int	i;

	i = 0;
	while (stack[i] != '\0')
	{
		if (stack[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/* Replace a STACK (char *) with '' in an S (char *)
RETURNS: a freeable pointer to the result.*/
char	*ft_replace(const char *s, char *stack)
{
	size_t	i;
	size_t	cnt;
	int		size;
	char	*res;

	i = -1;
	cnt = 0;
	while (++i < ft_strlen(s))
	{
		if (ft_isinstr(stack, s[i]) == 1)
			cnt++;
	}
	size = ft_strlen(s) - cnt;
	res = malloc(size);
	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (ft_isinstr(stack, s[i]) == 0)
			res[cnt++] = s[i];
		i++;
	}
	res[cnt] = '\0';
	return (res);
}

