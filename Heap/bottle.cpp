#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> heap;

void add_new(long long value);//добавление нового элемента в кучу
void sift_up(long long index);//просеивание вверх нового элемента
long long extract_max();//вывод максимального числа из кучи
void sift_down(long long index);//просеивание вниз, когда выводим максимальное число

int main(){
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("output.txt");

    long long N, M;
    fin >> N >> M;

    //добавляем в кучу жажду каждого ученика
    for (long long i = 0; i < N; i++){
        long long temp;
        fin >> temp;
        add_new(temp);
    }

    //M глотков
    for (long long i = 0; i < M; i++){
        long long temp = extract_max();
        temp = floor(double(temp) / 10);
        add_new(temp);
    }

    //суммируем жажду и выводим
    long long sum = 0;
    for(long long i = 0; i < N; i++)
        sum += heap[i];
    fout << sum;

    fin.close();
    fout.close();
    return 0;
}

void sift_up(long long index){
    long long int_par = (index - 1) / 2;
    if (index && heap[int_par] < heap[index]){
        swap(heap[int_par], heap[index]);
        sift_up(int_par);
    }
}

void add_new(long long value){
    heap.push_back(value);
    sift_up(heap.size() - 1);
}

void sift_down(long long index){
    long long ind_left_child = index * 2 + 1;
    long long ind_right_child = index * 2 + 2;
    long long ind_new = index;
    if (ind_left_child < heap.size() && heap[ind_left_child] > heap[ind_new])
        ind_new = ind_left_child;
    if (ind_right_child < heap.size() && heap[ind_right_child] > heap[ind_new])
        ind_new = ind_right_child;
    if (ind_new != index){
        swap(heap[index], heap[ind_new]);
        sift_down(ind_new);
    }
}

long long extract_max(){
    long long max = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.erase(heap.end() - 1);
    sift_down(0);
    return max;
}
