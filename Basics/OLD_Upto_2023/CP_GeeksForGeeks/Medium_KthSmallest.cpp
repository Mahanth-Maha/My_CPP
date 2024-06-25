#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

#define LOG(x) std::cout << x << std::endl;

using namespace std;

void printV(vector<int> &v)
{
    cout << v.size() << std::endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

void printA(int a[], int l, int r)
{
    for (int i = l; i < r; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int kthSmallest_1(int arr[], int l, int r, int k)
{
    sort(arr + l, arr + r);
    return arr[l + k - 1];
}

int kthSmallest_2(int arr[], int l, int r, int k)
{
    vector<int> v;
    for (int i = l; i < r; i++)
        v.push_back(-1 * arr[i]);
    make_heap(v.begin(), v.end());
    int elem;
    while (k--)
    {
        pop_heap(v.begin(), v.end());
        elem = v.back();
        v.pop_back();
    }
    return -1 * elem;
}

int partition(int arr[], int l, int r, int k)
{
    int pivot = r;
    int i = l, j = l;
    for (int i = l; i < r; i++)
    {
        if (arr[i] <= arr[pivot])
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    swap(arr[j], arr[pivot]);
    if (j > k)
        return partition(arr, l, j - 1, k);
    else if (j < k)
        return partition(arr, j + 1, r, k);
    return arr[j];
}

int kthSmallest_3(int arr[], int l, int r, int k)
{
    return partition(arr, l, r, k);
}

int main()
{
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int l, r, k;
    cin >> l >> r >> k;
    cout << kthSmallest_3(arr, l, r, k) << "\n";

    return 0;
}
