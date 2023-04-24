/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:27:45 by yabad             #+#    #+#             */
/*   Updated: 2022/10/10 19:11:17 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// line 22 i starts with 0 and dstsize starts with 1
// TEST 1
// int	main()
// {
// 	char src[] = "coucou";
// 	char dest[10]; memset(dest, 'A', 10);

// 	printf("%zu\n", ft_strlcpy(dest, src, 0));
// 	printf("%s\n", dest);
// 	printf("%zu\n", strlcpy(dest, src, 0));
// 	printf("%s\n", dest);
// }
// TEST 2
// int	main()
// {
// 	char	string[] = "Hello there, Venus";
// 	char	buffer[] = "Hello back from Earth";
// 	char	stringp[] = "Hello there, Venus";
// 	char	bufferp[] = "Hello back from Earth";
// 	printf("%zu\n", ft_strlcpy(buffer, string, 10));
// 	printf("%s\n", buffer);
// 	printf("%zu\n", strlcpy(bufferp, stringp, 10));
// 	printf("%s\n", bufferp);
// }