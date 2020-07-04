#include <iostream>
#define MAX_N 10
using namespace std;

bool used[MAX_N];
int current_perm[MAX_N];

void permutations(int, int);

int main(){
    int n;
    cin >> n;
    permutations(n, 0);
    return 0;
}

void permutations(int n, int k){
    if(n == k){
        for (int i = 0; i < n; i++)
            cout << current_perm[i] << " ";
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            used[i] = true;
            current_perm[k] = i;
            permutations(n, k + 1);
            used[i] = false;
        }
    }
}