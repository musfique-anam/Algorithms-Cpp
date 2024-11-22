#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BinarySearch {
public:
    int binarySearch(vector<int>& a,int start, int end, int m) {
        while (start <= end) {
            int mid = (start + end) / 2;
            if (a[mid] == m) {
                return mid;
            }else if(a[mid] > m) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    int n;
    cout << "Enter the total number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements: ";
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    cout << "Sorted form: ";
    for(int i =0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    BinarySearch b;
    int m;
    cout << "Enter the element to search: ";
    cin >> m;
    int result = b.binarySearch(a, 0, n-1,m);
    if(result == -1) {
        cout << "Element not found!" << endl;
    }else {
        cout << "Element found at index: " << result << endl;
    }

    return 0;
}