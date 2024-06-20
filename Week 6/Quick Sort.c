#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void quick_sort(int[], int, int);
int partition(int[], int, int);
void swap(int*, int*);

int main() {
    int a[15000], n, i, j, ch, temp;
    clock_t start, end;
    int low, high;

    while (1) {
        printf("\n1: For manual entry of N value and array elements");
        printf("\n2: To display time taken for sorting number of elements N in the range 500 to 14500");
        printf("\n3: To exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the number of elements: ");
                scanf("%d", &n);
                printf("\nEnter array elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }
                low = 0;
                high = n - 1;
                start = clock();
                quick_sort(a, low, high);
                end = clock();
                printf("\nSorted array is: ");
                for (i = 0; i < n; i++)
                    printf("%d\t", a[i]);
                printf("\nTime taken to sort %d numbers is %f Secs\n", n, ((double)(end - start)) / CLOCKS_PER_SEC);
                break;
            case 2:
                n = 500;
                while (n <= 14500) {
                    for (i = 0; i < n; i++) {
                        // a[i]=random(1000);
                        a[i] = n - i;
                    }
                    low = 0;
                    high = n - 1;
                    start = clock();
                    quick_sort(a, low, high);
                    end = clock();
                    printf("\nTime taken to sort %d numbers is %f Secs\n", n, ((double)(end - start)) / CLOCKS_PER_SEC);
                    n = n + 1000;
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void quick_sort(int a[], int low, int high) {
    if (low < high) {
        int split_point = partition(a, low, high);
        quick_sort(a, low, split_point - 1);
        quick_sort(a, split_point + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= j && a[i] <= pivot) {
            i++;
        }
        while (i <= j && a[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[low], &a[j]);
    return j;
}

void swap(int* i, int* j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}
