/* 
Author Name: Austin James Polak
Author Email: ajpolak@purdue.edu
TA Name: Zahra Ghorrati
Lab time: Thursday, 07:30am
*/

int main()
{
    /*
    Size of Container = 40x8x8 ft^3
    Type 1 = 1x1x1 ft^3
    Type 2 = 1x2x2 ft^3
    */

    /* Declare Identifiers */

    float containerVolume = 2560.0;
    float shippingPriceTypeOne = 20.0;
    float shippingPriceTypeTwo = 35.0;
    int OneQuanity = 0;
    int TwoQuanity = 0;
    float shippingPrice = 0.0;
    float finalShipPrice = 0.0;
    float discount = 0.0;

    /*
    Calculate the reamining cubic feet in shipping container
    Ask user for the amount of type 1 boxes
    Calculate the remaining space for the type 2 boxes
    Calculate the total of the type 2 boxes that can be stored
    Request the user for amount of type 2 boxes
    */
    /*
    Calculate remaining space in container
    Find shipping cost before discount
    Find total cubic footage for the boxes that will be shipped
    Find final shipping cost with discount
    */

    /* Request for user input for the amount of type 1 boxes*/
    printf("Container space available: %.2f ft^3\n", containerVolume);
    do{
    printf("How many Type 1 boxes would be shipped?: ");
    scanf("%d", &OneQuanity);
    
        if(OneQuanity < 0)
    {
            printf("Error Occured: Invalid amount of Type 1 boxes to ship.\n");
    }
        else if(OneQuanity > 2560)
    {
            printf("Error Occured: To large of quantity of Type 1 boxes to ship.\n");
    }
    }
    while((OneQuanity < 0 || OneQuanity > 2560));
    
    /* Printing the remainder the container can hold after user inputs Type 1 quantity*/
        containerVolume = containerVolume - OneQuanity;
        printf("Remaining container space: %.2f ft^3\n", containerVolume);

    /* Finds the total amount of type 2 boxes that can be stored*/
        int totalBoxes = ((int)containerVolume / 4);
        printf("Max number of Type 2 boxes that can be stored: %d\n", totalBoxes);

    /* Request user input for the amount of type 2 boxes*/
    do{
        printf("How many Type 2 boxes would be shipped?: ");
        scanf("%d", &TwoQuanity);
    
        if(TwoQuanity < 0)
    {
            printf("Error Occured: Invalid amount of Type 2 boxes to ship.\n");
    }
        else if(TwoQuanity > totalBoxes)
    {
            printf("Error Occured: To large of quantity of Type 2 boxes to ship.\n");
    }
    }
    while((TwoQuanity < 0) || (TwoQuanity > totalBoxes));

    /* Container space gets updated */ 
    /*Prints the remainder of space to the user */
    containerVolume = containerVolume - (TwoQuanity * 4.0);
        printf("Total footage of boxes to be shipped: %.2f ft^3\n", (2560 - containerVolume));

        printf("Remaining container space: %.2f ft^3\n", containerVolume);
    /* Calculating the discount for unused space */
    discount = (2.0 * containerVolume);
    /* Calculating the shipping cost prior to the discount being applied*/ 
    /* Shows the user the unused space for the discount*/
    shippingPrice = (OneQuanity * shippingPriceTypeOne) + (TwoQuanity * shippingPriceTypeTwo);
        printf("The shipping cost is: $%.2f\n", shippingPrice);
        printf("The discount for unallocated space is: $%.2f\n", discount);
    /* Calculating the final shipping cost, including the discount*/
    finalShipPrice = shippingPrice - discount;
        printf("Total shipping cost: $%.2f\n", finalShipPrice);

    /* Informs user the program is over */
        printf("Ending Program");
        return 0;
}