#include <stdio.h>

int main() {
    int exit = 0,
        inventoryQuantity = 50,
        selectedAction,
        selectedActionQuantity;

    do {
        printf("******** Welcome to Inventory Management System ********\n\n");
        printf("Please select what you want to do.\n 1 - Add item \n 2 - Remove item \n 3 - Check quantity of current items \n 4 - Exit\n");
        scanf("%d", &selectedAction);

        if (selectedAction == 1 || selectedAction == 2) {
            printf("How many items: \n");
            scanf("%d", &selectedActionQuantity);

            if (selectedActionQuantity < 0) {
                printf("Invalid quantity. Please enter a non-negative value.\n");
                continue;
            }
        } else if (selectedAction < 1 || selectedAction > 4) {
            printf("Please select a valid action\n");
            continue;
        }

        switch (selectedAction) {
            case 1:
                inventoryQuantity += selectedActionQuantity;
                printf("Item has been added\n");
                break;
            case 2:
                if (selectedActionQuantity > inventoryQuantity) {
                    printf("Error: Cannot remove more items than in inventory.\n");
                } else {
                    inventoryQuantity -= selectedActionQuantity;
                    printf("Item has been removed\n");
                }
                break;
            case 3:
                printf("Currently %d items are present\n", inventoryQuantity);
                break;
            case 4:
                printf("Exiting Program, Goodbye!\n");
                exit = 1;
                break;
            default:
                printf("Unknown Error, please try again\n");
                break;
        }
    } while (exit == 0);

    return 0;
}
