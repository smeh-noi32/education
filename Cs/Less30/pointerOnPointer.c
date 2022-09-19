#include <stdio.h>
#include <stdlib.h>

float c;

float add(float a, float b){
    c = a + b;
    return c;
}

float multiply(float a, float b){
    c = a * b;
    return c;
}

int main(){
    float (*VV)(float, float);

    VV = add;
    printf("%.3f\n", VV(1.1, 1.3));

    VV = multiply;
    printf("%.3f\n", VV(1.1, 1.1));

    system("pause");
    return 0;
}