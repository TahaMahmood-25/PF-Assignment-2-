#include <stdio.h>
#include <string.h>

void encodeMessage(char message[]);
void decodeMessage(char message[]);

int main() {
    int choice;
    char message[100];
    printf("--- TCS Encoding / Decoding system ---");
    
    printf("Press 1 to encode a message \n");
    printf("Press 2 to decorde a message \n");
    printf("Press 3 to exit the program \n");
    scanf(" %d", &choice);
    getchar();

    switch (choice) {
    case 1:
        printf("Enter the message to encode: ");
        fgets(message, strlen(message), stdin);

        encodeMessage(message);
        printf("Encoded message: %s\n", message);
        break;
    case 2:
        printf("Enter the encrypted message to decode: ");
        fgets(message, strlen(message), stdin);
        
        decodeMessage(message);
        printf("Decoded message: %s\n", message);
        break;
    case 3:
        return 0;
        break;

    default:
        printf("Invalid choice - Retry ");
        break;
    }
}

void encodeMessage(char message[]) {
    int len = strlen(message);
    char temp;
    for (int i = 0; i < len/2; i++) {
        temp = message[i];
        message[i] = message[len - i - 1];
        message[len - i - 1] = temp;
    }
    
    int mask = (1 << 2) | (1 << 5);
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = message[i] ^ mask;
    }
}

void decodeMessage(char message[]) {
    int mask = (1 << 2) | (1 << 5);
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = message[i] ^ mask;
    }
    int len = strlen(message);
    int temp;
    for (int i = 0; i < len/2; i++) {
        temp = message[i];
        message[i] = message[len - i - 1];
        message[len - i - 1] = temp;
}
}