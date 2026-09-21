#include <iostream>
#include <vector>
using namespace std;

struct MatrixNode {
    int data;
    MatrixNode* next;
    MatrixNode* prev;
    MatrixNode* up;
    MatrixNode* down;
    MatrixNode(int val) : data(val), next(nullptr), prev(nullptr), up(nullptr), down(nullptr) {}
};

MatrixNode* construct4WayDLL(vector<vector<int>>& mat) {
    int rows = mat.size();
    if (rows == 0) return nullptr;
    int cols = mat[0].size();

    vector<vector<MatrixNode*>> nodeMat(rows, vector<MatrixNode*>(cols, nullptr));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            nodeMat[i][j] = new MatrixNode(mat[i][j]);
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (j + 1 < cols) {
                nodeMat[i][j]->next = nodeMat[i][j + 1];
                nodeMat[i][j + 1]->prev = nodeMat[i][j];
            }
            if (i + 1 < rows) {
                nodeMat[i][j]->down = nodeMat[i + 1][j];
                nodeMat[i + 1][j]->up = nodeMat[i][j];
            }
        }
    }
    return nodeMat[0][0];
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    MatrixNode* head = construct4WayDLL(matrix);
    cout << "2D Matrix successfully converted to 4-way connected DLL.\n";
    return 0;
}