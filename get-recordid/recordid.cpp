#include <bits/stdc++.h>
#include <Windows.h>

using std::string;

int maxPage = 160;
string dir = "G:\\Projects\\My-Codes-on-Luogu\\";
string uid = "78407";


string root = "https://www.luogu.com.cn/record/list?user=";


string record;


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
void Left_Click() {
    mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}
void openBrowser() {

}
void pasteUrl() {
    
}
void Wait() {
	Sleep(700);
}

int main(){

    record = root + uid;

    openBrowser();

    for(int i = 1; i <= maxPage; ++i) {

    }

    return 0;
}
