#include "../Headers/arr.h"

int combFunc (int *arrF, int vol) {
    if (vol >= 2) {
        int delta = vol;

        sort = false;

        while (!sort || delta != 1) {
            if (delta > 1) {
                delta = delta * 10 / 13;        // Эквивалент delta/1.3
            }
            else 
                delta = 1;

            sort = true;
            for (int i = delta; i < vol; i++) {
                if (arrF[i- delta] > arrF[i]){
                    buf = arrF[i];
                    arrF[i] = arrF[i - delta];
                    arrF[i - delta] = buf;
                    sort = false;
                }
            }  
        }
    }
    
    return 0;
}