#include "../Headers/arr.h"

int insertionFunc (int *arrF, int vol) {
    if (vol >= 2) {
        for (int i = 1; i < vol; i++) {
            buf = arrF[i];
            int j = i;
            while (j > 0 && arrF[j - 1] > buf) {
                arrF[j] = arrF[j - 1];
                j--;
            }
            arrF[j] = buf;
        }
    }
    return 0;
}