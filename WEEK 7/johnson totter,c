#include <stdio.h>
#include <stdlib.h>

struct ele{
    int num;
    int dir;
};

void main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    struct ele e[n];
    printf("Enter sorted elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &e[i].num);
        e[i].dir = 1;
    }
    while(1){
        for(int i = 0; i < n; i++){
            printf("%d ", e[i].num);
        }
        printf("\n");
        int curri = -1;
        for(int i = 0; i < n; i++){
            if(curri == -1 || e[i].num > e[curri].num){
                if(e[i].dir == 1){
                    if(i < n - 1 && e[i+1].num < e[i].num){
                        curri = i;
                    }
                }
                else{
                    if(i > 0 && e[i].num > e[i-1].num){
                        curri = i;
                    }
                }
            }
        }
        if(curri == -1) break;
        struct ele temp = e[curri];
        if(e[curri].dir == 1){
            e[curri] = e[curri + 1];
            e[curri + 1] = temp;
        }
        else{
            e[curri] = e[curri - 1];
            e[curri - 1] = temp;
        }
        for(int i = 0; i < n; i++){
            if(e[i].num > temp.num){
                e[i].dir = !e[i].dir;
            }
        }
    }
