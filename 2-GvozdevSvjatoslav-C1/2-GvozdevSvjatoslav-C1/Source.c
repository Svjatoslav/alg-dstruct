#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
 * CPU: Intel(R) Core(TM) i3 M 370 2.40 GHz
 * RAM: 4097 MB
 * SSD: 110 GB
 *
 * Vertecies amount: 30000
 *      Stress Test results:
 *      Memory: 2.5 GB
 *      DFS execution time: 28.375000 seconds
 *
 *
 */

int** CreateAdjencyMatrix(int size_of_graph) {
    char ch;
    int current;

    int** adjencyMatrix = (int**)malloc(size_of_graph * sizeof(int*));
    if (adjencyMatrix == NULL) {
        fprintf(stderr, "%s", "Error of allocting memory");
        exit(-1);
    }
    for (int i = 0; i < size_of_graph; i++) {
        adjencyMatrix[i] = (int*)calloc(size_of_graph, sizeof(int));
    }
    for (int i = 0; i < size_of_graph; i++) {
        ch = ' ';
        while (ch == ' ') {
            scanf("%i%c", &current, &ch);
            if (current != i) {
                adjencyMatrix[i][current] = 1;
                adjencyMatrix[current][i] = 1;

            }

        }
    }
    return adjencyMatrix;
}

int DFS(int vert, int size_of_graph, int* visited, int** matrix) {
    //printf("%d ",vert);
    visited[vert] = 1;
    for (int i = 1; i < size_of_graph; i++) {
        if (matrix[vert][i] != 0 && visited[i] != 1) {
            DFS(i, size_of_graph, visited, matrix);
        }
    }
}
void stress_test() {
    int test_value = 30000;

    int* visited = (int*)malloc(sizeof(int) * test_value);
    int** matrix1 = (int**)malloc(test_value * sizeof(int*));
    for (int i = 0; i < test_value; i++) {
        matrix1[i] = (int*)calloc(test_value, sizeof(int));
    }
    if (matrix1 == NULL) {
        fprintf(stderr, "%s", "Error of allocting memory");
        exit(-1);
    }
    for (int i = 0; i < test_value; i++) {
        for (int j = 0; j < test_value; j++) {
            matrix1[i][j] = rand() % 2;

        }

    }
    unsigned long start = clock();
    DFS(0, test_value, visited, matrix1);
    double time = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("%f\n", time);
}


int main() {
    int size_of_graph;
    scanf("%i", &size_of_graph);
    int* visited = (int*)malloc(sizeof(int) * size_of_graph);
    int** matrix = CreateAdjencyMatrix(size_of_graph);
    DFS(0, size_of_graph, visited, matrix);
    //stress_test();

}


