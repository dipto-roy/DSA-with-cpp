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
//Selection Sort
void selectionSort(int data[],int size)
{

    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {


            if (data[i] < data[min_idx])
                min_idx = i;
        }


        swapValues(&data[min_idx], &data[step]);
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
    selectionSort(data,15);
    //insertionSort(data,15);

    cout<<"Sorted Data"<<endl;
    printArray(data,15);

    return 0;
}
