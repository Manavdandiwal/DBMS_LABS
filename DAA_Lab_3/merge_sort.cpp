#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int l, int mid, int h)
{
    int L = mid - l + 1;
    int R = h - mid;
    vector<int> left(L), right(R);
    for (int i = 0; i < L; i++)
        left[i] = arr[i + l];

    for (int i = 0; i < R; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < L && j < R)
    {
        if (left[i] > right[j])
            arr[k++] = right[j++];

        else    
            arr[k++] = left[i++];
    }

    while (i < L)
        arr[k++] = left[i++];

    while (j < R)
        arr[k++] = right[j++];
}

void merge_sort(vector<int>& arr, int l, int h)
{
    if (l == h)
        return;

    int mid = (l + h) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, h);
    merge(arr, l, mid, h);
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

    merge_sort(arr, 0, N - 1);
    for (auto i : arr)
        cout << i << ' ';
    cout << endl;
}