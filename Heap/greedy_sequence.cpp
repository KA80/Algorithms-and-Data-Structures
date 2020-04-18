#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long LONG;
typedef pair<LONG, LONG> PAIR;

class min_heap{
public:
    vector<pair <LONG, LONG>> heap;
    void sift_up(LONG index){
        LONG ind_par = (index - 1) / 2;
        if (index && (heap[ind_par].first > heap[index].first || (heap[ind_par].first == heap[index].first && heap[ind_par].second > heap[index].second))){
            swap(heap[ind_par], heap[index]);
            sift_up(ind_par);
        }
    }
    void add_new(LONG value, LONG ind){
        heap.emplace_back(value, ind);
        sift_up(heap.size() - 1);
    }
    void sift_down(LONG index){
        LONG ind_left_child = index * 2 + 1;
        LONG ind_right_child = index * 2 + 2;
        LONG ind_new = index;
        if (ind_right_child < heap.size() && heap[ind_right_child].first <= heap[ind_new].first)
            ind_new = ind_right_child;
        if (ind_left_child < heap.size() && heap[ind_left_child].first <= heap[ind_new].first)
            ind_new = ind_left_child;
        if (heap[ind_left_child].first == heap[ind_right_child].first && heap.size() > ind_right_child && heap.size() > ind_left_child){
            if (heap[ind_left_child].second > heap[ind_right_child].second)
                ind_new = ind_right_child;
            else
                ind_new = ind_left_child;
        }
        if (ind_new != index){
            swap(heap[index], heap[ind_new]);
            sift_down(ind_new);
        }
    }
    PAIR extract_min(){
        PAIR min = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.erase(heap.end() - 1);
        sift_down(0);
        return min;
    }
};

bool comp_for_index(PAIR a, PAIR b){
    return (a.second < b.second);
}

int main(){
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("output.txt");

    LONG N, M;
    fin >> N >> M;

    min_heap sequence;

    for (LONG i = 0; i < N; i++){
        LONG tmp;
        fin >> tmp;
        sequence.add_new(tmp, i);
    }
    
    for (LONG i = 0; i < M; i++){
        PAIR first_min = sequence.extract_min();
        PAIR second_min = sequence.extract_min();
        PAIR sum_of_min;
        sum_of_min.first = first_min.first + second_min.first;
        sum_of_min.second = N + i;
        sequence.add_new(sum_of_min.first, sum_of_min.second);
    }

    sort(sequence.heap.begin(), sequence.heap.end(), comp_for_index);

    for (LONG i = 0; i < N - M ; i++){
        fout << sequence.heap[i].first << " ";
    }

    fin.close();
    fout.close();
    return 0;
}

