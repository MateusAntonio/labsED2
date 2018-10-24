#include "item.h"


int partitioning(Item* a, int lo, int hi){
  int i = lo;
  int j = hi+1;
  Item v = a[lo];
  while(1){
    while(less(a[++i], v)) //Para quando a[i] não for menor que v
      if (i == hi) break;
    while(less(v, a[--j])) //para quando a[j] não for maior que v
      if (j == lo) break;
    if(i >= j) break; // indices se cruzaram
    exch(a[i],a[j]);
  }
  exch(a[lo], a[j]);
  return j;
}

void quicksort(Item* a, int lo, int hi){
  if (hi <= lo) return;
  
  int j = partitioning(a,lo,hi);
  quicksort(a, lo, j-1);
  quicksort(a, j+1, hi);
}

void sort(Item* a, int lo, int hi){
  quicksort(a, lo, hi);
}
