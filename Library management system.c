#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure for Book
struct Book {
    int id;
    char title[100];
    char author[100];
    int isIssued;  // 0 for available, 1 for issued
};

// Global array to store books (max 100 for simplicity)
struct Book library[100];
int bookCount = 0;

// Function to add a new book
void addBook() {
    if (bookCount >= 100) {
        printf("Library is full!\n");
        return;
    }
    struct Book newBook;
    newBook.id = bookCount + 1;
    printf("Enter book title: ");
    scanf(" %[^\n]", newBook.title);  // Read full line including spaces
    printf("Enter author name: ");
    scanf(" %[^\n]", newBook.author);
    newBook.isIssued = 0;
    library[bookCount] = newBook;
    bookCount++;
    printf("Book added successfully!\n");
}

// Function to display all books
void displayBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("ID\tTitle\t\tAuthor\t\tStatus\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d\t%s\t\t%s\t\t%s\n", library[i].id, library[i].title, library[i].author, library[i].isIssued ? "Issued" : "Available");
    }
}

// Function to search for a book by title
void searchBook() {
    char searchTitle[100];
    printf("Enter book title to search: ");
    scanf(" %[^\n]", searchTitle);
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strstr(library[i].title, searchTitle) != NULL) {
            printf("Found: ID=%d, Title=%s, Author=%s, Status=%s\n", library[i].id, library[i].title, library[i].author, library[i].isIssued ? "Issued" : "Available");
            found = 1;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

// Function to issue a book
void issueBook() {
    int id;
    printf("Enter book ID to issue: ");
    scanf("%d", &id);
    if (id < 1 || id > bookCount) {
        printf("Invalid book ID.\n");
        return;
    }
    if (library[id-1].isIssued) {
        printf("Book is already issued.\n");
    } else {
        library[id-1].isIssued = 1;
        printf("Book issued successfully!\n");
    }
}

// Function to return a book
void returnBook() {
    int id;
    printf("Enter book ID to return: ");
    scanf("%d", &id);
    if (id < 1 || id > bookCount) {
        printf("Invalid book ID.\n");
        return;
    }
    if (!library[id-1].isIssued) {
        printf("Book was not issued.\n");
    } else {
        library[id-1].isIssued = 0;
        printf("Book returned successfully!\n");
    }
}

// Main function with menu
int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
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
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
