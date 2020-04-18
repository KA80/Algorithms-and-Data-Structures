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
    int *x = new int [N], *y = new int [N];
    for(int i = 0; i < N; i++)
        fin >> x[i] >> y[i];
    fin.close();
    int max = 0, luminosity[100] = {0};
    for (int i = 0; i < N; i++){
        for(int j = x[i] - y[i]; j < x[i] + y[i]; j++){
            if(j >= 0 && j <= 100)
                luminosity[j]++;
        }
    }
    for (int i = 0; i < 100; i++)
        if(luminosity[i] > max)
            max = luminosity[i];
     fout << max;
     fout.close();
    return 0;
}
