#ifndef LIBRARY_H
# define LIBRARY_H

// Defines
#define MAX_INPUT 256

// Includes
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

// Structs
typedef struct s_book
{
	char    *title;
    char    *author;
    char     *year;
}	t_book;

typedef struct s_list
{
	t_book			*book;
	struct s_list	*next;
}	t_list;


// Prototypes
t_list  *create_node(t_book *book);
t_book  *create_book(char *title, char *author, int year);

void    add_book(char *title, char *author, int year);
void    remove_book(char *title);
void    list_books();
void    search_book(char *title);

#endif