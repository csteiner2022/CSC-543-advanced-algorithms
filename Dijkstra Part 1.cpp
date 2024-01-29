#include <iostream>
#include <cfloat>
using namespace std;


void printPath(int last_vert[], int current_vert) {
    if (last_vert[current_vert] == -1) {
        cout << current_vert;
        return;
    }
    printPath(last_vert, last_vert[current_vert]);
    cout << " -> " << current_vert;
}


int main() {

    //user inputs no. of vertices

    float vertex_total;
    cout << "Please enter the number of vertices in your graph:\n";
    cin >> vertex_total;

    while (cin.fail() ||
            vertex_total < 1 ||
            vertex_total > 100 ||
            (vertex_total - static_cast<int>(vertex_total) != 0)) {
        cout << "Invalid entry. Input a whole number between 1 and 100:\n";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> vertex_total;
    }

    int vertex_total_int = static_cast<int>(vertex_total);

    //traditional array structure is built

    float trad_mat[vertex_total_int][vertex_total_int];


    cout <<"Your vertices will be numbered 0-" << vertex_total - 1 << ".\n";
    cout <<"The source vertex will be assumed to be number 0.";
    cout <<"In the following section you will be asked to provide \n";
    cout <<"the weight of the edge traveling from one node to another.\n";
    cout <<"Please enter only a number valued 1 to 100. If no such edge \n";
    cout <<"exists please enter, instead, \"9999\".\n";

    for (int trad_row_coord = 0; trad_row_coord < vertex_total_int; trad_row_coord++){
        for (int trad_col_coord = 0; trad_col_coord < vertex_total_int; trad_col_coord++){
            if (trad_row_coord == trad_col_coord){
                trad_mat[trad_row_coord][trad_col_coord] = 0;
                continue;
            } else {
            float mat_value;
            cout << "Please enter the weight of the edge from vertex: " << trad_row_coord << " to vertex: " << trad_col_coord << ":\n";
            cin >> mat_value;

            while ((cin.fail() ||
            mat_value < 0  ||
            mat_value > 100) &&
            mat_value != 9999) {
            cout << "Invalid entry. Input a number between 0 and 100:\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> mat_value;

    }
        if (mat_value == 9999){
        trad_mat[trad_row_coord][trad_col_coord] = FLT_MAX;
        } else {
        trad_mat[trad_row_coord][trad_col_coord] = mat_value;
        }
        }
        }
    }

    //program initializes all vertices as unvisited

    bool visited[vertex_total_int] = {false};
    for (int initial = 0; initial < vertex_total_int; initial++){
        visited[initial] = false;
    }

    //program initializes the "shortest distance" array with the
    //first/source node set to zero and the rest set to infinity

    float short_dist[vertex_total_int];
    short_dist[0] = 0;
    for (int initial = 1; initial < vertex_total_int; initial++){
        short_dist[initial] = FLT_MAX;
    }

    //program initializes array of last vertices. The program sets
    //each vertices' last vertex as -1 to start, to be changed later.

    int last_vert[vertex_total_int];
    for (int initial = 0; initial < vertex_total_int; initial++){
        last_vert[initial] = -1;
    }


    //several nested for loops here accomplishing main goal. First is overall loop that
    //that cycles through each vertex.

    for (int vert = 0; vert < vertex_total_int; vert++){
        float min_dist = FLT_MAX;
        int min_vert;


        //the for loop here determines if a shorter alternative exists
        for (int trial = 0; trial < vertex_total_int; trial++){
            if (visited[trial] == false && short_dist[trial] <= min_dist){
                min_dist = short_dist[trial];
                min_vert = trial;
            }
        }

        //program updates visited status of the vertex
        visited[min_vert] = true;

        for (int v = 0; v < vertex_total_int; v++)
            if (visited[v] == false &&
                trad_mat[min_vert][v] != FLT_MAX &&
                short_dist[min_vert] != FLT_MAX &&
                (short_dist[min_vert] + trad_mat[min_vert][v]) < short_dist[v]){
                    short_dist[v] = short_dist[min_vert] + trad_mat[min_vert][v];
                    last_vert[v] = min_vert;
                } else {
                continue;}
    }

    for (int print_vert = 0; print_vert < vertex_total_int; print_vert++){
        cout << "0 -> " << print_vert << ", Cost: " << short_dist[print_vert] << ", ";
        printPath(last_vert, print_vert);
        cout << "\n";

    }

        return 0;
}
