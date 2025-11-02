#include <stdio.h>
#include <string.h>

int AddNewBook (int isbns[100], char titles[100][50], float prices[100], int quantities[100], int *count);
int ProcessSale (int isbns[100], char titles[100][50], float prices[100], int quantities[100], int *count);
int LowStockReport (int isbns[100], char titles[100][50], float prices[100], int quantities[100], int *count);

int main() {

    int choice;
    int ISBNS[100] = {0};
    char titles[100][50] = {{0}};
    float prices[100] = {0.0f};
    int quantities[100] = {0};

    int count = 0;

    while(1) {
    printf("--- Liberty Books Online System ---\n");
    
    printf("Press 1 to add a new book \n");
    printf("Press 2 to process the sale of a book \n");
    printf("Press 3 to add generate a low-stock report \n");
    printf("0. Exit\n");
    scanf(" %d", &choice);
    getchar();

    switch (choice) {
    case 1:
        AddNewBook(ISBNS, titles, prices, quantities, &count);
        break;
    case 2:
        ProcessSale(ISBNS, titles, prices, quantities, &count);
        break;
    case 3:
        LowStockReport(ISBNS, titles, prices, quantities, &count);
        break;
    case 0:
        return 0;
    
    default:
        printf("Invalid choice - Retry");
        break;
    }
}
}

int AddNewBook (int isbns[100], char titles[100][50], float prices[100], int quantities[100], int *count) {
    
    int ISBN;
    
    printf("Enter the ISBN for the new book \n");
    scanf(" %d", &ISBN);

    int lenISBN = sizeof(isbns)/sizeof(isbns[0]);

    for (int i = 0; i < *count; i++) {
        if (isbns[i] == ISBN) {
            printf("A book with same ISBN number already exists ... \n");
            return 0;
        }
    }
    isbns[*count] = ISBN;


    
    printf("Enter the title of the book \n");
    int ch = getchar();
    fgets(titles[*count], 50, stdin);
    titles[*count][strcspn(titles[*count], "\n")] = '\0';

    float price;
    printf("Enter the price of the book \n");
    scanf(" %f", &price);
    prices[*count] = price;

    int qty;
    printf("Enter the quantity of the book to be added \n");
    scanf(" %d", &qty);
    quantities[*count] = qty;

    (*count)++;
    printf("Book added successfully. Total books: %d\n", *count);
    return 1;
}   

int ProcessSale (int isbns[100], char titles[100][50], float prices[100], int quantities[100], int *count) {
    int bookISBN;
    int bookqty;
    printf("Enter the ISBN of the book to purchase \n");
    scanf(" %d", &bookISBN);
    printf("How many copies of the book do you want to purchase? \n");
    scanf(" %d", &bookqty);

    for (int i = 0; i < (*count); i++) {
        if (isbns[i] == bookISBN) {
            quantities[i] = quantities[i] - bookqty;
            return 1;
    
        }
        if (bookqty <= 0) { 
        printf("Invalid quantity.\n");
        return 0; }
        if (quantities[*count] < bookqty) { 
        printf("Insufficient stock. Available: %d\n", quantities[*count]);
        return 0; }

        printf("Sale processed. Remaining: %d\n", quantities[*count]);
        return 1;
    }   
}

int LowStockReport (int isbns[100], char titles[100][50], float prices[100], int quantities[100], int *count) {
    int foundCount = 0;

    for (int i = 0; i < *count; i++) {
        if (quantities[i] < 5) {
            printf("The books containing ISBNs %d have quantities less than 5 (Quantity left: %d)", isbns[i], quantities[i]);
            foundCount++;
        }
        if (foundCount == 0) {
            printf("No low-stock books");
        }
        
    }
    return foundCount;
}