#include<stdio.h>
void printArray(int a[],int size){
   for (int i = 0; i < size; i++)
   {
       printf("%d ",a[i]);
   }
   
}
int partision(int A[], int low,int high){
     int pivot = A[low];
     int i = low+1;
     int j = high;
     int temp;
     do
     {
         while (A[i]<=pivot)
         {
            i++;
         }
         while(A[j]>pivot){
             j--;
         }
         if(i<j){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
         }
     } while (i<j);
     
     temp=A[j];
     A[j]=A[low];
     A[low]=temp;
     return j;
}
void quickSort(int A[],int low,int high){
    int partisionIndex;
    if(low<high){
        partisionIndex = partision(A,low,high);
        quickSort(A,low,partisionIndex-1);
        quickSort(A,partisionIndex+1,high);
    }

}
int main()
{
  int *A,sizeOfArray;
  printf("Enter the Size of the Array : \n");
  scanf("%d",&sizeOfArray);
  printf("Enter The Array : \n");
  for (int i = 0; i < sizeOfArray; i++)
  {
      scanf("%d",&A[i]);
  }
  printf("The Original Array is : \n");
  printArray(A,sizeOfArray);
  quickSort(A,0,sizeOfArray-1);
  printf("\nThe Sorted Array is : \n");
  printArray(A,sizeOfArray);
return 0;
}