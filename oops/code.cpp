#include <iostream>
#include <vector>
using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int array_size;
        cin >> array_size;

        vector<int> numbers(array_size);
        for (int &num : numbers) {
            cin >> num;
        }

        // Check if the array size is less than or equal to 2
        if (array_size <= 2) {
            cout << "-1\n";
        } else {
            // Find the positions of 1 and 3 in the array
            int position_one = -1, position_three = -1;
            for (int i = 0; i < array_size; ++i) {
                if (numbers[i] == 1) {
                    position_one = i;
                } else if (numbers[i] == 3) {
                    position_three = i;
                }
            }

            // Swap the values at positions of 1 and 3
            swap(numbers[position_one], numbers[position_three]);

            // Print the modified array
            for (int num : numbers) {
                cout << num << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
