#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 100

int Password = 491625;
int isAdmin = 0;

typedef struct
{
    int id;
    char title[MAXSIZE];
    char author[MAXSIZE];
    int available;
} Book;

typedef struct
{
    int userId;
    char name[MAXSIZE];
    char password[MAXSIZE];
} User;

typedef struct
{
    char name[MAXSIZE];
} Admin;

void addBook()
{
    if (!isAdmin)
    {
        printf("\nOnly admins are allowed to add books.\n");
        return;
    }

    Book book;
    FILE *fptr;
    fptr = fopen("books.txt", "ab");

    if (fptr == NULL)
    {
        printf("Error, file doesn't exist!\n");
        return;
    }

    printf("Enter Book id: ");
    scanf("%d", &book.id);
    getchar();
    printf("Enter Title: ");
    fgets(book.title, MAXSIZE, stdin);
    book.title[strcspn(book.title, "\n")] = '\0';
    printf("Enter Author: ");
    fgets(book.author, MAXSIZE, stdin);
    book.author[strcspn(book.author, "\n")] = '\0';

    book.available = 1;

    fwrite(&book, sizeof(Book), 1, fptr);
    fclose(fptr);
    printf("\nBook added successfully!\n");
}

void displayBooks()
{
    FILE *fptr = fopen("books.txt", "rb");
    if (fptr == NULL)
    {
        printf("\nNo books found.\n");
        return;
    }

    Book book;
    printf("\nAvailable Books:\n");
    printf("-----------------------------\n");
    while (fread(&book, sizeof(Book), 1, fptr))
    {
        printf("\nID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n\n",
               book.id, book.title, book.author,
               book.available ? "Available" : "Issued");
    }
    fclose(fptr);
}
void issueBook()
{
    int bookId, found = 0;
    Book book;
    FILE *fptr = fopen("books.txt", "rb+");

    if (fptr == NULL)
    {
        printf("\nNo books found.\n");
        return;
    }

    printf("Enter Book ID to issue: ");
    scanf("%d", &bookId);

    while (fread(&book, sizeof(Book), 1, fptr))
    {
        if (book.id == bookId)
        {
            found = 1;
            if (book.available)
            {
                book.available = 0;
                fseek(fptr, -sizeof(Book), SEEK_CUR);
                fwrite(&book, sizeof(Book), 1, fptr);
                printf("\nBook issued successfully.\n");
            }
            else
            {
                printf("\nBook is already issued.\n");
            }
            break;
        }
    }

    if (!found)
    {
        printf("\nBook with ID %d is not found.\n", bookId);
    }
    fclose(fptr);
}
void returnBook()
{
    int bookId, found = 0;
    Book book;
    FILE *fptr = fopen("books.txt", "rb+");

    if (fptr == NULL)
    {
        printf("\nNo books found.\n");
        return;
    }

    printf("Enter Book ID to return: ");
    scanf("%d", &bookId);

    while (fread(&book, sizeof(Book), 1, fptr))
    {
        if (book.id == bookId)
        {
            found = 1;
            if (!book.available)
            {
                book.available = 1;
                fseek(fptr, -sizeof(Book), SEEK_CUR);
                fwrite(&book, sizeof(Book), 1, fptr);
                printf("\nBook returned successfully.\n");
            }
            else
            {
                printf("\nThis book was not issued.\n");
            }
            break;
        }
    }

    if (!found)
    {
        printf("\nBook with ID %d not found.\n", bookId);
    }
    fclose(fptr);
}

void registerUser()
{
    User user;
    FILE *fptr = fopen("users.txt", "ab");
    if (fptr == NULL)
    {
        printf("Error opening users file.\n");
        return;
    }
    printf("Enter User id: ");
    scanf("%d", &user.userId);
    getchar();
    printf("Enter name: ");
    fgets(user.name, MAXSIZE, stdin);
    user.name[strcspn(user.name, "\n")] = '\0';

    printf("Enter password: ");
    fgets(user.password, MAXSIZE, stdin);
    user.password[strcspn(user.password, "\n")] = '\0';

    fwrite(&user, sizeof(user), 1, fptr);
    fclose(fptr);
    printf("\nUser is registered succesfully!\n");
}

int loginUser()
{
    User user;
    int userId;

    printf("Enter your User ID: ");
    scanf("%d", &userId);
    getchar();

    char password[MAXSIZE];
    printf("Enter your password: ");
    fgets(password, MAXSIZE, stdin);
    password[strcspn(password, "\n")] = '\0';

    FILE *fptr = fopen("users.txt", "r");

    if (fptr == NULL)
    {
        printf("Error opening users file.\n");
        return 0;
    }

    while (fread(&user, sizeof(user), 1, fptr))
    {
        if (user.userId == userId && strcmp(user.password, password) == 0)
        {
            printf("\nLogin successful! Welcome, %s.\n", user.name);
            fclose(fptr);
            return 1;
        }
    }
    printf("Invalid credentials.\n");
    fclose(fptr);
    return 0;
}

void loginAdmin()
{
    Admin admin;
    printf("Enter Name: ");
    fgets(admin.name, sizeof(admin.name), stdin);
    admin.name[strcspn(admin.name, "\n")] = '\0';

    int passwordEntered;
    printf("Enter Admin Password (as integer): ");
    scanf("%d", &passwordEntered);
    getchar();

    if (passwordEntered == Password)
    {
        printf("\nYou are Logged in as Admin!\n");
        isAdmin = 1;
        return;
    }
    printf("\nAdmin Password is Incorrect!, Make sure you are an admin and not a user.\n");
}

void exitingUser()
{
    printf("\nThank you for using our system. Hope to see you Again!\n");
    exit(0);
}

int main()
{
    int choice;
    int loggedIn = 0;

    printf("Are you a user or a admin?\n"); // 0 for user and 1 for admin...
    int input;
    scanf("%d", &input);
    getchar();

    while (1)
    {
        if (input == 0)
        {
            if (!loggedIn)
            {
                printf("\nLibrary Management System\n");
                printf(" 1. Register\n 2. Login\n 3. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    registerUser();
                }
                else if (choice == 2)
                {
                    loggedIn = loginUser();
                }
                else if (choice == 3)
                {
                    exitingUser();
                }
                else
                {
                    printf("Invalid choice! Try again.\n");
                }
            }
            else
            {
                printf("\nWelcome to Library Features:\n");
                printf(" 1. Display Books\n 2. Issue Book\n 3. Return Book\n 3. Logout\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    displayBooks();
                    break;
                case 2:
                    issueBook();
                    break;
                case 3:
                    returnBook();
                    break;
                case 4:
                    loggedIn = 0;
                    printf("Logged out successfully.\n");
                    break;
                default:
                    printf("Invalid choice! Try again.\n");
                }
            }
        }
        else if (input == 1)
        {
            if (!loggedIn)
            {
                printf("\nLibrary Management System (Admin Mode)\n");
                loginAdmin();
                loggedIn = isAdmin;
            }
            else
            {
                printf("\nWelcome to Admin Features:\n");
                printf(" 1. Add Book\n 2. Display Books\n 3. Logout\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                getchar();

                switch (choice)
                {
                case 1:
                    addBook();
                    break;
                case 2:
                    displayBooks();
                    break;
                case 3:
                    loggedIn = 0;
                    isAdmin = 0;
                    printf("Admin logged out successfully.\n");
                    break;
                default:
                    printf("Invalid choice! Try again.\n");
                }
            }
        }
        else
        {
            printf("\nInvalid user type. Please restart the program and enter 0 or 1.\n");
            break;
        }
    }
    return 0;
}
