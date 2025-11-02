#include <stdio.h>


void QuerrySectorStatus(int r,int c, int myArr[r][c]);
void SystemDiagnositcs(int r,int c, int myArr[r][c]);
void UpdateSectorStatus(int r, int c, int myArr[r][c]);

int main() {
    int rows, cols, choice;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int arr[rows][cols];

    printf("\nEnter values from 0 to 7 only):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            do {
                printf("arr[%d][%d] = ", i, j);
                scanf("%d", &arr[i][j]);

                if (arr[i][j] < 0 || arr[i][j] > 7)
                    printf("Invalid Enter between 0-7\n");

            } while (arr[i][j] < 0 || arr[i][j] > 7);
        }
    }
    
    printf("-;-- IESCO POWER GRID MONITORING SYSTEM ---\n");
    printf("\nPress 1 to view the Querry Sector Status ");
    printf("\nPress 2 to Update Sector Status");
    printf("\nPress 3 to Run System Diagnostics ");

    scanf(" %d", &choice);
    
    switch (choice) {
    case 1:
        QuerrySectorStatus(rows, cols, arr);
        break;
    case 2:
        UpdateSectorStatus(rows, cols, arr);
        break;
    case 3:
        SystemDiagnositcs(rows, cols, arr);
        break;
    default:
        printf("Invalid choice - Retry !");
        break;
    }

    
}

void QuerrySectorStatus(int r,int c, int myArr[r][c]) {
    int row, col;

    printf("Enter row and column of the sector to query: ");
    scanf("%d", &row);
    scanf(" %d", &col);

    if (row >= r || col >= c) {
        printf("Invalid coordinates!\n");
        return;
    }

    if ((myArr[row][col] & (1 << 0)) == 0)
        printf("Power Status: OFF\n");
    else
        printf("Power Status: ON\n");

    if ((myArr[row][col] & (1 << 1)) == 0)
        printf("Overload Status: NORMAL\n");
    else
        printf("Overload Status: OVERLOAD\n");

    if ((myArr[row][col] & (1 << 2)) == 0)
        printf("Maintenance: NOT REQUIRED\n");
    else
        printf("Maintenance: REQIURED\n");

}

void UpdateSectorStatus(int r, int c, int myArr[r][c]) {
    int row , col, flag, action;
    printf("Enter row and column of the sector: ");
    scanf("%d %d", &row, &col);

    if (row >= r || col >= c) {
        printf("Invalid coordinates");
        return;
    }
    printf("Select flag to update:\n");
    printf("0 - Power Status\n");
    printf("1 - Overload Warning\n");
    printf("2 - Maintenance Required\n");
    scanf("%d", &flag);

    printf("Enter 1 to SET the bit or Enter 0 to CLEAR the bit: ");
    scanf("%d", &action);

    if (action == 1) {
        myArr[row][col] |= (1 << flag);
    }
    else {
        myArr[row][col] &= ~(1 << flag);
    }

     printf("Sector [%d][%d] updted successfully.\n", row, col);
}

void SystemDiagnositcs(int r,int c, int myArr[r][c]) {
    int overloadCount = 0;
    int maintainanceCount = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if ((myArr[i][j] & (1 << 1)) != 0) {
                overloadCount++;    
            }
            if ((myArr[i][j] & (1 << 2)) != 0)   {
                maintainanceCount++;
            }
        }
    }
    printf("\n%d sectors are overloaded ",overloadCount);
    printf("\n%d sectors require maintainance ",maintainanceCount);
}
