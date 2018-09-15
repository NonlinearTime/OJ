#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    bool is_li = false;
    bool is_pa = false;
    freopen("3.txt","r",stdin);
    while (getline(cin, line)) {
        if (line.empty()) {
            if (is_pa) {
                is_pa = false;
                cout << "</p>" << endl;
            }
            continue;
        }
        if (line[0] != '*') {
            if (is_li) cout << "</ul>" << endl;
            is_li = false;
        }
        size_t pos = line.find("_");
        while(pos != string::npos) {
            line.replace(pos, 1, "<em>");
            pos = line.find("_");
            line.replace(pos, 1, "</em>");
            pos = line.find("_");
        }
        pos = line.find("[");
        while (pos != string::npos) {
            size_t nxp = line.find("]", pos);
            size_t lp = line.find("(", nxp);
            size_t rp = line.find(")", lp);
            string t = line.substr(pos + 1, nxp - pos - 1);
            string k = line.substr(lp + 1, rp - lp - 1);
            line.replace(pos, rp - pos, "<a href=\"" + k + "\">" + t + "</a>");
            pos = line.find("[", rp);
        }
        if (line[0] == '#') {
            int hn = 0;
            while (line[hn] == '#') hn++;
            line = line.substr(hn + 1);
            line = "<h" + string(1, hn + '0') + ">" + line + "</h" + string(1, hn + '0') + ">\n";
        } else if (line[0] == '*') {
            if (!is_li) cout << "<ul>" << endl;
            is_li = true;
            line = line.substr(2);
            line.insert(0, "<li>");
            line += "</li>\n";
        } else {
            if (!is_pa) {
                line = "<p>" + line;
                is_pa = true;
            } else line = "\n" + line;
        }
        cout << line;
    }
    if (is_pa) cout << "</p>" << endl;
    return 0;
}