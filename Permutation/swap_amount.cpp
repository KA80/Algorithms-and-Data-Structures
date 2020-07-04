#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    ifstream fin;
    fin.open("input.txt");
    string a, b;
    int c;
    fin >> a >> b >> c;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ofstream fout;
    fout.open("output.txt");

    vector<int> x;
    do{
        if(a[0] != '0'){
            string y = to_string(c - stoi(a));
            if (is_permutation(y.begin(), y.end(), b.begin())){
                fout << "YES" << endl << a << " " << y;
                return 0;
            }
        }
    }while(next_permutation(a.begin(), a.end()));


    fout << "NO";
    return 0;
}