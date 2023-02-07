/* 
Author Name: Austin James Polak
Author Email: ajpolak@purdue.edu
TA Name: Zahra Ghorrati
Lab time: Thursday, 07:30am
*/

/* The program will aske for the user to input values measuremetns for the swimming pool and hot tub.
Calculating  the volumes and the gallons of water needed to fill the hot tub and pool.
It will display the results of gallons for each. The user will have to answer the last 
question to end the program.*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef M_PI
#define M_PI acos(-1.0)
#endif

int main(){
float depthShallow, depthDeep, widthPool, lengthPool, lengthWalk, lengthShallow, lengthDeep, 
widthHot, depthHot, volumeHot, gallonsHot, deepPool, shallowPool, walkIn, transition, volumePool, 
gallonsPool, lengthCal, totalGallons, totalCost = 0;
char result = 'y';

do{ 
    printf("Pool Dimension:\n");
do{
    printf("Enter the depth of the shallow end between 0-5 feet: ");
    scanf("%f", &depthShallow);
} 
    while (depthShallow > 5 || depthShallow < 0);
        depthShallow = depthShallow-0.5;

do{
    printf("Enter the depth of the deep end between 6-15 feet: ");
    scanf("%f", &depthDeep);
} 
    while (depthDeep > 15 || depthDeep < 6);
        depthDeep = depthDeep-0.5;

do{
    printf("Enter the wideth of the pool between 15-30 feet: ");
    scanf("%f", &widthPool);
} 
    while (widthPool > 30 || widthPool < 15);

do{
    printf("enter the length of the pool between 35-70 feet: ");
    scanf("%f", &lengthPool);
} 
    while (lengthPool > 70 || lengthPool < 35);

do{
    printf("Enter the length of the walk in between 5 feet minimum to 1/3 of the pool length: ");
    scanf("%f", &lengthWalk);
} 
    while (lengthWalk < 5 || lengthWalk > lengthPool/3);

do{
    printf("Enter the length of the shallow end between 10 feet minimum to 1/2 of the pool length: ");
    scanf("%f", &lengthShallow);
} 
    while (lengthShallow < 10 || lengthShallow > lengthPool/2);

do{
    printf("Enter the length of the deep end between 12 feet to 1/2 of the pool length: ");
    scanf("%f", &lengthDeep);
}
    while (lengthDeep < 12 || lengthDeep > lengthPool/2);

do{
    printf("Enter the width of the hot tub between 8-14 feet: ");
    scanf("%f", &widthHot);
} 
    while (widthHot > 14 || widthHot < 8);

do{
    printf("Enter the depth of the hot tub between 3-5 feet: ");
    scanf("%f", &depthHot);
} 
    while (depthHot > 5 || depthHot < 3);
        depthHot = depthHot-0.5;

        deepPool = lengthDeep*widthPool*depthDeep;
        shallowPool = lengthShallow*widthPool*depthShallow;
        walkIn = (lengthWalk*widthPool*depthShallow)/2;
        lengthCal = lengthPool-lengthDeep-lengthShallow-lengthWalk;
        transition = ((depthShallow+depthDeep)*lengthCal/2)*widthPool;

        volumePool = deepPool+shallowPool+walkIn+transition;
        gallonsPool = volumePool * 7.481;
        volumeHot = ((widthHot/2)*(widthHot/2)*M_PI)*depthHot;
        gallonsHot = volumeHot*7.481;

        totalGallons = gallonsPool + gallonsHot;
        totalCost = totalGallons * 4 * 0.07;


printf("\nPool Volume\n");
printf("Total volume of the pool: %.2f\n", volumePool);
printf("Gallons of water to fill: %.2f\n", gallonsPool); 

printf("Hot Tub Volume\n");
printf("Total volume of hot tub: %.2f\n", volumeHot);
printf("Gallons of water to fill: %.2f\n", gallonsHot);

printf("Total gallons for both: %.1f\n", totalGallons);
printf("Total cost for both: %.1f\n", totalCost);

printf("Would you like to run the program again? (yes or no) ");
scanf("%s", &result);

} 
    while (result == 'y');

return 0;
}