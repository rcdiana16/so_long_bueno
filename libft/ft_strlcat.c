/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:43:52 by diana             #+#    #+#             */
/*   Updated: 2024/10/16 15:27:59 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize == 0 || dstsize < dst_len)
	{
		return (src_len + dstsize);
	}
	i = 0;
	while (i + dst_len < dstsize - 1 && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
int main ()
{
	char dst[20] = "Diana";
	const char *src = "Hola";
	size_t dstsize = 2;

	size_t result = ft_strlcat(dst, src, dstsize);
	printf("concatenacion:%s\n", dst);
	printf("combinado:%zu\n", result);
	return (0);
}
