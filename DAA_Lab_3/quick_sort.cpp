#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(vector<int>& arr, int l, int h)
{
    int pivot = arr[h];
    int i = l;
    for (int j = l; j <= h; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[h]);
    return i;
}

void quick_sort(vector<int>& arr, int l, int h)
{
    if (l >= h)
        return;

    int pos = partition(arr, l, h);
    
    quick_sort(arr, l, pos - 1);
    quick_sort(arr, pos + 1, h);
}

int main()
{
    int N;
    cout << "Number of elements : ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter elements of array : ";
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    quick_sort(arr, 0, N - 1);
    for (auto i : arr)
        cout << i << ' ';
    cout << endl;
}