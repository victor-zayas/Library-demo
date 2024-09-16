#include "library.h"

t_list *book_list = NULL;

t_list  *create_node(t_book *book)
{
    t_list  *node;

    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->book = book;
    node->next = NULL;
    return (node);
}

t_book  *create_book(char *title, char *author, int year)
{
    t_book *book;
    char    fix_year[5];

    book = malloc(sizeof(t_book));
    if (!book)
        return (NULL);
    book->title = strdup(title);
    book->author = strdup(author);
    snprintf(fix_year, sizeof(fix_year), "%d", year);
    book->year = strdup(fix_year);
    return (book);
}

void    add_book(char *title, char *author, int year)
{
    t_list  *list;
    t_list  *tmp;
    t_book  *book;

    if (!title || !author || !year)
    {
        printf("There is one parameter incorect: [%s], [%s], [%d]\n", title, author, year);
        return ;
    }
    book = create_book(title, author, year);
    list = create_node(book);
    if (!book_list)
        book_list = list;
    else
    {
        tmp = book_list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = list;
    }
    printf("New book added: %s\n", title);
}

void    remove_book(char *title)
{
    t_list  *list;
    t_list  *prev;
    t_book  *book;

    list = book_list;
    prev = NULL;

    while (list != NULL)
    {
        book = list->book;

        if (strcmp(book->title, title) == 0)
        {
            if (prev == NULL)
                book_list = list->next;
            else
                prev->next = list->next;
        } 
        free(book->title);
        free(book->author);
        free(book->year);
        free(book);
        free(list);
        printf("Removed book: '%s'\n", title);
        return ;
    }
    prev = list;
    list = list->next;
}

void    list_books()
{

}

void    search_book(char *title)
{

}

int main(int argc, char **argv)
{
    if (argc != 4)
        return (0);
    else
    {
        add_book(argv[1], argv[2], atoi(argv[3]));
        remove_book(argv[1]);
        return (1);
    }
}