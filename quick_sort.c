// Quick sort in C

#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int p = partition(array, low, high);
    quickSort(array, low, p-1);
    quickSort(array, p+1, high);
  }
}

void display(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
    int size,arr[30]; 
	printf("Enter size:");
    scanf("%d",&size);
    printf("Enter elements:");
    for (int i=0;i<size;i++)
    scanf("%d",&arr[i]);
  
  printf("Unsorted Array\n");
  display(arr,size);
  quickSort(arr, 0, size- 1);
  printf("Sorted array : \n");
  display(arr,size);
}