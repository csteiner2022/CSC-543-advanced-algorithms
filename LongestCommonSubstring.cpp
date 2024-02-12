#include <iostream>
#include <vector>
using namespace std;


void LCS(string string1, string string2) {


        //program takes in two strings
        int str1_len = string1.length();
        int str2_len = string2.length();

        int substrings[str1_len + 1][str2_len + 1];


        //program initializes all elements in 2d array to 0
        for (int i = 0; i < str1_len + 1; i++) {
            for (int j = 0; j < str2_len + 1; j++) {
                 substrings[i][j] = 0;
            }
        }


        int maxLength = 0;
        int endIndex = 0;


        //Program tests for all common substrings
        for (int i = 1; i < str1_len + 1; i++) {
            for (int j = 1; j < str2_len + 1; j++) {
                if (string1[i-1] == string2[j-1]) {
                    substrings[i][j] = substrings[i-1][j-1] + 1;
                    if (substrings[i][j] > maxLength){
                        maxLength = substrings[i][j];
                        endIndex = i;
                    }
                } else {
                    substrings[i][j] = 0;
                    }
                }
            }

        //Program writes first string across top of grid

        cout << "\n";
        cout << "    ";
        for (int letter = 0; letter < str2_len + 1; letter++){
            cout << string2[letter] << " ";
        }
        cout << "\n  ";


        //Program displays matrix as grid
        for (int i = 0; i < str1_len + 1; i++) {
            for (int j = 0; j < str2_len + 2; j++) {
                 if (j < str2_len + 1){
                    cout << substrings[i][j] << " ";
                 } else {
                    //Program jumps to next line and
                    //inserts a letter from the second string
                    cout << "\n" << string1[i] << " ";
                    }
            }
        }

        cout << "\n";

        //LCS is displayed one character at a time
        for (int letter = (endIndex - maxLength); letter < endIndex; letter++){
            cout << string1[letter];
        }

        cout << "\n";

    }

int main() {

    cout << "To find the Longest Common Substring, please enter two strings.\nString 1: ";
    string first_string;
    cin >> first_string;
    cout << "String 2: ";
    string sec_string;
    cin >> sec_string;

    LCS(sec_string, first_string);

    return 0;
}

