#include <iostream>
using namespace std;


int merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    int counter = 0;

    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
     
    int i = 0; 
    int j = 0; 
    int k = l;
     
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            counter+=n1-i;
        }
        k++;

    }
 
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    return counter;
}

    

int mergeSort(int arr[], int l, int r)
{
    int count = 0;
    if (l < r)
    {
        int m = l + (r - l) / 2;

        count += mergeSort(arr, l, m);
        count += mergeSort(arr, m + 1, r);

        count += merge(arr, l, m, r);
    }
    return count;
}

void print(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout<<A[i];
    cout<<"\n";
}

int main()
{
    int n;
    cout << "Enter the number of Elements : ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the Elements : ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "\nNumber of Inversions : " << mergeSort(arr, 0, n - 1) << endl;
    print(arr, n);
    return 0;
}