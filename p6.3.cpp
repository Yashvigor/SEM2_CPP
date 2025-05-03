#include <iostream>
using namespace std;

int main()
 {
    int m,n;
    cout << "Enter the size of the first array: ";
    cin >> m;
    cout << "Enter the size of the second array: ";
    cin >> n;

    int* arr1 = new int[m];
    int* arr2 = new int[n];

    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < m; ++i)
    {
        cin >> arr1[i];
    }
    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr2[i];
    }

    int* merged = new int[m + n];
    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            merged[k++] = arr1[i++];
        } else
        {
            merged[k++] = arr2[j++];
        }
    }
    while (i < m)
    {
        merged[k++] = arr1[i++];
    }

    while (j < n)
    {
        merged[k++] = arr2[j++];
    }

    cout << "Merged sorted array: ";
    for (int i = 0; i < m + n; ++i)
    {
        cout << merged[i] << " ";
    }
    cout << endl;

   delete []arr1;
   delete []arr2;
   delete []merged;
   cout<<"24CE037_Yashvi";
    return 0;
}

