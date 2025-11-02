#include <stdio.h>
#include <string.h>

void customerInfo();
void displayInventory(char productCode[][4], int productQty[4], int productPrice[4]);
void updateInventory();
void AddToCart(char productCode[][4], int productQty[4], int productPrice[4]);
void showInvoice();
void displayTotalBill(char productCode[][4], int productQty[4], int productPrice[4]);

char cartCodes[10][4];
int cartQty[10];
int cartPrices[10];
int cartCount = 0;

int main() {
    char productCode[4][4] = {"001","002","003","004"};
    int productQty[4] = {50,10,20,8};
    int productPrice[4] = {100,200,300,150};
    int choice; 


    
    while(1) {
    printf("--- Online Supermarket Management System ---\n");
    printf("Press 1 to enter user information \n");
    printf("Press 2 to view the inventory \n");
    printf("Press 3 to add item to your cart \n");
    printf("Press 4 to view total bill \n");
    printf("Press 5 to view envoice \n");
    printf("Press 6 to exit the system \n");
    scanf(" %d", &choice);
    getchar();

    switch (choice) {
    case 1:
        customerInfo();
        break;
    case 2:
        displayInventory(productCode, productQty, productPrice);
        break;
    case 3:
        AddToCart(productCode, productQty, productPrice);
        break;
    case 4:
        displayTotalBill(productCode, productQty, productPrice);
        break;
    case 5:
        showInvoice();
        break;
    case 6:
        printf("Exit \n");
        return 0;
        break;

    default:
        printf("Invalid Choice !");
        break;
    }
    }
return 0;
}

void customerInfo() {
    char username[50];
    char CNIC[50];
    printf("Enter your name \n");
    fgets(username, 50, stdin);
    username[strcspn(username, "\n")] = '\0';
    printf("Enter you CNIC \n");
    fgets(CNIC, 50, stdin);
    CNIC[strcspn(CNIC, "\n")] = '\0';
}

void displayInventory(char productCode[][4], int productQty[4], int productPrice[4]) {
    printf("=== INVENTORY ===\n");
    printf("Product code, Quantity in Stock, Price per product\n");
    
    for (int i = 0; i < 4; i++) {
        printf("%s, %d, %d\n", productCode[i], productQty[i], productPrice[i]);   
    }
}

void AddToCart(char productCode[][4], int productQty[4], int productPrice[4]) {
    char userCode[4];
    char userCart[4];
    int userQty;
    printf("Enter the Product code for the item that you want to add into cart \n");
    fgets(userCode, 4, stdin);
    userCode[strcspn(userCode, "\n")] = '\0';

    printf("Enter the quantity of your item \n");
    scanf(" %d", &userQty);
    getchar();

    if (userQty <= 0) {
        printf("Invalid quantity. \n");
        return;
    }

    
    for (int i = 0; i < 4; i++) {
        if (strcmp(productCode[i], userCode) == 0) {
            if (userQty > productQty[i]) {
            printf("Not enough stock \n");
            return;
            }
            productQty[i] = productQty[i] - userQty;
            
            for (int j = 0; j < userQty; j++) 
                userCart[j] = productCode[i];
        }
    strcpy(cartCodes[cartCount], userCode);
    cartQty[cartCount] = userQty;
    cartPrices[cartCount] = userQty * productPrice[i];
    cartCount++;

    printf("Item added to cart successfully!\n");
    return;
    }

}

void displayTotalBill(char productCode[][4], int productQty[4], int productPrice[4]) {
    int qty;
    char item[4], promocode[20];
    int price = 0;

    printf("Enter the product code for the item to order \n");
    fgets(item, 4, stdin);
    item[strcspn(item, "\n")] = '\0';


    printf("Enter the quantity of the item to order \n");
    scanf(" %d", &qty);
    getchar();

    printf("Enter promo-code if any, \n");
    fgets(promocode, strlen(promocode), stdin);

    for (int i = 0; i < 4; i++) {
        if (strcmp(productCode[i], promocode) == 0) {
            price = (productPrice[i]*qty);
            break;
        }
    }
        if (strcmp(promocode, "Eid2025") == 0) {
        price = price - (0.25 * price);
        }   
        printf("Total bill amount: %d\n", price);

}
    
void showInvoice() {
    printf("=== INVOICE ===\n");
    printf("Item Code | Quantity | Price\n");
    printf("--------------------------------");

    int total = 0;
    for (int i = 0; i < cartCount; i++) {
        printf("%s\t   %d\t   %d\n", cartCodes[i], cartQty[i], cartPrices[i]);
        total = total + cartPrices[i];
    }

    printf("Total bill: %d\n", total);
    printf("Thank you for shopping with us!\n\n");
}