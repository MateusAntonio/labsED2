#include "item.h"

void sort(Item *a, int lo, int hi){
    for (int i = 2; i < hi; i++){
        for (int j = i; j > 1 && a[j] < a[j-1]; j--)
            exch(a[j], a[j-1]);
    }
}