#include <iostream>
using namespace std;

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

    //sparse array structure is built

    int sparse_rows[sparse_elmnt_count];
    int sparse_cols[sparse_elmnt_count];
    float sparse_values[sparse_elmnt_count];

    //sparse array is filled

    sparse_elmnt_count = 0;
    for (int trad_row_coord = 0; trad_row_coord < trad_mat_row_int; trad_row_coord++){
        for (int trad_col_coord = 0; trad_col_coord < trad_mat_col_int; trad_col_coord++){
            if (trad_mat[trad_row_coord][trad_col_coord] != 0){
                sparse_rows[sparse_elmnt_count] = trad_row_coord;
                sparse_cols[sparse_elmnt_count] = trad_col_coord;
                sparse_values[sparse_elmnt_count] = (trad_mat[trad_row_coord][trad_col_coord]);
                sparse_elmnt_count++;
            } else {
                continue;
                }
        }
    }


    //sparse array row indexes are outputted

    cout << "\nSparse Array Representation:\n[";
    for (int sparse = 0; sparse < sparse_elmnt_count; sparse++){
    if (sparse != (sparse_elmnt_count - 1)){
        cout << sparse_rows[sparse] << ", ";
    } else {
        cout << sparse_rows[sparse] << "]\n[";
        }
    }

    //sparse array column indexes are outputted

    for (int sparse = 0; sparse < sparse_elmnt_count; sparse++){
    if (sparse != (sparse_elmnt_count - 1)){
        cout << sparse_cols[sparse] << ", ";
    } else {
        cout << sparse_cols[sparse] << "]\n[";
        }
    }

    //sparse array values are outputted

    for (int sparse = 0; sparse < sparse_elmnt_count; sparse++){
    if (sparse != (sparse_elmnt_count - 1)){
        cout << sparse_values[sparse] << ", ";
    } else {
        cout << sparse_values[sparse] << "]\n";
        }
    }



    return 0;
}
