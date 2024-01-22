#include <iostream>
using namespace std;

 struct SparseNode
    {
        int row;
        int column;
        float value;
        struct SparseNode *link;
    };

    class SparseList
    {
        private:
        struct SparseNode
    {
        int row;
        int column;
        float value;
        struct SparseNode *link;
    };

        SparseNode *head;
        public:
        SparseList()
        { head = NULL; }
        void appendNode(int,int,float);
        void displayList();
    };

    void SparseList::appendNode(int mat_row, int mat_col, float mat_value)
    {
        SparseNode *newNode, *nodePtr;
        newNode = new SparseNode;
        newNode->row = mat_row;
        newNode->column = mat_col;
        newNode->value = mat_value;
        newNode->link = NULL;
        if (!head){
            head = newNode;
        }else
        {
            nodePtr = head;
            while (nodePtr->link)
                nodePtr = nodePtr->link;
            nodePtr->link = newNode;
        }
    }

    void SparseList::displayList()
    {
        if (!head)
        {
            cout << "The list is empty.\n";
        }
        else
        {
            cout << "Linked List Shown using displayList function [Row, Column, Value]\n";
            SparseNode *nodePtr;
            nodePtr = head;
            while (nodePtr)
            {
                cout << "[" << nodePtr->row << ", " << nodePtr->column << ", " << nodePtr->value << "]\n";
                nodePtr = nodePtr->link;
            }
        }
    }


int main() {

    //user inputs no. of columns of the traditional matrix

    float trad_mat_col;
    cout << "Please enter the number of columns in your matrix:\n";
    cin >> trad_mat_col;

    while (cin.fail() ||
            trad_mat_col < 1 ||
            trad_mat_col > 100 ||
            (trad_mat_col - static_cast<int>(trad_mat_col) != 0)) {
        cout << "Invalid entry. Input a whole number between 1 and 100:\n";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> trad_mat_col;
    }

    int trad_mat_col_int = static_cast<int>(trad_mat_col);


    //user inputs no. of rows of the traditional matrix

        float trad_mat_row;
    cout << "Please enter the number of rows in your matrix:\n";
    cin >> trad_mat_row;

    while (cin.fail() ||
            trad_mat_row < 1 ||
            trad_mat_row > 100 ||
            (trad_mat_row - static_cast<int>(trad_mat_row) != 0)) {
        cout << "Invalid entry. Input a whole number between 1 and 100:\n";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> trad_mat_row;
    }

    int trad_mat_row_int = static_cast<int>(trad_mat_row);

    //traditional array structure is built

    float trad_mat[trad_mat_row_int][trad_mat_col_int];

    //user inputs individual values

    for (int trad_row_coord = 0; trad_row_coord < trad_mat_row_int; trad_row_coord++){
        for (int trad_col_coord = 0; trad_col_coord < trad_mat_col_int; trad_col_coord++){
            float mat_value;
            cout << "Please enter the value at row " << trad_row_coord << " column " << trad_col_coord << ":\n";
            cin >> mat_value;

            while (cin.fail() ||
            mat_value < -100 ||
            mat_value > 100) {
            cout << "Invalid entry. Input a number between -100 and 100:\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> mat_value;

    }
        trad_mat[trad_row_coord][trad_col_coord] = mat_value;

        }
    }

    //program counts all non-zero matrix elements

    int sparse_elmnt_count = 0;
    for (int trad_row_coord = 0; trad_row_coord < trad_mat_row_int; trad_row_coord++){
        for (int trad_col_coord = 0; trad_col_coord < trad_mat_col_int; trad_col_coord++){
            if (trad_mat[trad_row_coord][trad_col_coord] != 0){
                sparse_elmnt_count++;
            } else {
                continue;
                }

        }
    }

    SparseList mat;

    for (int trad_row_coord = 0; trad_row_coord < trad_mat_row_int; trad_row_coord++){
        for (int trad_col_coord = 0; trad_col_coord < trad_mat_col_int; trad_col_coord++){
            if (trad_mat[trad_row_coord][trad_col_coord] != 0){
                mat.appendNode(trad_row_coord, trad_col_coord, (trad_mat[trad_row_coord][trad_col_coord]));
            } else {
                continue;
                }
        }
    }


    mat.displayList();

        return 0;
}
