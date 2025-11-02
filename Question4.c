#include <stdio.h>

int push(int stack[], int top, int max);
int pop(int stack[], int top, int max);
int peek(int stack[], int top);
int display(int stack[], int top,int max);

int main() {
    int stack[10];
    int top = -1;
    int max = 10;
    int choice;

    printf("--- Stack implementation program ---\n");
    printf("Press 1 to PUSH data into the stack \n");
    printf("Press 2 to POP data from the stack \n");
    printf("Press 3 to PEEK to the top-most element of the stack \n");
    printf("Press 4 to DISPLAY all the elements of the stack \n");
    printf("Press 0 to exit");
    scanf(" %d", &choice);

    while (1) {
    switch (choice) {
    case 1:
        top = push(stack,top, max);
        printf("%d", top);
        break;
    case 2:
         pop(stack,top, max);
        break;
    case 3:
        peek(stack, top);
        break;
    case 4:
        display(stack,top, max);
        break;
    case 0:
        return 0;
    default:
        printf("Invalid choice - Retry !");
        break;
    }
    }
}

int push(int stack[], int top, int max) {
    if (top == max - 1) {
        printf("The stack is already full !");
    }
    else {
        int value;
        printf("Enter an integer value to enter ");
        scanf(" %d", &value);
        
        top = top + 1;
        stack[top] = value;
        printf("The value has been PUSHED to index position %d\n", top);
        return top;
    }
}

int pop(int stack[], int top, int max) {
    if (top == -1) {
        printf("The stack is already empty !");
    }
    else {
        int value;
        value = stack[top];
        printf("The value %d has been POPPED from the index position %d", value, top);
        top = top - 1;
    }
}

int peek(int stack[], int top) {
    if (top == -1) {
        printf("The stack is empty !");
    }
    else {
        int value;
        value = stack[top];
        printf("The value on the index position %d is %d ", top, stack[top]);
    }
}

int display(int stack[], int top, int max) {
    for (int i = 0; i < max; i++) {
        printf("The contents of the stack on the index %d are: %d", i, stack[i]);
    }
}
