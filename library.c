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

    book = malloc(sizeof(t_book));
    if (!book)
        return (NULL);
    book->title = title;
    book->author = author;
    book->year = year;
    return (book);
}

void    add_book(char *title, char *author, int year)
{
    t_list  *list;
    t_book  *book;

    if (!title || !author || !year)
        return ;
    book = create_book(title, author, year);
    list = create_node(book);
    if (!book_list)
        book_list = list;
    else
    {
        t_list *tmp = book_list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = list;
    }
    printf("New book added: %s\n", title);
}

void    remove_book(char *title)
{

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
        return (1);
    }
}