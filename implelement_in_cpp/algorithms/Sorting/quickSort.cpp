#include<iostream>
using namespace std;
void printArray(int a[],int size){
   for (int i = 0; i < size; i++)
   {
       cout<<a[i]<<" ";
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
  cout<<"Enter the Size of the Array : "<<endl;
  cin>>sizeOfArray;
  cout<<"Enter The Array : "<<endl;
  for (int i = 0; i < sizeOfArray; i++)
  {
      cin>>A[i];
  }
  cout<<"The Original Array is : "<<endl;
  printArray(A,sizeOfArray);
  quickSort(A,0,sizeOfArray-1);
  cout<<"\nThe Sorted Array is : "<<endl;
  printArray(A,sizeOfArray);
return 0;
}