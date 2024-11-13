#include <iostream>
using namespace std;

#define MAX_SIZE 1000

int main() {
    int n, arr[MAX_SIZE];



    cout << "Enter the number of element : ";
    cin >> n;


    for (int i = 0; i < n; i++) {
        cout<<"Enter number "<<i+1<<" : ";
        cin >> arr[i];
    }


    int stack[MAX_SIZE], top = -1;
    stack[++top] = 0;
    stack[++top] = n - 1;

    while (top >= 0) {

        int high = stack[top--];
        int low = stack[top--];


        int pivot = arr[high];
        int i = low - 1;


        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;


        int pi = i + 1;


        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }


        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }


    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

