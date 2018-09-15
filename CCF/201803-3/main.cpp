#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct regulation {
    string name;
    vector<string> regv;
    regulation(string a, vector<string> v): name(a), regv(v) {}
};

vector<regulation> regulations;

vector<string> str2regv(string str) {
    vector<string> res;
    str = str.substr(1, str.size() - 1);
    res.push_back("/");
    size_t pos = str.find("/");
    while (pos != string::npos) {
        res.push_back(str.substr(0, pos));
        res.push_back("/");
        str = str.substr(pos + 1);
        pos = str.find("/");
    }
    if (str.size()) res.push_back(str);
    return res;
}

void urlmap(string str) {
    vector<string> v = str2regv(str);
    for (int i = 0 ; i < regulations.size() ; ++i) {
        vector<string> &r = regulations[i].regv;
        string res = regulations[i].name;
        size_t lv = v.size(), lr = r.size();
        size_t j = 0, k = 0;
        while (j < lv && k < lr) {
            if (v[j] == r[k]) {
                j++, k++;
                continue;
            }
            if (r[k] == "<path>") {
                if (v[lv - 1] == "/") break;
                res += " ";
                while (j < lv) {
                    res += v[j++];
                }
                cout << res << endl;
                return;
            } else if (r[k] == "<int>") {
                string num = v[j];
                bool is_num = true;
                for (int l = 0 ; l < num.size() ; ++l) {
                    if (!isdigit(num[i])) {
                        is_num = false;
                        break;
                    }
                }
                if (!is_num) break;
                int l ;
                for (l = 0; l < num.size() ; ++l) {
                    if (num[l] != '0') break;
                }
                res += " " + num.substr(l, num.size() - l);
            } else if (r[k] == "<str>")
                res += " " + v[j];
            else break;
            j++, k++;
        }
        if (j == lv && k == lr) {
            cout << res << endl;
            return;
        }
    }
    cout << "404" << endl;
}

int main() {
    int n, m;
    string regl, name;
    cin >> n >> m;
    while (n--) {
        cin >> regl >> name;
        regulations.push_back(regulation(name, str2regv(regl)));
    }
    while (m--) {
        cin >> regl;
        urlmap(regl);
    }
    return 0;
}