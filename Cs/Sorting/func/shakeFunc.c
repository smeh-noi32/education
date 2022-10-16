#include "../Headers/arr.h"

int shakeFunc (int *arrF, int vol) {
    if (vol >= 2) {
        min = 0;
        max = vol - 1;
        while (min <= max) {
            for (int i = max; i > min; i--) {
                if (arrF[i - 1] > arrF[i]) {
                    buf = arrF[i];
                    arrF[i] = arrF[i-1];
                    arrF[i-1] = buf;
                }
            }
            min++;
            for (int i = min; i < max; i++) {
                if (arrF[i] > arrF[i + 1]) {
                    buf = arrF[i];
                    arrF[i] = arrF[i + 1];
                    arrF[i + 1] = buf;
                }
            }
            max--;
        }
    }
    return 0;    
}