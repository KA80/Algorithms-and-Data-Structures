#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class max_heap{
public:
    vector<long long> heap;
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
};
class min_heap{
public:
    vector<long long> heap;
    void sift_up(long long index){
        long long int_par = (index - 1) / 2;
        if (index && heap[int_par] > heap[index]){
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
        if (ind_left_child < heap.size() && heap[ind_left_child] < heap[ind_new])
            ind_new = ind_left_child;
        if (ind_right_child < heap.size() && heap[ind_right_child] < heap[ind_new])
            ind_new = ind_right_child;
        if (ind_new != index){
            swap(heap[index], heap[ind_new]);
            sift_down(ind_new);
        }
    }
    long long extract_min(){
        long long min = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.erase(heap.end() - 1);
        sift_down(0);
        return min;
    }
};

int main(){
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("output.txt");

    int n;
    fin >> n;

    max_heap left_heap;
    min_heap right_heap;

    for (int i = 0; i < n; i++){
        int tmp;
        fin >> tmp;
        if ((i + 1) % 2 == 0){
            if(tmp < left_heap.heap[0]){
                right_heap.add_new(left_heap.extract_max());
                left_heap.add_new(tmp);
            }
            else{
                right_heap.add_new(tmp);
            }
        }
        else{
            if(i > 0 && tmp > right_heap.heap[0]){
                left_heap.add_new(right_heap.extract_min());
                right_heap.add_new(tmp);
            }
            else{
                left_heap.add_new(tmp);
            }
        }
        fout << left_heap.heap[0] << " ";


    }


    fin.close();
    fout.close();
    return 0;
}



