/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshon <yshon@student.42seoul.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:54:06 by yshon             #+#    #+#             */
/*   Updated: 2021/05/18 11:57:42 by yshon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n == INT_MIN)
		return (ft_putstr_fd("2147483648", fd));
	if (n < 0)
		n *= (-1);
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd("0123456789"[n % 10], fd);
}
