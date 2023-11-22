#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
void FCFS(int arr[], int head, int n)
{
    int seek_count = 0;
    int cur_track, distance;
   
    for(int i=0; i<n; i++)
    {
        cur_track = arr[i];
        distance = abs(head - cur_track);
       
        seek_count += distance;
        head = cur_track;
    }
   
    printf("Total number of seek operations: %d\n", seek_count);
    printf("Seek Sequence is\n");
   
    for (int i=0; i<n; i++) 
    {
        printf("%d\n", arr[i]);
    }
}
 
int main()
{
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements in array: \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int head;
    printf("Enter head: ");
    scanf("%d", &head);
     
    FCFS(arr, head, n);
   
    return 0;
}
