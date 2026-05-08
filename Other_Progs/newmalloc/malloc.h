/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 18:55:43 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/30 14:20:56 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <sys/mman.h>
# include <sys/resource.h>
# include <unistd.h>
# include <stdlib.h>
//# include <libft.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#define TINY 512
#define SMALL 1024
#define PAGE getpagesize()


typedef struct		s_tab
{
	int				free;
	size_t			size;
	void			*ptr;
}					t_tab;

typedef struct		s_block
{
	struct s_block	*next;//next page 
	void			*page;//debut page
	void			*end;// fin 
	unsigned int	nbpage;//nombre de page self
	void			*my_next;//si nbpage > 1 next
}					t_block;

typedef struct		s_start
{
	t_block			*tiny;
	t_block			*small;
	t_block			*big;
}					t_start;
static t_start *g_start = NULL;
t_block **get_block_by_size(size_t size);
void	init_struct(void);
void	*add_last_block(t_block *add, t_block **start);
void				free(void *ptr);
void				*ft_malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem();
#endif
