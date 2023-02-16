#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int a[], int length);

int main(void){
  int a[] = {1,3,7,0,2,4,9,5,8,6};
  int length = 10;
  bubble_sort(a, length);
  // output the array to see it has been sorted
  for (int i = 0; i < length; i++)
    printf("a[%d] = %d\n", i, a[i]);
  return 0;
}

void bubble_sort(int a[], int length){
  bool swapped = false;
  int i = 0;
  do {
    swapped = false;
    for (int j = 0; j < (length - 1 - i); j++){
      if (a[j] > a[j + 1]){
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        swapped = true;
      } 
    }
    i++;
  } while (swapped);
}

int test[3][4] = {{3, 23, 12, 23, 2}, {13, 3, 1, 4, 9}, {24, 76, 14, 26}};