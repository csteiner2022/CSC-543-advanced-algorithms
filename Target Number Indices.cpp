#include <iostream>
using namespace std;

int main() {

    // user enters the target number
    float target_num;
    cout << "Please enter the target number:\n";
    cin >> target_num;

    while (cin.fail() ||
            target_num < -109 ||
            target_num > 109 ||
            (target_num - static_cast<int>(target_num) != 0)) {
        cout << "Invalid entry. Input an integer between -109 and 109:\n";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> target_num;
    }
    int target_int = static_cast<int>(target_num);

    // user enters number of array elements

    float numlength;
    cout << "Please enter the number of elements the array will contain:\n";
    cin >> numlength;

    while (cin.fail() ||
            numlength < 2 ||
            numlength > 104 ||
            (numlength - static_cast<int>(numlength) != 0)) {
        cout << "Invalid entry. Input a whole number between 2 and 104:\n";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> numlength;
    }

    int numlengthint = static_cast<int>(numlength);

    int nums[numlengthint];
    int nums_copy[numlengthint];

    // user inputs each array element

    for (int indx = 0; indx < numlengthint; indx++) {

        float possible_exceptions;
        cout << "Type in element ";
        cout << (indx + 1);
        cout << ":\n";
        cin >> possible_exceptions;

          while (cin.fail() ||
            possible_exceptions < -109 ||
            possible_exceptions > 109 ||
            (possible_exceptions - static_cast<int>(possible_exceptions) != 0)) {
            cout << "Invalid entry. Input an integer between -109 and 109:\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> possible_exceptions;
    }

        /* here I make two identical arrays so that
            I can use a nested 'for loop' to check each combo
            of elements.*/
        nums[indx] = static_cast<int>(possible_exceptions);
        nums_copy[indx] = static_cast<int>(possible_exceptions);
    }

    //calculation of the index pair

    int element1 = 105;
    int element2 = 105;

    for (int numsindx = 0; numsindx < numlengthint; numsindx++){
        for(int numscopyindx = 0; numscopyindx < numlengthint; numscopyindx++){
            if(numscopyindx == numsindx){
                continue;
            } else if((nums[numsindx] + nums_copy[numscopyindx]) == target_int) {
                element1 = numsindx;
                element2 = numscopyindx;
                break;
            } else {
                continue;
            }
        }
    }
    if (element1 == 105 && element2 == 105){
        cout << "No possible solution";
    } else {
    cout << "The solution is:\n[" << element2 << "," << element1 << "]";
    }

    return 0;
}

