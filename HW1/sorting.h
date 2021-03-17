#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

using namespace std;

static int swapCount = 0;

void swap(int* a, int* b)
{
    //swapCount++;
    int temp;
    temp = *a; 
    *a = *b; 
    *b = temp; 
}


/* See Knuth's shuffles https://en.wikipedia.org/wiki/Random_permutation */



void insertionsort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n ; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Order Theta(NlogN) sorting

void mergearray(int a[], int a_tmp[], int l, int m, int r)
{
    int i = l , j = m + 1, k = l ;
//    for (i = m + 1 ; i > l; i--) {
//        a_tmp[i - 1] = a[i - 1];
//    }
//    for (j = m ; j < r; j++) {
//        a_tmp[r + m - j] = a[j + 1];
//    }
//    for (k = l ; k <= r; k++) {
//        a[k] = (a_tmp[i] < a_tmp[j])? a_tmp[i++]: a_tmp[j--];
//    }
    for(k = l; k <= r; k++) a_tmp[k] = a[k];
    k = l;
    while (i <= m && j <= r) {
        a[k++] = (a_tmp[i] < a_tmp[j])? a_tmp[i++]: a_tmp[j++];
    }
    while (i <= m) {
        a[k++] = a_tmp[i++];
    }
    return;
}

void mergeSort(int a[], int a_tmp[], int l, int r)
{
    if (l >= r) {
        return;
    }
    int mid = l + (r - l) / 2;
    mergeSort(a, a_tmp, l , mid);
    mergeSort(a, a_tmp, mid + 1, r);
    mergearray(a, a_tmp, l, mid, r);
//    for (i = mid + 1 ; i > l; i--) {
//        a_tmp[i - 1] = a[i - 1];
//    }
//    for (j = mid ; j < r; j++) {
//        a_tmp[r + mid - j] = a[j + 1];
//    }
//    for (int k = l ; k <= r; k++) {
//        a[k] = (a_tmp[i] < a_tmp[j])? a_tmp[i++]: a_tmp[j--];
//    }
    return;
}


//
void mergeSortblend(int a[], int a_tmp[], int l, int r)
{
    int i, j, k, m;
    if (r <= l) {
        return;
    }
    if (r - l > 32) {
        m = l + (r - l) / 2;
        mergeSortblend(a, a_tmp, l, m);
        mergeSortblend(a, a_tmp, m + 1, r);
        mergearray(a, a_tmp, l, m, r);
    } else {
        for (i = l + 1; i <= r; i++) {
            k = a[i];
            j = i - 1;
            while (j >= l && a[j] > k) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = k;
        }
    }
}

void checkInorder(int a[],int left, int right){
    //checks  that a is in order from left to right
    for (int i = left;i <right; i++){
        if (a[i] > a[i+1]){
            int tmp = i;
        }
    }
}

void simpleTimsort(int a[], int a_tmp[], int n)
{
    int i, j, k, len1, len2, m;
    int minsortsize = 32;
    int runstack[5000];
    int num_in_stack = 0;
    int length = 1;
    int l = 0;
    runstack[0] = 0;
    for (i = 1; i < n - 1; i++) {
        if (a[i] < a[i - 1]) {
            if (length < minsortsize) { //insertion sort
                k = a[i];
                j = i - 1;
                while (j >= l && a[j] > k) {
                    a[j + 1] = a[j];
                    j--;
                }
                a[j + 1] = k;
            } else {
                runstack[num_in_stack++] = i;
                l = i;
                length = 1;
            }
        } else {
            length++;
        }

        runstack[++num_in_stack] = n;
        num_in_stack++;

        while (num_in_stack > 1) {
            mergearray(a, a_tmp, runstack[num_in_stack - 2], runstack[num_in_stack - 1] - 1,
                    runstack[num_in_stack] - 1);
        runstack[num_in_stack - 1] = runstack[num_in_stack];
        num_in_stack--;
        }
    }

    return;
}// end function




#endif 
