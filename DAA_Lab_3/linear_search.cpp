#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int linear_search(vector<int>& arr, int key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binary_search(vector<int>& arr, int key)
{
    sort(arr.begin(), arr.end());
    int l = 0, h = arr.size() - 1;

    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] > key)
            h = mid - 1;

        else if (arr[mid] < key)
            l = mid + 1;

        else
            return mid;
    }
    return -1;
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

    int key;
    cout << "Enter key to be searched in the array : ";
    cin >> key;

    int pos = linear_search(arr, key);
    if (pos != -1)
        cout << key << " found at pos " << pos + 1 << endl;
        
    else
        cout << "Key not found" << endl;

    pos = binary_search(arr, key);
    if (pos != -1)
        cout << key << " found at pos " << pos + 1 << endl;
        
    else
        cout << "Key not found" << endl;
}