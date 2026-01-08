#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char name[50];
    char author[50];
    int qty;
};

void addBook() {
    FILE *fp = fopen("library.csv", "a");
    struct Book b;

    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    printf("Enter Book Name: ");
    scanf(" %[^\n]", b.name);
    printf("Enter Author Name: ");
    scanf(" %[^\n]", b.author);
    printf("Enter Quantity: ");
    scanf("%d", &b.qty);

    fprintf(fp, "%d,%s,%s,%d\n", b.id, b.name, b.author, b.qty);
    fclose(fp);

    printf("Book Added Successfully\n");
}

void displayBooks() {
    FILE *fp = fopen("library.csv", "r");
    char line[200];

    printf("\nBookID\tBook Name\tAuthor\t\tQuantity\n");
    while (fgets(line, sizeof(line), fp)) {
        struct Book b;
        sscanf(line, "%d,%[^,],%[^,],%d",
               &b.id, b.name, b.author, &b.qty);
        printf("%d\t%s\t%s\t%d\n",
               b.id, b.name, b.author, b.qty);
    }
    fclose(fp);
}

void searchBook() {
    FILE *fp = fopen("library.csv", "r");
    int id, found = 0;
    char line[200];

    printf("Enter Book ID to Search: ");
    scanf("%d", &id);

    while (fgets(line, sizeof(line), fp)) {
        struct Book b;
        sscanf(line, "%d,%[^,],%[^,],%d",
               &b.id, b.name, b.author, &b.qty);
        if (b.id == id) {
            printf("Book Found: %s by %s (Qty: %d)\n",
                   b.name, b.author, b.qty);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found)
        printf("Book Not Found\n");
}

void issueBook() {
    FILE *fp = fopen("library.csv", "r");
    FILE *temp = fopen("temp.csv", "w");
    int id;
    char line[200];

    printf("Enter Book ID to Issue: ");
    scanf("%d", &id);

    while (fgets(line, sizeof(line), fp)) {
        struct Book b;
        sscanf(line, "%d,%[^,],%[^,],%d",
               &b.id, b.name, b.author, &b.qty);

        if (b.id == id && b.qty > 0) {
            b.qty--;
            printf("Book Issued Successfully\n");
        }
        fprintf(temp, "%d,%s,%s,%d\n",
                b.id, b.name, b.author, b.qty);
    }

    fclose(fp);
    fclose(temp);
    remove("library.csv");
    rename("temp.csv", "library.csv");
}

int main() {
    int choice;

    do {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: addBook(); break;
        case 2: displayBooks(); break;
        case 3: searchBook(); break;
        case 4: issueBook(); break;
        case 5: printf("Exiting...\n"); break;
        default: printf("Invalid Choice\n");
        }
    } while (choice != 5);

    return 0;
}