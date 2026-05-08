/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 12:43:42 by REDACTED          #+#    #+#             */
/*   Updated: 2015/05/15 14:41:47 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H

# include <libft.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_puts(const char *s);
int		ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *s1, const char *s2);
void	*ft_memset(void *s, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
void	ft_cat(int fd);

char 	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnew(size_t size);
int		ft_strequ(char const *s1, char const *s2);
char	*ft_strjoin(const char *s1, const char *s2);

#endif
//%rdi, %rsi, %rdx, %rcx, %r8 and %r9
// strchr, strcmp, strequ
