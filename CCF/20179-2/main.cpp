#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define MAX_SIZE 11000

vector<int> rent_stamp[MAX_SIZE];
vector<int> ret_stamp[MAX_SIZE];

bool compare(int a, int b) {
    return a > b ? true : false;
}

int find_pos(int * keys, int index, int size) {
    for (int i = 0 ; i < size ; ++i) {
        if (keys[i] == index) return i;
    }
    return -1;
}

int main() {
    int N,K;
    int w,s,c;
    int tmp;
    for (int i = 0 ; i < MAX_SIZE ; ++i) rent_stamp[i].clear(),ret_stamp[i].clear();
    cin >> N >> K;
    vector<int> pos;
    pos.clear();
    int keys[N+1];
    for (int i = 0 ; i < N + 1 ; ++i) keys[i] = i;
    for (int i = 0 ; i < K ; ++i) {
        cin >> w >> s >> c;
        rent_stamp[s].push_back(w);
        ret_stamp[s+c].push_back(w);
    }
    for (int i = 1 ; i < MAX_SIZE ; ++i) {
        sort(ret_stamp[i].begin(),ret_stamp[i].end());
        for (vector<int>::iterator it = ret_stamp[i].begin(); it != ret_stamp[i].end() ; ++it) {
            tmp = pos.back();
            pos.pop_back();
            keys[tmp] = *it;
        }
        for (vector<int>::iterator it = rent_stamp[i].begin() ; it != rent_stamp[i].end(); ++it) {
            tmp = find_pos(keys,*it,N+1);
            pos.push_back(tmp);
            keys[tmp] = 0;
        }
        sort(pos.begin(),pos.end(),compare);
    }
    for (int i = 1 ; i < N ; ++i) cout << keys[i] << " ";
    cout << keys[N] << endl;
    return 0;
}