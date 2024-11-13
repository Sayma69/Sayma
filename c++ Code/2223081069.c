#include <iostream>
using namespace std;

int main()
{
    int sequence_input[] = {10, 20, 30, 40, 50, 60, 500, 80};
    int arr_size = sizeof(sequence_input) / sizeof(sequence_input[0]);
    int max_sequence = sequence_input[0];

    for (int i = 0; i < arr_size; i++){
        if (sequence_input[i] > max_sequence){
            max_sequence = sequence_input[i];
        }
    }

    cout << "The maximum number of sequences is " << max_sequence << endl;
    return 0;
}
