#include <stdio.h>
#include <stdlib.h>

int c, n;

int ternaryOperator(int i){
    c = i < 10 ? 10  : (i > 100 ? 100 : i + 1000);
    return c;
}

/*int myFactRec (int x){
    if (x > 1) {
        return x * myFactRec(x - 1);
    }
    else
        return 1;
}*/

int exponentiation (int x, int k){
    if (k > 0) {
        return x * exponentiation(x, k - 1);
    }
    else
        return 1;
}

int main(){
    scanf("%d", &n);
    printf("%d\n", n);
    printf("%d\n", ternaryOperator(n));
    printf("%d\n", exponentiation(2, n));
    system("pause");
    return 0;
}