#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> used; // для проверки использована ли вершина
vector<int> dist;  // переменная для записи расстояния до вершин
vector<vector<pair<int, int>>> info; // базовые данные, каждая вершина хранит:
                                    // количество ребер(пара - в какую вершину, какой вес имеет ребро)

void dijkstra(int);

int main(){
    ifstream fin("input.txt");
    int N, M, S;
    fin >> N >> M >> S;

    for (int i = 0; i < N; i++){ // выделяем память под структуры
        info.emplace_back();
        dist.push_back(INT_MAX);
        used.push_back(false);
    }

    for (int i = 0; i < M; i++){ // заполняем
        int f_top, s_top, rib_w;
        fin >> f_top >> s_top >> rib_w;
        info[f_top - 1].emplace_back(s_top - 1, rib_w);
    }
    fin.close();

    dijkstra(S - 1);

    ofstream  fout("output.txt");
    for (auto i : dist){
        if (i == INT_MAX)
            fout << -1 << " ";
        else
            fout << i << " ";
    }
    fout.close();

    return 0;
}

void dijkstra(int V){
    dist[V] = 0; // к начальной - путь 0
    priority_queue<pair<int, int>> pQueue; // создаем очередь с приоритетом
    pQueue.push(pair<int, int>(0, V)); // в очередь пушим первую пару

    while (!pQueue.empty()){
        int i = pQueue.top().second; // забираем из очереди минимальный
        pQueue.pop(); // удаляем этот элемент
        if (!used[i]){
            for(int k = 0; k < info[i].size(); k++){ // проверяем для каждой вершины связанной с начальным
                if (dist[i] + info[i][k].second < dist[info[i][k].first]){ // если оказалось меньше то меняем на меньший
                    dist[info[i][k].first] = dist[i] + info[i][k].second;
                    pQueue.push(pair<int, int>(-dist[info[i][k].first], info[i][k].first));
                    // и доавляем его в очередь с минусом чтобы куча была на минимум
                }
            }
            used[i] = true;
        }
    }
}