#include <stdio.h>

void heap_sort(int* A,int size);
void buildMaxHeap(int* A,int size);
void max_heapify(int* A,int i);
void printArray(int* A,int size);

int heap_size=0;

int left(int i){
  return i*2+1;
}
int right(int i){
  return i*2+2;
}
void heap_sort(int* A,int size){
  buildMaxHeap(A,size);
  for(int i=size-1;i>=1;i--){
    int temp=A[i];
    A[i]=A[0];
    A[0]=temp;
    heap_size--;
    max_heapify(A,0);
  }
}
void buildMaxHeap(int* A,int size){
  heap_size=size;
  int index=heap_size/2;
  for(int i=index-1;i>=0;i--)
    max_heapify(A,i);
}
void max_heapify(int* A,int i){
  int l=left(i);
  int r=right(i);
  int largest;
  if(l<heap_size&&A[l]>A[i])
    largest=l;
  else
    largest=i;

  if(r<heap_size&&A[r]>A[largest])
    largest=r;

  if(largest!=i){
    int temp=A[largest];
    A[largest]=A[i];
    A[i]=temp;
    max_heapify(A,largest);
  }
}
void printArray(int* A,int size){
  for(int i=0;i<size;i++)
    printf("%d ",A[i]);
  printf("\n");
}
void main(){
  int A[8]={12,2,3,4,6,9,7,11};
  printArray(A,8);
  heap_sort(A,8);
  printArray(A,8);
}
