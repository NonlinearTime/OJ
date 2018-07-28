#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <ext/hash_map>
#include <ext/hash_set>
#include <unordered_map>
#include <vector>
#include <map>


using namespace std;

//hash_map<string, bool > rec_hash;
unordered_map<string, bool> rec_map;
string text;


int main() {
    size_t T, N, NC;
    string kw;
    size_t cnt = 0;
    cin >> T;
    while (T--) {
        cin >> N >> NC;
        cin >> text;
        cnt = 0;
        for (size_t i = 0 ; i < text.size() - N + 1; ++i ) {
            kw = text.substr(i, N);
            if (rec_map.find(kw) == rec_map.end()) {
                rec_map[kw] = true;
                cnt++;
            }
//            if (rec_hash.find(kw)->second) break;
//            rec_hash[kw] = true;
//            cnt++;
        }
        cout << cnt << endl;
        if (T) printf("\n");
    }
    return 0;
}