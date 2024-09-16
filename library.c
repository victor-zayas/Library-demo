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

void remove_book(char *title) {
    t_list *list = book_list;
    t_list *prev = NULL;
    t_book *book;

    while (list != NULL) {
        book = list->book;

        if (strcmp(book->title, title) == 0) {
            if (prev == NULL)
                book_list = list->next;
            else
                prev->next = list->next;

            free(book->title);
            free(book->author);
            free(book->year);
            free(book);
            free(list);
            printf("Removed book: '%s'\n", title);
            return;
        }
        prev = list;
        list = list->next;
    }
    printf("Book not found: '%s'\n", title);
}

void    list_books()
{
    t_list  *list;
    t_book  *book;

    list = book_list;
    if (!list)
    {
        printf("There are no book yet\n");
        return ;
    }
    while (list != NULL)
    {
        book = list->book;
        printf("Title: '%s', Author: '%s', Year: '%s'\n", book->title, book->author, book->year);
        list = list->next;
    }
}

void    search_book(char *title)
{
    t_list  *list;
    t_book  *book;

    list = book_list;
    while(list != NULL)
    {
        book = list->book;
        if (strcmp(book->title, title) == 0)
        {
            printf("Book founded!\n Title: '%s', Author: '%s', Year: '%s'\n", book->title, book->author, book->year);
            return ;
        }
        list = list->next;
    }
    printf("Book not found: '%s'\n", title);
}

int main()
{
    char input[MAX_INPUT];
    char command[16], title[256], author[256];
    int year;

    while (1)
    {
        printf("\nEnter command (add, list, search, remove, quit): ");
        if (fgets(input, sizeof(input), stdin) == NULL) // get imput
            break;                                      // breaks on error
        
        input[strcspn(input, "\n")] = '\0'; // clean \n on endline

        if (sscanf(input, "%15s", command) != 1) // split command and arguments
        {
            printf("Invalid command.\n");
            continue;
        }
        
        if (strcmp(command, "quit") == 0)
            break;
        else if (strcmp(command, "add") == 0)
        {
            printf("Enter title: ");
            if (fgets(title, sizeof(title), stdin) == NULL)
                continue;
            title[strcspn(title, "\n")] = '\0';
            printf("Enter author: ");
            if (fgets(author, sizeof(author), stdin) == NULL)
                continue;
            author[strcspn(author, "\n")] = '\0';
            printf("Enter year: ");
            if (scanf("%d", &year) != 1)
            {
                printf("Invalid year.\n");
                while (getchar() != '\n');
                continue;
            }
            while (getchar() != '\n');
            add_book(title, author, year);
        }
        else if (strcmp(command, "list") == 0)
            list_books();
        else if (strcmp(command, "search") == 0)
        {
            printf("Enter title to search: ");
            if (fgets(title, sizeof(title), stdin) == NULL) continue;
            title[strcspn(title, "\n")] = '\0';

            search_book(title);
        }
        else if (strcmp(command, "remove") == 0)
        {
            printf("Enter title to remove: ");
            if (fgets(title, sizeof(title), stdin) == NULL) continue;
            title[strcspn(title, "\n")] = '\0';

            remove_book(title);
        }
        else
            printf("Unknown command.\n");
    }

    while (book_list != NULL) {
        t_list *temp = book_list;
        book_list = book_list->next;

        free(temp->book->title);
        free(temp->book->author);
        free(temp->book->year);
        free(temp->book);
        free(temp);
    }

    printf("Exiting...\n");
    return 0;
}
