#include <bits/stdc++.h>
#include <Windows.h>
using std::string;

const int WIDTH = 4;

string comp = "..\\data\\tmpscrs\\";
string to = "..\\data\\codes\\";

int __;
string num;
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
void makeDir(string add) {
    string dir = "md " + add;
    system(dir.c_str());
}
void openFolder() {
    string dir = comp + num + ".txt";
    freopen(dir.c_str(), "r", stdin);


    string tmp;
    std::getline(std::cin, tmp);

    string out = to, out1, out2;
    for(int i = 0, flag = 0; i < (int)tmp.size(); ++i) {
        if(tmp[i - 6] == 'p' && tmp[i - 5] == 'i' && tmp[i - 4] == 'd')
            flag = 1;
        if(tmp[i] == '\"' && tmp[i + 1] == ',')
            flag = 0;
        if(flag) out.push_back(tmp[i]);
    }

    makeDir(out);
    out1 = out + "\\" + num + "_raw.cpp";


    freopen(out1.c_str(), "w", stdout);
    puts("#include <bits/stdc++.h>");
    printf("int main(){printf(\"");
    for(int i = 0, flag = 0; i < (int)tmp.size(); ++i) {
        if(i >= 13 && tmp[i - 13] == 's' && tmp[i - 12] == 'o' && tmp[i - 11] == 'u' && tmp[i - 10] == 'r' && tmp[i - 9] == 'c' && tmp[i - 8] == 'e' && tmp[i - 7] == 'C' && tmp[i - 6] == 'o' && tmp[i - 5] == 'd' && tmp[i - 4] == 'e' && tmp[i - 3] == '\"')
            flag = 1;
        if(i + 8 < (int)tmp.size() && tmp[i + 1] == ',' && tmp[i + 2] == '\"' && tmp[i + 3] == 't' && tmp[i + 4] == 'i' && tmp[i + 5] == 'm' && tmp[i + 6] == 'e' && tmp[i + 7] == '\"' && tmp[i + 8] == ':')
            flag = 0;
        if(flag) putchar(tmp[i]);
        if(tmp[i] == '%') printf("%%");
    }
    printf("\");return 0;}");

    out1 = "g++ " + out1 + " -o " + "rrr.exe";

    // freopen("CON", "w", stdout);
    // std::cout << out1 << '\n';

    system(out1.c_str());

    out2 = "rrr.exe> " + out + "\\" + num + ".cpp";

    // freopen("CON", "w", stdout);
    // std::cout << out2 << '\n';

    system(out2.c_str());
}

int main() {

    // freopen("../data/rid.txt", "r", stdin);
    //
    // while(std::cin >> __) rids.push_back(__);

    rids.push_back(33017148);

    makeDir(to);

    for(int i = 0; i < (int)rids.size(); ++i) {
        num = itos(rids[i]);
        openFolder();
    }
    return 0;
}
