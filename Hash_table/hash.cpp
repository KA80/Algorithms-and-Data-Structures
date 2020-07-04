#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#define PRIME_SIZE 100000

typedef long long int lli;
using namespace std;


class Chain{
private:
    lli key;
    lli value;
    Chain *next;
public:
    Chain(lli key, lli value){
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }


    lli getKey(){
        return key;
    }

    lli getValue() {
        return value;
    }


    void setValue(lli value) {
        this->value = value;
    }

    Chain *getNext() {
        return next;
    }

    void setNext(Chain *next) {
        this->next = next;
    }
};

class Hash{
    Chain *table[PRIME_SIZE];

    static lli HashFunction(lli num){//остаток от деления
        return num % PRIME_SIZE;
    }

public:
    Hash(){
        for(auto & i : table){
            i = nullptr;
        }
    }

    void push(lli num){
        lli hashNumber = HashFunction(num);
        auto *number = new Chain(hashNumber, num);
        Chain *place = table[hashNumber];
        if (place == nullptr){
            table[hashNumber] = number;
            return;
        }
        while(place->getNext() != nullptr){
            place = place->getNext();
        }
        place->setNext(number);
    }

    lli find(lli num){
        lli hashNumber = HashFunction(num);
        Chain *result = table[hashNumber];
        if (!result){
            //cout << "element not found" << endl;
            return 0;
        }
        while(result->getValue() != num){
            if (!result->getNext()){
                //cout << "element not found" << endl;
                return 0;
            }
            result = result->getNext();
        }
        return result->getValue();
    }

    void pop(lli num){
        lli hashNumber = HashFunction(num);
        Chain *result = table[hashNumber];
        if (!result){
            //cout << "element not found" << endl;
            return;
        }
        if (result->getValue() == num){
            table[hashNumber] = result->getNext();
            delete result;
            return;
        }
        while(result->getValue() != num){
            if (!result->getNext()){
                //cout << "element not found" << endl;
                return;
            }
            if (result->getNext()->getValue() == num)
                break;
            result = result->getNext();
        }
        result->setNext(result->getNext()->getNext());
    }

    vector<lli> NumsOfHash(){
        vector<lli> nums;
        for (auto & i : table){
            if (i != nullptr){
                Chain *num = i;
                while(num != nullptr){
                    nums.push_back(num->getValue());
                    num = num->getNext();
                }
            }
        }
        return nums;
    }

};


int main(){
    ifstream fin("input.txt");
    lli tmp;
    Hash hashTable;
    do{
        fin >> tmp;
        if (tmp > 0 and hashTable.find(tmp) == 0)
            hashTable.push(tmp);
        else if (tmp < 0)
            hashTable.pop(-tmp);
    }while(tmp != 0);
    fin.close();
    vector<lli> nums = hashTable.NumsOfHash();
    sort(nums.begin(), nums.end());
    ofstream fout("output.txt");
    for (auto i : nums){
        fout << i << ' ';
    }
    fout.close();
    return 0;
}

