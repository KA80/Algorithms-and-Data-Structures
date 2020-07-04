#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream fin;
    fin.open("input.txt");
    int n;
    fin >> n;
    int *a = new int [n];
    for (int i = 0; i < n; i++)
        fin >> a[i];
    fin.close();

    vector<int> sum_stairs;
    sum_stairs.push_back(a[0]);

    if(n > 1){

        if (sum_stairs[0] > 0)
            sum_stairs.push_back(sum_stairs[0] + a[1]);
        else
            sum_stairs.push_back(a[1]);

        if (n > 2){

            for (int i = 2; i < n; i++){
                if(sum_stairs[i - 1] > sum_stairs[i - 2])
                    sum_stairs.push_back(sum_stairs[i - 1] + a[i]);
                else
                    sum_stairs.push_back(sum_stairs[i - 2] + a[i]);
            }

        }
    }

    ofstream fout;
    fout.open("output.txt");
    fout << sum_stairs[sum_stairs.size() - 1];
    fout.close();
    return 0;
}
