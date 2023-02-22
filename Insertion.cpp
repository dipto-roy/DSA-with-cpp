#include<iostream>
using namespace std;

void swapValues(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[],int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//Insertion Sort
void insertionSort(int data[],int size)
{

    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = data[i];
        j = i - 1;


        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}
int main()
{
    int size = 15;
    int data[] = {35,14,7,9,46,26,17,49,6,9,33,4,17,37,22};

    cout<<"Unsorted Data"<<endl;
    printArray(data,15);

    //Call your sorting function
    //bubbleSort(data,15);
    //selectionSort(data,15);
    insertionSort(data,15);

    cout<<"Sorted Data"<<endl;
    printArray(data,15);

    return 0;
}
