#include <iostream>
#include <fstream>
#include <vector>

#define x first
#define y second

using namespace std;

int main() {
    ifstream fin("input.txt");

    int N, x0, y0, x1, y1;
    fin >> N >> x0 >> y0 >> x1 >> y1;

    vector<string> field;
    for (int i = 0; i < N; i++){
        string tmp;
        fin >> tmp;
        field.push_back(tmp);
    }
    fin.close();

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int first = 0, last = 1;
    vector<vector<int>> dist(N, vector<int>(N, 0));
    vector<pair<int, int>> way;

    dist[y0 - 1][x0 - 1] = 0;
    way.emplace_back(x0 - 1, y0 - 1);

    while (first < last)
    {
        pair<int, int> cur_point = way[first];
        first++;
        for (int i = 0; i < 4; i++){
            pair<int, int> next_point = make_pair(cur_point.x + dx[i], cur_point.y + dy[i]);
            if (0 <= next_point.x && next_point.x < N && 0 <= next_point.y && next_point.y < N ){
                if (field[next_point.y][next_point.x] == '.' && dist[next_point.y][next_point.x] == 0){
                    dist[next_point.y][next_point.x] = dist[cur_point.y][cur_point.x] + 1;
                    way.push_back(next_point);
                    last++;
                }
            }
        }
    }

    ofstream fout("output.txt");
    fout << dist[y1 - 1][x1 - 1];
    fout.close();
    return 0;
}