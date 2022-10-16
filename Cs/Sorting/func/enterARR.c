#include "../Headers/arr.h"

int enterARR () {
    printf("Input N: ");
    scanf_s("%d", &N);
    int* mass;
    mass = (int *)malloc(N * sizeof(int));
    printf("Input the array elements:\n");
    for (int i = 0; i < N; i++)
        scanf_s("%d", &mass[i]);
    //сортировка методом выбора
    int minPosition, tmp;
 
    for (int i = 0; i < N; i++)
    {
        minPosition = i;
        for (int j = i + 1; j < N; j++)
            if (mass[minPosition] > mass[j])
                minPosition = j;
        tmp = mass[minPosition];
        mass[minPosition] = mass[i];
        mass[i] = tmp;
    }
 
    printf("Sorted array:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", mass[i]);
    printf("\n");
    free(mass);
    return 0;
}