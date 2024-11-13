
#include <iostream>
#include <vector>

using namespace std;

void searchElement(const vector<int>& array, int element) {
    bool found = false;
    for (size_t i = 0; i < array.size(); i++) {
        if (array[i] == element) {
            found = true;
            cout << "The element " << element << " is present at position " << i << endl;
        }
    }
    if (!found) {
        cout << "The element " << element << " is not present in the array." << endl;
    }
}

int main() {
    int n;
    cout << "Enter array size here (1-20): ";
    cin >> n;

    // Input validation
    if (n <= 0 || n > 20) {
        cout << "Invalid array size. Please enter a size between 1 and 20." << endl;
        return 1;
    }

    vector<int> b(n);
    cout << "Enter array elements here:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int temp;
    cout << "Enter the array element to find: ";
    cin >> temp;

    searchElement(b, temp);

    return 0;
}
