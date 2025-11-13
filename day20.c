#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char title[30];
    char author[30];
    int pages;
    float price;
} Book;

// 
void pushing(Book *books, int getSize) {
    int i = 0;
    printf("\nLet's fill your library with some books!\n");
    while (i < getSize) {
        printf("\n--- Book %d ---\n", i + 1);
        printf("→ Enter the book title: ");
        scanf("%s", books[i].title);
        printf("→ Enter the author's name: ");
        scanf("%s", books[i].author);
        printf("→ Number of pages: ");
        scanf("%d", &books[i].pages);
        printf("→ Price ($): ");
        scanf("%f", &books[i].price);
        printf("----------------------------\n");
        i++;
    }
}
//
void display(Book *books, int getSize) {
    int i = 0, check;
    printf("\nWould you like to see your library? (1 = yes / 0 = no): ");
    scanf("%d", &check);

    if (check == 1) {
        printf("\n====== Your Library ======\n");
        while (i < getSize) {
            printf("%d. %s | %s | %d pages | $%.2f\n", 
                   i + 1, books[i].title, books[i].author, books[i].pages, books[i].price);
            i++;
        }
        printf("==============================\n");
    } else {
        printf("\nNo worries! Your library is safely stored.\n");
    }
    printf("\nibrary setup complete!\n");

}
// 
void totalPrice(Book *books, int getSize) {
    int i = 0;  
    float totalPrice = 0;

    while (i < getSize) {
        totalPrice += books[i].price;
        i++;
    }   
    printf("\nTotal cost of all books: $%.2f\n", totalPrice);
}
//
int main() {
    int size; 
    Book *books;

    printf("How many books would you like to add to your library? ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Hmm... %d books? Maybe start your library later!\n", size);
        return 0;
    }

    books = malloc(sizeof(*books) * size);
    if (books == NULL) {
        printf("Memory allocation failed!");
        return EXIT_FAILURE;
    }
    
    pushing(books, size);
    display(books, size);
    totalPrice(books, size);
    
    free(books);
    printf("\nThanks for using the mini library manager!\n");

    return 0;
}