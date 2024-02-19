#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//Program defines node struct.
struct huffmanNode
{
    char sample_char;
    int char_freq;
    huffmanNode* llink;
    huffmanNode* rlink;

    huffmanNode(char sample_char = '\0', int char_freq = 0, huffmanNode* llink = nullptr, huffmanNode* rlink = nullptr)
        : sample_char(sample_char), char_freq(char_freq), llink(llink), rlink(rlink) {}
};


//Program recursively calls itself and
//branches to produce preordered movement through the tree
void printHuffmanCodes(huffmanNode* current, string binary) {
    if (current != nullptr) {
        if ((current->llink == nullptr) && (current->rlink == nullptr)) {
            cout << current->sample_char << " : " << binary << endl;
        }
        printHuffmanCodes(current->llink, binary + "0");
        printHuffmanCodes(current->rlink, binary + "1");
    }
}


int main () {
    string sample;
    cout << "Please enter the sample string:\n";
    getline(cin, sample);

    // I should have modified the code
    //here to include better error handling.
    //However I had difficulty figuring out how to
    //check for duplicated letters in the 'sample' string.

    vector<int> freq(sample.length());

    //program requests an integer for the frequency value.
    //Error handles cases incorrect type and value less than 0.

    for (int i = 0; i < sample.length(); i++){
        float test;
        cout << "Please enter the frequency of the character \"" << sample[i] << "\":\n";
        cin >> test;

        while (cin.fail() ||
            test < 0 ||
            (test - static_cast<int>(test) != 0)) {
        cout << "Invalid entry. Input a whole number:\n";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> test;
        }

        freq[i] = static_cast<int>(test);
    }


    //Program creates a 1d vector to handle the min heap
    vector<huffmanNode> huff_heap(sample.length());

    for (int i = 0; i < sample.length(); i++){
        huff_heap[i] = huffmanNode(sample[i], freq[i], NULL, NULL);
    }

    huffmanNode* root = nullptr;

    //Program uses while loop to create the binary tree structure
    //first sorts by frequency
    //assigns two nodes with smallest frequncy to variables
    // creates new internal node with a null character value
    //and pointers to the smallest frequency nods.
    //removes the two values and runs again until only one value in vector.
    while (huff_heap.size() > 1) {
        sort(huff_heap.begin(), huff_heap.end(), [](const huffmanNode& left, const huffmanNode& right) {
            return left.char_freq < right.char_freq;
        });

        huffmanNode* left1 = new huffmanNode(huff_heap[0]);
        huffmanNode* right1 = new huffmanNode(huff_heap[1]);

        root = new huffmanNode('\0', left1->char_freq + right1->char_freq, left1, right1);

        huff_heap.erase(huff_heap.begin());
        huff_heap.erase(huff_heap.begin());
        huff_heap.push_back(*root);
    }

    //Program runs the print
    cout << "\n";
    printHuffmanCodes(root, "");


    return 0;
}
