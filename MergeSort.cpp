#include <iostream>
#include <vector>
using namespace std;

class MergeSort {
    public:
    void conq(vector<int>& a, int beg, int mid, int end) {
        int i = beg;
        int j = mid + 1;
        int k = 0;
        vector<int> temp(end - beg + 1);

        while (i <= mid && j <= end) {
            if (a[i] < a[j]) {
                temp[k] = a[i];
                i++;
            } else {
                temp[k] = a[j];
                j++;
            }
            k++;
        }

        while (i <= mid) {
            temp[k] = a[i];
            i++;
            k++;
        }

        while (j <= end) {
            temp[k] = a[j];
            j++;
            k++;
        }

        for (k=0;k < temp.size();k++) {
            a[beg + k] = temp[k];
        }
    }

    void div (vector<int>& a, int beg, int end) {
        if (beg < end) {
            int mid = (beg + end) / 2;
            div(a, beg, mid);
            div(a, mid + 1, end);
            conq(a, beg, mid, end);
        }
    }

    void printArray(const vector<int>& a) {
        for (int i = 0; i < a.size();i++) {
            cout << a[i] << " ";
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> a(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    MergeSort ms;
    ms.div(a, 0, n - 1);
    cout << "Sorted array: ";
    ms.printArray(a);

    return 0;
}