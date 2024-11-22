#include<iostream>
#include<vector>
using namespace std;

class QuickSort {
public:
    int pivotValue(vector<int>& a, int start, int end) {
        int pivot = a[start];
        int i = start + 1;
        int j = end;

        while (i <= j) {
            while (i <= end && a[i] <= pivot) {
                i++;
            }
            while (j >= start && a[j] > pivot) {
                j--;
            }
            if (i < j) {
                swap(a[i], a[j]);
            }
        }
        swap(a[start], a[j]);
        return j;
    }

    void quick(vector<int>& a, int start, int end) {
        if(start < end) {
            int p = pivotValue(a, start, end);
            quick(a, start, p - 1);
            quick(a, p + 1, end);
        }
    }

    void print(const vector<int>& a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
    }
};

int main () {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> a(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    QuickSort q;
    cout << "Before Sorting: ";
    q.print(a);
    cout << "\nAfter Sorting: ";
    q.quick(a, 0, n-1);
    q.print(a);

    return 0;
}