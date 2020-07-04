#include <iostream>
#include <vector>
#include <fstream>
#define cost first
#define weight second
#define MAX 10000000

using namespace std;

int main(){
    ifstream fin;
    fin.open("input.txt");
    vector<pair<int, int >> coin;
    int E, F, N;
    fin >> E >> F >> N;
    int capacity = F - E + 1;
    vector<int> dp(capacity);
    dp[0] = 0;
    for (int i = 0; i < N; i++){
        int C, W;
        fin >> C >> W;
        coin.emplace_back(C, W);
    }
    fin.close();

    for (int i = 1; i < capacity; i++){
        dp[i] = MAX;
        for (int j = 0; j <= N; j++){
            if (coin[j].weight <= i) // если вес монеты меньше
                dp[i] = min(dp[i], dp[i - coin[j].weight] + coin[j].cost); // выбор меньшего
        }
    }
    int result = dp[F - E];

    ofstream fout;
    fout.open("output.txt");
    if (result == MAX)
        fout << -1;
    else
        fout << result;
    fout.close();
    return 0;
}