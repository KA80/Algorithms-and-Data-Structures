#include <iostream>
#include <fstream>
#include <vector>
#define link first
#define visited second

using namespace std;

vector<pair<vector<int>, bool>> modules;
//вектор модулей; first показывает с кем слинкован модуль,
// second - использован ли модуль в dfs

void dfs(int t) {
    modules[t].visited = true;
    for (int i: modules[t].link) {
        if (!modules[i].visited)
            dfs(i);
    }
}

int main() {
    ifstream fin("input.txt");

    int N, M;
    fin >> N >> M;

    for (int i = 0; i < N; i++)
        modules.emplace_back(vector<int>(), false);

    for (int i = 0; i < M; i++) {
        int tmp_1, tmp_2;
        fin >> tmp_1 >> tmp_2;
        modules[tmp_1 - 1].link.push_back(tmp_2 - 1);
        modules[tmp_2 - 1].link.push_back(tmp_1 - 1);
    }
    fin.close();

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (!modules[i].visited) {
            dfs(i);
            count++;
        }
    }

    ofstream fout("output.txt");
    fout << count;
    fout.close();
    return 0;
}
