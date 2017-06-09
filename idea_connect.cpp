#include<bits/stdc++.h>
#define _WIN32_WINNT 0x0500
#include<windows.h>
#include <sys/types.h>
#include <unistd.h>
#include<dos.h>
using namespace std;
void MouseMove (int x, int y )
{
	double fScreenWidth    = ::GetSystemMetrics( SM_CXSCREEN )-1;
	double fScreenHeight  = ::GetSystemMetrics( SM_CYSCREEN )-1;
	double fx = x*(65535.0f/fScreenWidth);
	double fy = y*(65535.0f/fScreenHeight);
	INPUT  Input={0};
	Input.type      = INPUT_MOUSE;
	Input.mi.dwFlags  = MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE;
	Input.mi.dx = fx;
	Input.mi.dy = fy;
	::SendInput(1,&Input,sizeof(INPUT));
}
void LeftClick ( )
{
  INPUT    Input={0};
  // left down
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
  ::SendInput(1,&Input,sizeof(INPUT));

  // left up
  ::ZeroMemory(&Input,sizeof(INPUT));
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
  ::SendInput(1,&Input,sizeof(INPUT));
}
int main()
{
    while(1)
    {
        system("ping www.google.com > hunter.txt");
        freopen("hunter.txt","r",stdin);
        int c=0;
        string s;
        while(getline(cin,s))
        {
            c++;
        }
        if(c>7)
        {
            cout<<"connected ";
            //connected
        }
        else
        {
            //disconnected
            cout<<"disconnected ";
            system("cd C:\\Program Files (x86)\\Idea Net Setter & \"Idea Net Setter.exe\"");
            //simulate click here

            //modem coordinates x=1241 y=218
            MouseMove(1241,218);
            LeftClick();

            Sleep(15000);
            //idm icon coordinates 206,751
            MouseMove(206,751);
            LeftClick();

            Sleep(3000);
            //idm multitab coordinates 342,645
            MouseMove(342,645);
            LeftClick();

            Sleep(2000);
            //idm coordinates x=630 y=427
            //system("cd C:\\Users\\Admin\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Internet Download Manager & \"Internet Download Manager.lnk\"");
            //system("cd "C:\\Program Files (x86)\\Internet Download Manager\\IDMan.exe"")
            MouseMove(630,427);
            LeftClick();
        }
        Sleep(60000);
    }
    return 0;
}
