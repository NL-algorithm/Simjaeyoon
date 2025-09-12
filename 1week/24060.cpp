#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

int n;
int k;
int cnt = 0;

void merge(vector<int> &arr, vector<int> &tmp, int start, int mid, int end);
void mergeSort(vector<int> &arr, vector<int> &tmp, int start, int end);

void mergeSort(vector<int> &arr)
{
    vector<int> tmp(arr.size());
    mergeSort(arr, tmp, 0, arr.size() - 1);
}

void mergeSort(vector<int> &arr, vector<int> &tmp, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, tmp, start, mid);
        mergeSort(arr, tmp, mid + 1, end);
        merge(arr, tmp, start, mid, end);
    }
}

void merge(vector<int> &arr, vector<int> &tmp, int start, int mid, int end)
{
    int part1 = start;
    int part2 = mid + 1;
    int index = start;

    while (part1 <= mid && part2 <= end)
    {
        if (arr[part1] <= arr[part2])
        {
            tmp[index++] = arr[part1++];
        }
        else
        {
            tmp[index++] = arr[part2++];
        }
    }

    while (part1 <= mid)
    {
        tmp[index++] = arr[part1++];
    }
    while (part2 <= end)
    {
        tmp[index++] = arr[part2++];
    }

    while (start <= end)
    {
        arr[start++] = tmp[start];
        cnt++;
        if(cnt==k){
            cout<<arr[start-1];
        }
        
    }
}

int main()
{
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr);
    if(cnt<k){
        cout<<-1;
    }
}