#include "malloc.h"

void 	*get_block(t_block *previous, size_t nb)// si reallloc getblock
{
	void *ret;
	(void)previous;
	puts("get_block");
	if (nb == 0)
	{
		 ret = mmap(0, PAGE, PROT_READ | PROT_WRITE, MAP_ANON |
			MAP_PRIVATE , -1, 0);
		 if (!ret)
		 	return (NULL);
		 ((t_block *)ret)->next = NULL;
		 ((t_block *)ret)->nbpage = 1;
		 ((t_block *)ret)->my_next = NULL;
	}
	//ajout realloc
	return (ret);
}

void	*get_page(size_t size)
{
	void	*add;
//	t_block *block;
	size_t	nbpage;
	t_block *block;

	block = get_block(NULL, 0);
	if (block == NULL)
		return (NULL);
	if (size <= TINY){
		add = mmap(0, PAGE * 13, PROT_READ | PROT_WRITE, MAP_ANON |
			MAP_PRIVATE , -1, 0);
		nbpage = 13; 
	}
	else if (size > TINY && size <= SMALL)
	{
		add =  mmap(0,  PAGE * 25, PROT_READ | PROT_WRITE, MAP_ANON |
			MAP_PRIVATE , -1, 0);//25 | 26?
		nbpage = 25;
	}
	//else
		//add = mmap(0, ((size + sizeof(t_mal) + sizeof(t_block))/ getpagesize()) + getpagesize(), PROT_READ |
		//		PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	//bzero(add, getpagesize() * 25);
	printf("fat page : %p - %p size : %lu\n", add , add + nbpage * PAGE-1, nbpage * PAGE);
	block->page = add;
	block->next = NULL;
	block->end = add + nbpage * PAGE -1;
	((t_tab *)((void *)block + sizeof(t_block)))->free = 1;
	((t_tab *)((void *)block + sizeof(t_block)))->size = nbpage * PAGE;
	((t_tab *)((void *)block + sizeof(t_block)))->ptr = add;
	assert(add);
//	puts("get_page");
	return (block);
}


void *split_memory(t_tab *mem, t_block *block, size_t size)
{
	t_tab *next;

	mem->free = 0;
	next = &mem[1];//((t_tab *)((void *)mem + sizeof(t_tab)));
	
	//ici realloc ssi nb page > taille page besoin de fonction pour determiner next ?
	if (mem->size > size)
	{
		next->free = 1;
		next->size = mem->size - size;
		next->ptr = (void*)(mem->ptr) + next->size ;
	}
	block->page++;
	mem->size = size;
	assert(mem);
	//printf("%p\n", mem->ptr);
	assert(mem);
	return (mem->ptr);
}

void	*find_alloc_on_page(t_block *page, size_t size)
{
	size_t nb;
	t_tab *i;
//	assert(page);
	//("page dans find_Alloc_onpage %p\n", page);
	while (page!= NULL)
	{

		i = (void*)&page[1]; //+ sizeof(t_block);
		printf("page dans find_Alloc_onpage %p :    i == %p\n", page, i);
		nb = page->nbpage + 1;
		while (nb > 0)
		{
			if (i->free == 1 && i->size >= size)
				return (split_memory(i, page, size));
			i++;
			nb--;
			//ici modulo ssi need realloc pour struct i = i->mynext
		}
		//abort();
		page = page ->next;
	}
	return (NULL);
}

void	*get_alloc_on_page(t_block *page, size_t size)//wrong
{
	void *ret;
	ret = find_alloc_on_page(page, size);
	if (ret)
		return (ret);
	add_last_block(get_page(size), get_block_by_size(size));
	ret = find_alloc_on_page(page, size);
	return (ret);
}

void	*get_alloc(t_block **block, size_t size)
{	
	printf("get alloc : %p\n", *block);
	if (*block == NULL){
		get_page(size);
		if (*block == NULL)
			return (NULL);
		ih = 
		printf("get alloc after get_block %p\n", *block);
		get_page(size, *block);
	}
	return (get_alloc_on_page(*block, size));
}

void	*ft_malloc(size_t size)
{
	(void)size;
//	char *s = mmap(0, (getpagesize() * 25), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE , -1, 0);
	static int t = 0;
	if (!t)
		init_struct();
	t = 1;
	puts("debut");
//	return (get_alloc(get_block_by_size(size), size));
void *ti = get_alloc(get_block_by_size(size), size);
printf("return %p\n", ti);
return (ti);
}
