#include <iostream>
#include <fstream>

using namespace std;

void quick_sort(long *mass, int left, int right);

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
    quick_sort(mass, 0, N - 1);
    for (int i = 0; i < N; i++)
        fout << mass[i] << " ";
    fout.close();
    return 0;
}

void quick_sort(long *mass, int left, int right){
    int l_hold = left, r_hold = right;
    while (l_hold < r_hold){
        while (mass[l_hold] < mass[r_hold])
            l_hold++;
        while (((mass[r_hold - 1] >= mass[r_hold]) || (mass[l_hold] >= mass[r_hold])) && (l_hold != r_hold)) {
            if (mass[l_hold] < mass[r_hold])
                l_hold++;
            else {
                if ((l_hold != r_hold - 1)) {
                    swap(mass[r_hold], mass[l_hold]);
                    swap(mass[l_hold],mass[r_hold - 1]);
                    r_hold--;
                } else {
                    swap(mass[l_hold], mass[r_hold]);
                    r_hold--;
                }
            }
        }
    }
    if (r_hold > left)
        quick_sort(mass, left, r_hold - 1);
    if (r_hold < right)
        quick_sort(mass, l_hold + 1, right);
}
