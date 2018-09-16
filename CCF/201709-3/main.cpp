#include <bits/stdc++.h>

using namespace std;

struct object {
    string name, value;
    bool is_object;
    vector<object> elements;
    object() {}
    object(string name, bool is_object, vector<object> elements)
    : name(name), is_object(is_object), elements(elements) {}
};

object get_object(string name) {
    object ret;
    ret.name = name;
    ret.is_object = true;
    string line;
    while (getline(cin , line)) {
        string tmp = "";
        for (int i = 0 ; i < line.size() ; ++i) {
            if (line[i] == '\\') i++;
            tmp += line[i];
        }
        line = tmp;
        if (line[0] == '}') return ret;
        if (line == "{") continue;
        if (line[line.size() - 1] != '{') {
            size_t p = line.find(":", 0);
            string key = line.substr(1, p-2);
            string val = line[line.size() - 1] == ',' ? line.substr(p + 3, line.size() - p - 5) :line.substr(p + 3, line.size() - p - 4);
            object o;
            o.name = key;
            o.is_object = false;
            o.value = val;
            ret.elements.push_back(o);
        } else {
            size_t p = line.find(":", 0);
            string key = line.substr(1, p-2);
            object o = get_object(key);
            ret.elements.push_back(o);
        }

    }
    return ret;
}

queue<string> str2que(string str) {
    size_t pos = str.find(".");
    queue<string> res;

    while (pos != string::npos) {
        string k = str.substr(0, pos);
        res.push(k);
        str = str.substr(pos + 1);
        pos = str.find(".");
    }
    res.push(str);
    return res;
}

void find(queue<string> &q, object o) {
    string s = q.front();
    q.pop();
    object obj;
    vector<object> ele = o.elements;
    int i;
    for (i = 0 ; i < ele.size() ; ++i) {
        if (s == ele[i].name) {
            obj = ele[i];
            break;
        }
    }
    if (i == ele.size()) {
        cout << "NOTEXIST" << endl;
        return;
    }
    if (q.empty()) {
        if (obj.is_object) {
            cout << "OBJECT" << endl;
        } else {
            cout << "STRING " << obj.value << endl;
        }
        return;
    }
    find(q, obj);
}

int main() {
    vector<object> res;
    int n, m;
    cin >> n >> m;
    cin.get();
    object root = get_object("root");


    string instr;
    while (m--) {
        cin >> instr;
        queue<string> r = str2que(instr);
        find(r, root);
    }
    return 0;
}