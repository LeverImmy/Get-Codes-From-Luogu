#include <bits/stdc++.h>
#include <Windows.h>
// #define system puts
using std::string;


const int WIDTH = 4;
int maxPage = 5;
string comp = "G:\\Projects\\My-Codes-on-Luogu\\";
string from = ".\\from-clip.bat ";
string into = ".\\into-clip.bat ";
string uid = "78407";

string root_pre = "https://www.luogu.com.cn/record/list?user=";
string root_suf = "&_contentOnly=1&page=";

string num;



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
    string dir = from + comp + num + ".txt";
    system(dir.c_str());
}
void pasteUrl() {
    string dir = into + "\"" + root_pre + uid + root_suf + num + "\"";
    system(dir.c_str());
    Ctrl('V');
}
void waitDefault() {
	Sleep(700);
}




int main(){

    makeDir();
    openBrowser();

    for(int i = 1; i <= maxPage; ++i) {
        num = itos(i);
        F6();
        pasteUrl(), waitDefault();
        Enter(), waitDefault();
        leftClick();
        Ctrl('A'), waitDefault();
        Ctrl('C'), waitDefault();
        pasteRecord();

        F6();
        Ctrl('A'), waitDefault();
        Backspace(), waitDefault();
    }

    return 0;
}
