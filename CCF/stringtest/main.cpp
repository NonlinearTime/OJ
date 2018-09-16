#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "09";
    int t = 9;
    cout << stoi(s, 0 , 10) << endl;
    cout << to_string(9) << endl;
    cout << s.substr(0,s.find("9")) << endl;
    char line[] = "\"esc\\\\aped\": \"\\\"hello\\\"\"";
    for (int i = 0 ; line[i] != '\0' ; ++i) {
//        if (line[i] == '\\') {
//            i++;
//        }
        cout << line[i];
    }
    return 0;
}