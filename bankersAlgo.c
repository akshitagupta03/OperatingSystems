#include <stdio.h>
int main()
{
    int processes, resources;

    printf("Enter the number of processes: ");
    scanf("%d\n", &processes);

    printf("Enter the number of resources: ");
    scanf("%d\n", &resources);

    int allocation[processes][resources];
    printf("Enter the values in allocation matrix: \n");
    for(int i=0; i<processes; i++)
    {
        for(int j=0; j<resources; j++)
        {
            printf("Enter the resource for P", i, ": ");
            scanf("%d", &allocation[i][j]);
        }
        printf("\n");
        printf("\n");
    }

    int max[processes][resources];
    printf("Enter the values in max matrix: \n");
    for(int i=0; i<processes; i++)
    {
        for(int j=0; j<resources; j++)
        {
            printf("Enter the max resource for P", i, ": ");
            scanf("%d", &max[i][j]);
        }
        printf("\n");
        printf("\n");
    }
 
    int available[resources];
    printf("Enter the values in available matrix: \n");
    for(int i=0; i<resources; i++)
    {
        scanf("%d", &available[i]);
    }
 
    int f[processes], ans[processes], ind = 0;
    for(int i = 0; i<processes; i++) 
    {
        f[i] = 0;
    }

    int need[processes][resources];
    for(int i=0; i<processes; i++) 
    {
        for(int j=0; j<resources; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    for(int i=0; i<processes; i++) 
    {
        for(int j=0; j<processes; j++) 
        {
            if(f[i] == 0)
            {
                int flag = 0;
                for(int k=0; k<resources; k++) 
                {
                    if(need[i][k] > available[k]){
                        flag = 1;
                            break;
                    }
                }
 
                if(flag == 0)
                {
                    ans[ind++] = i;
                    for(int a=0; a < resources; a++)
                    {
                        available[a] += allocation[i][a];
                    }
                    f[i] = 1;
                }
            }
        }
    }
    
    int flag = 1;
    for(int i=0; i<processes; i++)
    {
        if(f[i] == 0)
        {
            flag = 0;
            printf("The following system is not safe.");
            break;
        }
    }
    
    if(flag == 1)
    {
        printf("Following is the SAFE Sequence\n");
        for(int i=0; i<processes-1; i++)
        {
            printf("P%d ->", ans[i]);
        }
        printf(" P%d", ans[processes-1]);
    }
    
    return 0;
}
