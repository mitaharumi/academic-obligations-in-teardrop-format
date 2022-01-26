#include<stdio.h> 
#include<stdlib.h>

int getTimesSubsetSum(int set [], int sizeSubset, int sum){
    if (sum == 0) return 1;
    if (sizeSubset < 0 || sum < 0) return 0;
    return getTimesSubsetSum(set, sizeSubset - 1, sum - set[sizeSubset]) + getTimesSubsetSum(set, sizeSubset - 1, sum);  // include + exclude
}

void resultsPrint(int *results, int resultsAmount){
    printf("----\n"); 
    printf("results: ");
    int i;
    for (i = 0; i < resultsAmount; i++, results++) printf("%i ", *results);
    printf("\n----\n\n\n");

}

void testGet(int *numbersAmount, int *setAmount, int *set, int *numbers){
    int i;

    FILE *data = fopen("test.dat", "r");
    fscanf(data, "%i", &(*numbersAmount));
    fscanf(data, "%i", &(*setAmount));

    for (i = 0; i < *setAmount; i++) fscanf(data, "%d", &set[i]);
    for (i = 0; i < *numbersAmount; i++) fscanf(data, "%d", &numbers[i]);
    
    fclose(data);
}

void testPrint(int numbersAmount, int setAmount, int *set, int *numbers){
    int i;

    printf("\n\n\n----\ntest\n----\n");
    printf("numbers amount = %i\n", numbersAmount);
    printf("set amount = %i\n", setAmount);
    
    printf("set = ");
    for (i = 0; i < setAmount; i++, set++) printf("%d ", *set);
    printf("\n");
    printf("numbers = ");
    for (i = 0; i < numbersAmount; i++, numbers++) printf("%d ", *numbers);
    printf("\n");
}
    


int main(void){
    int setAmount, numbersAmount, i = 0;
    int set[50], numbers[50], results[50];
    printf("SUBSET SUM PROBLEM\nready test gererated from a dat file");

    testGet(&numbersAmount, &setAmount, set, numbers);
    testPrint(numbersAmount, setAmount, set, numbers);

    for (i = 0; i < numbersAmount; i++) results[i] = getTimesSubsetSum(set, setAmount - 1, numbers[i]);

    resultsPrint(results, numbersAmount);    
    
    return 0;
}