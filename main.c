#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    int id;
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount < MAX_BOOKS) {
        printf("Enter book title: ");
        scanf(" %[^\n]s", library[bookCount].title);
        printf("Enter author name: ");
        scanf(" %[^\n]s", library[bookCount].author);
        library[bookCount].id = bookCount + 1;
        printf("Book added with ID: %d\n", library[bookCount].id);
        bookCount++;
    } else {
        printf("Library is full!\n");
    }
}

void displayBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("\nLibrary Books:\n");
    int i;  // Declare i outside the loop
    for (i = 0; i < bookCount; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n2. Display Books\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice, try again!\n");
        }
    }
    return 0;
}

