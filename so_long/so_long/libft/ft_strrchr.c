/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:18:58 by user              #+#    #+#             */
/*   Updated: 2022/05/06 18:18:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*str_end;
	char	ch;

	str_end = ft_strchr(str, '\0');
	ch = (unsigned char) c;
	if (ch == '\0')
		return (str_end);
	str_end--;
	while (*str)
	{
		if (*str_end == ch)
			return (str_end);
		str++;
		str_end--;
	}
	return (NULL);
}
