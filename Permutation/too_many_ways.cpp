#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int gcd(int, int);

int main(){
    int x1, y1, z1, x2, y2, z2;
    ifstream fin("input.txt");
    fin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    fin.close();
    int dx, dy, dz;
    dx = abs(x1 - x2);
    dy = abs(y1 - y2);
    dz = abs(z1 - z2);

    vector<int> fact;
    for (int i = 2; i <= dx + dy +dz; i++)
        fact.push_back(i);

    for (int i = 2; i <= dx; i++){
        int a = i;
        for(int j = 0; j < fact.size(); j++){
            int gcd_res = gcd(a, fact[j]);
            a /= gcd_res;
            fact[j] /= gcd_res;
        }
    }
    for (int i = 2; i <= dy; i++){
        int a = i;
        for(int j = 0; j < fact.size(); j++){
            int gcd_res = gcd(a, fact[j]);
            a /= gcd_res;
            fact[j] /= gcd_res;
        }
    }
    for (int i = 2; i <= dz; i++){
        int a = i;
        for(int j = 0; j < fact.size(); j++){
            int gcd_res = gcd(a, fact[j]);
            a /= gcd_res;
            fact[j] /= gcd_res;
        }
    }
    long long int result = 1;
    for (int i : fact){
        result *= i;
        result %= 1000000007;
    }

    ofstream fout("output.txt");
    fout << result;
    fout.close();
    return 0;
}

int gcd (int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        }
        else b = b % a;
    }
    return a + b;
}