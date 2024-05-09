#include <stdio.h>
#include <string.h>

//Shows all the available items and their info
void itemShowcase(char items[30][50], float prices[30], int quantity[30]) {
    for (int i = 0; i < 30; i++) {
        printf("%d. %s\nPrice: $%.1f\nQuantity: %d\n\n\n", i, items[i], prices[i], quantity[i]);
    }
}



int rentDuration;

void askUser(char selectedItemsArray[30][50], 
    float selectedItemsPrice[30],//Price of selected items will be stored here
    int selectedItemsQty[30], //Number of selected items will be stored here
    int *x,//A common index for all arrays
    float camping_equipment_prices[30], //Prices of available products
    int camping_quantities[30], //Quantities of camping equipment
    char camping_equipment[30][50])//Our camping equipments
    {
    char quitCondition;//Used to ask if the user wants another item
    int emptyArrayQty;//Input of number of items

    while (1) {
        int itemSelect;//Selects a serial number of a product from the list
        while(1){
        printf("Enter the product's serial number: ");
        scanf("%d",&itemSelect);
        if(itemSelect<0||itemSelect>29){//Condition for checking the correct range
        printf("Invalid input. Enter again: ");
        }else{
            break;
        }
    }
        if (camping_quantities[itemSelect] <= 0) {//Checks the quantity of the seleected item
            printf("Out of stock.\n");
            continue;
        }
        //Showcase of the item details
        printf("Item is in stock.\n");
        printf("Item Selected: %s\n", camping_equipment[itemSelect]);
        printf("Item Price: %.2f\n", camping_equipment_prices[itemSelect]);
        printf("Available Quantity: %d\n\n\n", camping_quantities[itemSelect]);
        
               //Destination            //To be copied from here
        strcpy(selectedItemsArray[*x], camping_equipment[itemSelect]);/*Strcpy is used to copy the selected item(string)
        from the items menu to the selected item menu*/
        selectedItemsPrice[*x] = camping_equipment_prices[itemSelect];/*Initially, x is at 0. So, the first item copied from the
        items array will be placed at 0, and so on*/
        int i = 0;
        //Keeps asking for the quantity until an appropriate response is given
        while (i == 0) {
            printf("How many do you want? ");
            scanf("%d",&emptyArrayQty);
            if(emptyArrayQty>camping_quantities[itemSelect]||emptyArrayQty<=0){
                printf("Invalid. Re-enter: ");
            }else{
            selectedItemsQty[*x] = emptyArrayQty;//Quantity is saved in the x index of the selected items quantity array
            break;
            }
        }
        (*x)++; //Pointer is first dereferenced then incremented
        
        //Loop for asking ti continue or not
        while (1) {
            printf("Do you want another item?\ny for yes\nn for no\nEnter: ");
            if (scanf(" %c", &quitCondition) != 1) {
                printf("Invalid input. Please enter y or n.\n");;
            }
            if (quitCondition == 'n') {
                printf("Enter the rent duration: ");
                if (scanf("%d", &rentDuration) != 1 || rentDuration <= 0) {
                    printf("Invalid input. Please enter a positive integer.\n");
                }
                break;
            }
            else if (quitCondition != 'y') {
                printf("Invalid input. Please enter y or n.\n");
                continue;
            }
            else {
                break; 
            }
        }
        if (quitCondition == 'n') {
            break; 
        }
    }
}
int main() {
    printf("WELCOME TO THE CAMPING EQUIPMENT RENTING STORE!\n\n");
    printf("GET THE EQUIPMENT YOU NEED-WITHOUT PURCHASING\n");
    printf("HOW IT WORKS: \n");
    printf("1. Pick an item from the menu below.\n");
    printf("2. Select the item quantity and the rent duration\n");
    printf("3. You will be shown the invoice.\n\n");
    char selectedItemsArray[30][50];
    int selectedItemsQty[30];
    float selectedItemsPrice[30];

    int x = 0; 
    int condition = 1;

    char camping_equipment[30][50] = {
    "Tent",                             // Index 0, Price: $100
    "Sleeping bag",                     // Index 1, Price: $85
    "Camping stove",                    // Index 2, Price: $20
    "Lantern",                          // Index 3, Price: $35
    "Campfire grill",                   // Index 4, Price: $25
    "Camp chairs",                      // Index 5, Price: $40
    "Cooler",                           // Index 6, Price: $50
    "Water filter/purifier",            // Index 7, Price: $150
    "Camp table",                       // Index 8, Price: $90
    "Hammock",                          // Index 9, Price: $60
    "Portable camping toilet",          // Index 10, Price: $50
    "First aid kit",                    // Index 11, Price: $20
    "Multi-tool or knife",              // Index 12, Price: $15
    "Headlamp",                         // Index 13, Price: $50
    "Camping cookware set",             // Index 14, Price: $50
    "Portable camp shower",             // Index 15, Price: $40
    "Camping axe or hatchet",           // Index 16, Price: $20
    "Portable solar charger",           // Index 17, Price: $35
    "Camping shovel",                   // Index 18, Price: $35
    "Camping cot or sleeping pad",      // Index 19, Price: $90
    "Inflatable mattress",              // Index 20, Price: $78
    "Campfire starter kit",             // Index 21, Price: $55
    "Camping backpack or hiking pack",  // Index 22, Price: $33
    "Campfire tripod for cooking",      // Index 23, Price: $67
    "Campfire gloves",                  // Index 24, Price: $25
    "Portable camping sink",            // Index 25, Price: $65
    "Camping dishes and utensils",      // Index 26, Price: $90
    "Camping tarp or canopy",           // Index 27, Price: $10
    "Folding saw",                      // Index 28, Price: $23
    "Bug repellent and sunscreen"       // Index 29, Price: $15
};

    float camping_equipment_prices[30] = {
    100.0,   // Tent
    50.0,    // Sleeping bag
    40.0,    // Camping stove
    20.0,    // Lantern
    30.0,    // Campfire grill
    20.0,    // Camp chairs
    60.0,    // Cooler
    50.0,    // Water filter/purifier
    40.0,    // Camp table
    30.0,    // Hammock
    70.0,    // Portable camping toilet
    25.0,    // First aid kit
    30.0,    // Multi-tool or knife
    20.0,    // Headlamp
    50.0,    // Camping cookware set
    40.0,    // Portable camp shower
    35.0,    // Camping axe or hatchet
    80.0,    // Portable solar charger
    25.0,    // Camping shovel
    60.0,    // Camping cot or sleeping pad
    50.0,    // Inflatable mattress
    15.0,    // Campfire starter kit
    70.0,    // Camping backpack or hiking pack
    25.0,    // Campfire tripod for cooking
    15.0,    // Campfire gloves
    30.0,    // Portable camping sink
    20.0,    // Camping dishes and utensils
    25.0,    // Camping tarp or canopy
    15.0,    // Folding saw
    10.0     // Bug repellent and sunscreen
};  

    int camping_quantities[30] = {
        5,   // Tent
        8,   // Sleeping bag
        10,  // Camping stove
        3,   // Lantern
        7,   // Campfire grill
        12,  // Camp chairs
        2,   // Cooler
        6,   // Water filter/purifier
        9,   // Camp table
        4,   // Hammock
        15,  // Portable camping toilet
        11,  // First aid kit
        13,  // Multi-tool or knife
        14,  // Headlamp
        1,   // Camping cookware set
        0,   // Portable camp shower
        8,   // Camping axe or hatchet
        5,   // Portable solar charger
        7,   // Camping shovel
        2,   // Camping cot or sleeping pad
        6,   // Inflatable mattress
        3,   // Campfire starter kit
        4,   // Camping backpack or hiking pack
        9,   // Campfire tripod for cooking
        10,  // Campfire gloves
        1,   // Portable camping sink
        12,  // Camping dishes and utensils
        2,   // Camping tarp or canopy
        11,  // Folding saw
        15   // Bug repellent and sunscreen
    };

    printf("Equipment along with serial numbers: \n\n");
    itemShowcase(camping_equipment, camping_equipment_prices, camping_quantities);

    askUser(selectedItemsArray, selectedItemsPrice, selectedItemsQty, &x, camping_equipment_prices, camping_quantities, camping_equipment);


//Printing the INVOICE

//Total Price Formula: rent duration x items quantity x item Price
//Grand total = sum of prices of all products

printf("\n<===INVOICE===>\n\n");
float grandTotal = 0;
int i = 1;
for (int j = 0; j < x; j++) { 
    float total = rentDuration * selectedItemsPrice[j] * selectedItemsQty[j];
    grandTotal += total;
    printf("%d.\tName: %s\tPrice: $%.2f\tQuantity %d\tRent Duration %d\t==> %.1f\n",
        i++, selectedItemsArray[j], selectedItemsPrice[j], selectedItemsQty[j], rentDuration, total);
}
printf("\nTotal: $%.1f\n", grandTotal);


    return 0;
}
