#include <bits/stdc++.h>
#include <Windows.h>
// #define system puts
using std::string;


const int WIDTH = 4;
string comp = "../data/rids/";

int maxPage;
string uid, num;
std::vector <int> rids;


string itos(int _num) {
    std::stack<int> stk;
    while(!stk.empty()) stk.pop();
    while(_num) {
        stk.push(_num % 10);
        _num /= 10;
    }
    while(stk.size() < WIDTH)
        stk.push(0);

    string _res = "";
    while(!stk.empty()) {
        _res.push_back(stk.top() + '0');
        stk.pop();
    }
    return _res;
}
void selectFolder() {
    string dir = comp + num + ".txt";
    freopen(dir.c_str(), "r", stdin);
}
void solve() {
    string s;
    std::getline(std::cin, s);
    int len = s.length();
    for(int i = 0; i + 5 < len; ++i) {
        int nowid = 0;
        if(s[i] == 's' && s[i + 1] == 't' && s[i + 2] == 'a' && s[i + 3] == 't' && s[i + 4] == 'u' && s[i + 5] == 's') {
            std::stack <char> stk;
            for(int j = i - 3; s[j] != ':'; --j)
                stk.push(s[j]);
            while(!stk.empty()) {
                nowid = nowid * 10 + stk.top() - '0';
                stk.pop();
            }
            rids.push_back(nowid);
        } // get runid
    }
}
void intoFile() {
    freopen("../data/rid.txt", "w", stdout);
    for(int i = 0; i < (int)rids.size(); ++i) printf("%d\n", rids[i]);
}


int main(){

    freopen("../data/info.txt", "r", stdin);
    std::cin >> uid >> maxPage;

    for(int i = 1; i <= maxPage; ++i) {
        num = itos(i);
        selectFolder();
        solve();
    }
    intoFile();

    return 0;
}
