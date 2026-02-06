/*
==============================================================================
PROJECT: GRAPH COLORING PROBLEM 

. Student: Amirali HajiShamsaie
. professor: Dr. Mina Masoudifar
. Course: Algorithms design

. GitHub Repository: https://github.com/amhajii/GraphColoring.git

==============================================================================

PROBLEM STATEMENT:
The objective is to assign colors to the vertices of a graph such that no two 
adjacent vertices share the same color. The algorithm calculates the minimum 
number of colors required to achieve this.

INPUT:
   - Adjacency Matrix representing the graph.

OUTPUT:
1. Console Output:
   - Minimum number of colors (Chromatic Number).
   - Color assignment for each vertex.

2. Graphical Output:
    - Not implemented yet. Sorry :(

ALGORITHM:
The solution is implemented using a Backtracking algorithm. 
The program starts checking with m=1 (1 color) and increments m until a valid 
coloring is found for all vertices. This ensures the minimum number of colors 
is determined.
*/


#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;


bool isValidColor(int v, vector<vector<int>>& graph, int color[], int c) {

    // can we assign color c to vertex v?
    // - v: current vertex
    // - c: current color to assign
    // return false if any adjacent vertex has the same color c

    for (int i = 0; i < graph.size(); i++)
        if (graph[v][i] == 1 && c == color[i])
            return false;
    //else
    return true;
}

bool Coloring(vector<vector<int>>& graph, int m, int color[], int v) { 

    //  Can we color graph with m colors?
    //  - m: number of colors
    //  - v: current vertex to color
    //  - Algorithm: backtracking


    // condition of success: all vertices are colored
    if (v == graph.size())
        return true;


    for (int c = 1; c <= m; c++) { // c : current color
        if (isValidColor(v, graph, color, c)) {
            color[v] = c;
            if (Coloring(graph, m, color, v+1))
                return true;

            color[v] = 0; 
        }
    }
    return false;
}



int main() {

    // Graph : 
    //   - representation with adjacency matrix
    //   - (Sorry): not implemented any func for geting custom graph from user input, 
    //              but you can change the graph variable to test with different graphs.
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };


    bool isSuccess = false; 
    int n = graph.size();
    int color[n]; 


    // Try for minimum number of colors (starting from 1)
    for (int m = 1; m <= n; m++) { 

        for (int i = 0; i < n; i++) color[i] = 0; // initialize color array (calibrate it) 

        isSuccess = Coloring(graph, m, color, 0); 
        if (isSuccess) {
            // print the results

            cout << "Minimum Colors: " << m << endl;
            cout << "Color Assignment: ";
            for (int i = 0; i < n; i++) cout << color[i] << " ";
            cout << endl;

            break; // stop after finding the minimum number of colors needed
        }
    }

    if (!isSuccess) cout << "No valid coloring exists for the given graph." << endl;
    


    return 0;
}