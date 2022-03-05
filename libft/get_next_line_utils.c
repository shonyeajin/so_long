#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*(s++))
		count++;
	return (count);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s1);
	if (n < len)
		len = n;
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (0);
	ft_strlcpy(dst, s1, len + 1);
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	src_len;

	idx = 0;
	src_len = 0;
	if (!dst || !src)
		return (0);
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize == 0)
		return (src_len);
	while (src[idx] && idx + 1 < dstsize)
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = '\0';
	return (src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	pre_len;
	size_t	suf_len;
	size_t	idx;
	char	*result;

	if (!s1 || !s2)
		return (0);
	idx = 0;
	pre_len = ft_strlen(s1);
	suf_len = ft_strlen(s2);
	result = malloc(pre_len + suf_len + 1);
	result[pre_len + suf_len] = '\0';
	while (s1[idx])
	{
		result[idx] = s1[idx];
		idx++;
	}
	idx = 0;
	while (s2[idx])
	{
		result[pre_len + idx] = s2[idx];
		idx++;
	}
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}
