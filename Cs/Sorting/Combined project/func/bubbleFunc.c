#include "../Headers/arr.h"

int bubbleFunc (int *arrF, int vol) {
    if (vol >= 2) {
        max = 0;
        sort = false;
        while (sort == false){
            sort = true;
            for (int i = 0; i < vol - 1 - max; i++) {
                if (arrF[i] > arrF[i + 1]) {
                    buf = arrF[i];
                    arrF[i] = arrF[i + 1];
                    arrF[i + 1] = buf;
                    sort = false;
                } 
            }
            max++;
        }
    }
    return 0; 
}