#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<pair<string, int>> answers;
string supposed_answer;
string final_answer;
bool is_found = false;

void allocate_memory_for_string(int);
void print_answer(int, int, int);

int main(){
    ifstream fin;
    fin.open("input.txt");
    int P, Q;
    fin >> P >> Q;
    for (int i = 0; i < P; i++){
        string answer;
        int count_of_right;
        fin >> answer;
        fin >> count_of_right;
        answers.emplace_back(answer, count_of_right);
    }
    fin.close();
    ofstream fout;
    fout.open("output.txt");

    allocate_memory_for_string(Q);
    print_answer(P, Q, 0);

    fout << final_answer;

    fout.close();
    return 0;
}

void print_answer(int n, int m, int t){
    if (is_found)
        return;
    if (t == m){
        bool is_all_equal = true;
        for (int i = 0; i < n; i++){
            int matched = 0;
            for (int j = 0; j < m; j++){
                if (supposed_answer[j] == answers[i].first[j])
                    matched++;
            }
            if (matched != answers[i].second){
                is_all_equal = false;
                break;
            }
        }
        if (is_all_equal){
            final_answer = supposed_answer;
            is_found = true;
        }
        return;
    }
    supposed_answer[t] = '+';
    print_answer(n, m, t + 1);
    supposed_answer[t] = '-';
    print_answer(n, m, t + 1);
}

void allocate_memory_for_string(int n){
    for (int i = 0; i < n; i++)
        supposed_answer.push_back('\0');
}