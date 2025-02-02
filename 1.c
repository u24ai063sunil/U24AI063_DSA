/* An array is a bitonic array if all integers from index 0 to index i are sorted in 
ascending order, and all subsequent integers from index i+1 to n-1 are sorted in 
descending order. Given a bitonic array of n distinct integers, write a C/C++ program to 
find the maximum integer in the array in O(log(n)) time.
*/
#include<stdio.h>

int main()
{
    int n;
    printf("Enter size of Bitionic array: ");
    scanf("%d",&n);

    int arr[n];
    printf("\nEnter Elements of Bitionic Array\n ");
    for(int i=0 ; i<n ; i++)
    {
        printf("Enter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }

    for(int i=0 ; i<n ; i++)
    {
        printf("%d ",arr[i]);
    }
    
    int st = 0;
    int end = n-1;
    int mid,max;
    
    for(int i=0;i<n;i++)
    {
        mid = st+(end - st)/2;
        if(arr[mid-1]>arr[mid])
        {
            end= mid-1;
        }
        else if(arr[mid+1]>arr[mid])
        {
            st= mid+1;
        }
        else
        {
            max = arr[mid];
        }
    }
    
    printf("\nMaximum Element in Bitionic Array is : %d", max); 
    return 0;
}
