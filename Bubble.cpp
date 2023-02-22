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

//Bubble Sort
void bubbleSort(int data[],int size)
{

    for (int step = 0; step < size; ++step)
    {


        for (int i = 0; i < size - step; ++i)
        {


            if (data[i] > data[i + 1])
            {

                swapValues(&data[i],&data[i + 1]);
            }
        }
    }
}

int main()
{
    int size = 15;
    int data[] = {35,14,7,9,46,26,17,49,6,9,33,4,17,37,22};

    cout<<"Unsorted Data"<<endl;
    printArray(data,15);

    //Call your sorting function
    bubbleSort(data,15);
    //selectionSort(data,15);
    //insertionSort(data,15);

    cout<<"Sorted Data"<<endl;
    printArray(data,15);

    return 0;
}
