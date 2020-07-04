#include <iostream>
#include <fstream>
#include <vector>
#define MAX_N 13
#define COUNT_OF_CUBE_FACES 6

using namespace std;

bool is_used[MAX_N]; // использован ли куб
bool is_found = false; // найден ли набор
string nums; // числа использованных кубов в итоге
vector<string> letters_on_cube; // набор букв на кубике
string num_of_cube; // номер куба
string word; // какое должно получиться слово
int N; // количество кубов

void nums_of_cubes(int, int);

int main(){
    ifstream fin;
    fin.open("input.txt");
    fin >> N;
    fin >> word;
    for (int i = 0; i < N; i++){
        string tmp;
        fin >> tmp;
        letters_on_cube.push_back(tmp);
    }
    fin.close();

    nums_of_cubes(word.length(), 0);

    ofstream fout;
    fout.open("output.txt");
    if (nums.length()){
        for(int i : nums)
            fout << i << " ";
    }
    else{
        fout << "0";
    }
    fout.close();

    return 0;
}

void nums_of_cubes(int n, int k){
    if(is_found)
        return;
    if(n == k){
        for (int i = 0; i < n; i++)
            nums = num_of_cube;
        is_found = true;
        return;
    }
    for(int i = 0; i < N; i++){
        if(!is_used[i]){
            for(int j = 0; j < COUNT_OF_CUBE_FACES; j++){
                if (word[k] == letters_on_cube[i][j]){ // если буква на кубике совпадает с буквой слова
                    is_used[i] = true;
                    num_of_cube.push_back(i + 1);
                    nums_of_cubes(n, k + 1);
                    num_of_cube.pop_back();
                    is_used[i] = false;
                }
            }
        }
    }
}