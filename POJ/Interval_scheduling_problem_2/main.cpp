#include <iostream>
#include <map>

using namespace std;

int main() {
    double s,f,w;
    int max_N;
    double dp[max_N];// use a array to store temple result - foreach i , dp[i] is the best solution of the sub-problem[1,i]
    map<double,pair<double ,double >> intervalSet; //use a map to store the intervals
    while (cin >> max_N) {
        intervalSet.clear();
        for (int i = 0 ; i != max_N ; i++) {
            cin >> s >> f >> w;
            intervalSet.insert({f,make_pair(s,w)});
        }
        dp[0] = intervalSet.begin()->second.second; //initial dp[0]
        int index = 1;
        for (auto item = ++intervalSet.begin(); item != intervalSet.end() ; ++item) { //compute from the 2nd
            double  max;
            auto tmp = intervalSet.lower_bound(item->second.first);
            //cout <<item->second.first <<" " << item->first << " " << tmp->first<<" " << tmp->second.first<<" " <<tmp->second.second<< " " << index<< "\n";
            if (tmp != intervalSet.end()) {
                int i = 0;
                for (auto x = intervalSet.begin() ; x != tmp ; x++) i++;
                max = dp[i] + item->second.second;
            } else {
                max = item->second.second;
            }
            dp[index] = max > dp[index-1]?max:dp[index-1];
            //cout << dp[index] << "\n";
            index++;
        }
    }
}