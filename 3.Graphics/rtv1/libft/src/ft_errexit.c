/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errexit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 07:37:13 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/28 07:38:00 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_errexit(const char *message, char *color, int code)
{
	ft_putstr_color((char*)message, color);
	ft_putchar(10);
	exit(code);
}
