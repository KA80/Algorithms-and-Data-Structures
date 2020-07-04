#include <iostream>
#include <fstream>

using namespace std;

int comp(const void*, const void* );

int main() {
    ifstream fin;
    fin.open("input.txt");
    int N;
    fin >> N;
    int *nails = new int [N];
    for (int i = 0; i < N; i++){
        fin >> nails[i];
    }
    fin.close();
    qsort(nails, N, sizeof(int), comp);

    int *total_length = new int [N];
    total_length[0] = 0;

    for (int i = 0; i < N; i++){
        if (i == 1 || i == 2)
            total_length[i] = total_length[i - 1] + (nails[i] - nails[i - 1]);
        if (i >= 3)
            total_length[i] = min(total_length[i - 1] + (nails[i] - nails[i - 1]) ,total_length[i - 2] + (nails[i] - nails[i - 1]));
    }

    ofstream fout;
    fout.open("output.txt");
    fout << total_length[N - 1];
    fout.close();
    return 0;
}

int comp(const void* a, const void* b){
    return ( *(int*)a - *(int*)b );
}