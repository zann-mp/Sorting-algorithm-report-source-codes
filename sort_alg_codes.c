#include <stdio.h>
#include <time.h>
#include <unistd.h>
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

void bubbleSort(int arr[], int n) {
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r) {
    if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

void heapify(int arr[], int n, int i) {
    int max = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[leftChild] > arr[max])
      max = leftChild;

    if (rightChild < n && arr[rightChild] > arr[max])
      max = rightChild;

    if (max != i) {
      swap(&arr[i], &arr[max]);
      heapify(arr, n, max);
    }
  }
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);

      heapify(arr, i, 0);
    }
  }

void shellSort(int arr[], int num) {
    int i, j, k, tmp;
    for (i = num / 2; i > 0; i = i / 2)
    {
        for (j = i; j < num; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (arr[k+i] >= arr[k])
                    break;
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;
                }
            }
        }
    }
}
int main()
{

    FILE *myFile;
    myFile = fopen("POZ1milSortedDESC.txt", "r");


    int static numberArray[1000000];
    int i;

    if (myFile == NULL)
    {
        printf("Error Reading File\n");

    }

    for (i = 0; i < 1000000; i++)
    {
        fscanf(myFile, "%d,", &numberArray[i] );
    }

    double time_spent = 0.0;

    int size = sizeof(numberArray)/sizeof(numberArray[0]);
    clock_t begin = clock();

    //bubbleSort(numberArray, size);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n");
    printf("Time elapsed for bubble sort is %f seconds\n", time_spent);

    time_spent = 0.0;
    begin = clock();
    size = sizeof(numberArray)/sizeof(numberArray[0]);

    //selectionSort(numberArray, size);

    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n");
    printf("Time elapsed for selection sort is %f seconds\n", time_spent);

    time_spent = 0.0;
    begin = clock();
    size = sizeof(numberArray)/sizeof(numberArray[0]);

    //insertionSort(numberArray, size);

    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n");
    printf("Time elapsed for insertion sort is %f seconds\n", time_spent);

    time_spent = 0.0;
    begin = clock();

    //mergeSort(numberArray, 0, size - 1);

    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n");
    printf("Time elapsed for merge sort is %f seconds\n", time_spent);
    time_spent = 0.0;
    begin = clock();

    //heapSort(numberArray, size);

    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n");
    printf("Time elapsed for heap sort is %f seconds\n", time_spent);

    time_spent = 0.0;
    begin = clock();
    size = sizeof(numberArray)/sizeof(numberArray[0]);

    //shellSort(numberArray, size);

    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n");
    printf("Time elapsed for shell sort is %f seconds\n", time_spent);

    return 0;
    fclose(myFile);
}
