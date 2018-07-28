#include <iostream>
#include <map>


using namespace std;

int main() {
    int max_N;//input interval num
    double  s,f;
    map<double ,double > intervalSet;
    while(cin>>max_N) {
        for (int i = 0; i != max_N; i++) {  //input the instances, use a map to store;
            cin >> s >> f;
            intervalSet.insert({f, s});     //the is sorted;
        }

        double rec = 0;
        int count = 0;
        cout << "the result is : ";
        for (auto item = intervalSet.begin(); item != intervalSet.end(); item++) {
            if (rec <= item->second) {      //if no overlap
                count++;
                cout << "(" << item->second << "," << item->first << ") ";
                rec = item->first;
            }
        }
        cout << "#" << count << endl;
    }
    return 0;
}