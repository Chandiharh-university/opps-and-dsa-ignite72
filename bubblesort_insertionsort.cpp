#include<iostream>
using namespace std;
//to perform bubble sort
void bubblesort(int arr[], int n)
{
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-1;j++){
            if(arr[j]>arr[j+1]){
                //swap arr[j],arr[j+1]
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
//to perform insertion sort
void insertionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int key = arr[i];
        int j= i-1;


        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Original array for Bubble Sort: ";
    printArray(arr1, n1);  // Corrected function name

    bubblesort(arr1, n1);
    cout << "Sorted array using Bubble Sort: ";
    printArray(arr1, n1);  // Corrected function name

    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Original array for Insertion Sort: ";
    printArray(arr2, n2);  // Corrected function name

    insertionsort(arr2, n2);
    cout << "Sorted array using Insertion Sort: ";
    printArray(arr2, n2);  // Corrected function name

    return 0;
}
