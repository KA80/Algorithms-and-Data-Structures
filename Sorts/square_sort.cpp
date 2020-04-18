#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("output.txt");
    int N;
    fin >> N;
    long *mass = new long [N];
    for (int i = 0; i < N; i++)
        fin >> mass[i];
    fin.close();
    for (int i = 0; i < N - 1; i++){
        for (int j = i + 1; j < N; j++)
            if (mass[i] > mass[j])
                swap (mass[i], mass[j]);
        fout << mass[i] << " ";
    }
    fout << mass[N - 1];
    fout.close();
    return 0;
}
