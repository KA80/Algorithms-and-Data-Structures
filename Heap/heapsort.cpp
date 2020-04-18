#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> heap;

void max_reverse(int value);
void sift_down_reverse(int index);

int main(){
    ifstream fin;
    fin.open("heapsort.in");
    ofstream fout;
    fout.open("heapsort.out");

    int n;
    fin >> n;

    for (int i = 0; i < n; i++){
        max_reverse(i + 1);
    }
    for (int i = 0; i < n; i++){
        fout << heap[i] << " ";
    }

    fin.close();
    fout.close();
    return 0;
}

void max_reverse(int value){
    if(heap.size() > 0)
        sift_down_reverse(heap.size() - 1);
    heap.push_back(value);
    swap(heap[0], heap[heap.size() - 1]);
}

void sift_down_reverse(int index){
    if(index == 0)
        return;
    int ind_par = (index - 1) / 2;
    if(heap[ind_par] > heap[index]){
        swap(heap[ind_par], heap[index]);
        sift_down_reverse(ind_par);
    }
}
