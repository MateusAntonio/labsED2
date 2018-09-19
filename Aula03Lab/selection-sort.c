#include "item.h"

void sort(Item *a, int lo, int hi){
    for(int i = lo; i < hi-1; i++){
        int minor = i;
        for(int j = i+1; j < hi; j++){
            if (less(a[j], a[minor]))
                minor = j;
        }
        if (a[i] != a[minor]) 
            exch(a[i], a[minor]);
    }
}