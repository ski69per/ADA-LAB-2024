
int removeDuplicates(int* nums, int numsSize) {
    int a[numsSize];
    int c = 0;
    int j = 0;
    int n, f;
    for (int i = 0; i < numsSize; i++) {
        n = nums[i], f = 0;
        for (int j = 0; j < c; j++) {
            
            if (nums[i] == a[j]) {
                f = 1;
                break;
            }
        }
        if (f == 0) {
                a[c] = n;
                c++;
            }  
    }

    for(int i=0;i<c;i++)
    {
        nums[i] = a[i];
    }
    return c;
}
