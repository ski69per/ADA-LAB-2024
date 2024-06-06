#include<stdio.h>

void main()
{
    int n;
    printf("Enter number of veritces: ");
    scanf("%d",&n);
    int a[n][n];

    printf("Enter the elements of adjacency matrix\n");
    for(int r = 0;r<n;r++)
    {
        for(int c = 0;c<n;c++)
        {
            scanf("%d",&a[r][c]);
        }
        printf("\n");
    }

    int s[n],indegree[n];
    int sum;

    for(int j = 0;j<n;j++)
    {
        sum = 0;
        for(int i=0;i<n;i++)
        {
            sum = sum + a[i][j];
        }
        indegree[j] = sum;
    }

    int top = -1;
    for(int i=0;i<n;i++)
    {
        if(indegree[i] == 0)
        {
            top += 1;
            s[top] = i;
        }
    }

    int u, vertex[n] ;
    int j=0;
    while(top != -1)
    {
        u = s[top];
        top -= 1;

        vertex[j++] = u;

        for(int i=0;i<n;i++)
        {
            if(a[u][i] == 1)
            {
                indegree[i] -= 1;
                if(indegree[i] == 0)
                {
                    top += 1;
                    s[top] = i;
                }
            }
        }

    }

    // Output
    for(int i=0;i<n;i++)
        printf("%d\t",vertex[i]+1);
}
