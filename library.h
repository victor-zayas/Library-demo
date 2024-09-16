#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*book;
	struct s_list	*next;
}	t_list;

typedef struct s_book
{
	char    *title;
    char    *author;
    char    *year;
}	t_book;

void    add_book(char *title, char *author, int year);
void    remove_book(char *title);
void    list_books();
void    search_book(char *title);

#endif