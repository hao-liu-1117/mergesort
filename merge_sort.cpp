#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> buf1, buf2;

void merge_sort(vector<int>& arr, int l, int r) {
    if (l>=r) return;
    if (l==r-1) {
        if (arr[l]>arr[r]) swap(arr[l], arr[r]);
        return;
    }

    int mid = (l+r)/2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid+1, r);
    
    for (int i = l; i <= mid; i++) buf1[i] = arr[i];
    for (int i = mid+1; i <= r; i++) buf2[i] = arr[i];
    int p = l, q = mid+1;
    int disp = 0;
    while (p!=mid+1&&q!=r+1) {
        if (buf1[p]<buf2[q]) {
            arr[l+disp] = buf1[p];
            p++;
        }
        else {
            arr[l+disp] = buf2[q];
            q++;
        }
        disp++;
    }
    while (p!=mid+1) {
        arr[l+disp] = buf1[p];
        p++;
        disp++;
    }
    while (q!=r+1) {
        arr[l+disp] = buf2[q];
        q++;
        disp++;
    }
}

int main(int argc, char *argv[]) {
    if (argc!=2) {
        cout << "only one argument accepted." << endl;
        return 0;
    }

    ifstream inputFile(argv[1]);
    vector<int> arr;
    if (inputFile) {
        int val;
        while (inputFile >> val) arr.push_back(val);
    }

    buf1 = vector<int>(arr), buf2 = vector<int>(arr);
    merge_sort(arr, 0, arr.size()-1);
    for (auto num: arr) cout << num << " ";
    cout << endl;
    return 0;
}