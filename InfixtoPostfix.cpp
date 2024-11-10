#include <iostream>
#include <string>
using namespace std;

char exp[10];
int top = -1;

void push(char ele) {
    if (top < 9) {
        top++;
        exp[top] = ele;
    }
}

int check(char ele) {
    if (ele == '*' || ele == '/') {
        return 1;
    } else if (ele == '+' || ele == '-') {
        return 0;
    } else {
        return -1; // Return -1 for non-operator characters
    }
}

char pop() {
    if (top >= 0) {
        return exp[top--];
    }
    return '\0';
}

int main() {
    string a;
    int n;
    cout << "Enter the expression for conversion: ";
    getline(cin, a);
    n = a.length();

    for (int i = 0; i < n; i++) {
        if (a[i] == '*' || a[i] == '/' || a[i] == '+' || a[i] == '-') {
            // Check operator precedence and print operators from the stack
            while (top >= 0 && check(exp[top]) >= check(a[i])) {
                cout << pop();
            }
            push(a[i]);
        } else if (a[i] == '(') {
            push(a[i]);
        } else if (a[i] == ')') {
            while (top >= 0 && exp[top] != '(') {
                cout << pop();
            }
            pop(); // Pop the '(' from the stack
        } else {
            // Directly print operand characters
            cout << a[i];
        }
    }

    // Pop any remaining operators in the stack
    while (top >= 0) {
        cout << pop();
    }

    cout << endl;
    return 0;
}
