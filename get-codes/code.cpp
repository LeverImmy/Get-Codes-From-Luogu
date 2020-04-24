#include <bits/stdc++.h>
#include <Windows.h>
// #define system puts
using std::string;


const int WIDTH = 4;
string from = ".\\from-clip.bat ";
string into = ".\\into-clip.bat ";
string root_pre = "https://www.luogu.com.cn/record/";
string root_suf = "?_contentOnly=1";

int maxPage, __;
string comp = "..\\data\\codes\\", uid, num;
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
void Backspace() {
	keybd_event(8, 0, 0, 0);
	keybd_event(8, 0, KEYEVENTF_KEYUP, 0);
}
void Ctrl(char ch) {
    keybd_event(17, 0, 0, 0);
    keybd_event(ch - 'A' + 65, 0, 0, 0);
    keybd_event(ch - 'A' + 65, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(17, 0, KEYEVENTF_KEYUP, 0);
}
void Enter() {
	keybd_event(VK_RETURN, 0, 0, 0);
	keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
}
void F6() {
	keybd_event(117, 0, 0, 0);
	keybd_event(117, 0, KEYEVENTF_KEYUP, 0);
}
void leftClick() {
    mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}
void makeDir() {
    string dir = "md " + comp;
    system(dir.c_str());
}
void waitLong() {
    Sleep(2000);
}
void openBrowser() {

    waitLong();
}
void pasteRecord() {
    string dir = from + comp + num + ".cpp";
    system(dir.c_str());
}
void pasteUrl() {
    string dir = into + "\"" + root_pre + uid + root_suf + num + "\"";
    system(dir.c_str());
    Ctrl('V');
}
void waitDefault() {
	Sleep(2000);
}




int main(){

    freopen("../data/rids.txt", "r", stdin);
    while(std::cin >> __) rids.push_back(__);

    openBrowser();

    for(int i = 0; i < (int)rids.size(); ++i) {
        num = itos(rids[i]);
        pasteUrl(), waitDefault();
        Enter(), waitDefault();
        leftClick(), waitDefault();
        Ctrl('A'), waitDefault();
        Ctrl('C'), waitDefault();
        pasteRecord(), waitDefault();

        F6(), waitDefault();
        Ctrl('A'), waitDefault();
        Backspace(), waitDefault();
    }

    return 0;
}
