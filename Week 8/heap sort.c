#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int a[15000];

void bottom_up_heapify(int n)
{
    int  item, c;
    for(int p=(n-1)/2 ; p>=0 ; p--)
    {
        item = a[p];
        c = 2 * p + 1;
        while(c <= n-1)
        {
            if(c+1 <= n-1)
            {
                if(a[c] < a[c+1])
                    c+=1;
            }

            if(item < a[c])
            {
                a[p] = a[c];
                p = c;
                c = 2 * p + 1;
            }
            else
                break;
        }
        a[p] = item;
    }
}

void exchange(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heap_sort(int n)
{
    // Heap_sort
    for(int i = n-1; i>0;i--)
    {
        exchange(&a[0], &a[i]);
        bottom_up_heapify(i);
    }
}

int main() {
    int n, i, j, ch, temp;
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
                start = clock();
                bottom_up_heapify(n);
                heap_sort(n);
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

                    start = clock();
                    bottom_up_heapify(n);
                    heap_sort(n);
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
