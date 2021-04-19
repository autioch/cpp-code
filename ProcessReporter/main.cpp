/* 
 * File:   main.cpp
 * Author: Jakub
 *
 * Created on 23 listopad 2011, 19:20
 */

#define _WIN32_WINNT 0x0500
#include <cstdlib>
#include <fstream>
#include <dos.h>
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <iostream>
#include <sstream>
#include <string>
#pragma comment(linker, "/SUBSYSTEM:WINDOWS")

using namespace std;

string GetProcessList( ){
    int count = 0;
HANDLE hProcessSnap;
PROCESSENTRY32 pe32;
hProcessSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
if( hProcessSnap == INVALID_HANDLE_VALUE ){
        return "";
}
pe32.dwSize = sizeof( PROCESSENTRY32 );
if( !Process32First( hProcessSnap, &pe32 ) ){
        CloseHandle( hProcessSnap ); 
        return "";
}
std::stringstream ss;
do {
    ss << "\n" << pe32.szExeFile << "\t\t" << pe32.th32ProcessID << "\t" << pe32.cntThreads << "\t" << pe32.th32ParentProcessID;
    count++;
} while( Process32Next( hProcessSnap, &pe32 ) );
CloseHandle( hProcessSnap );
ss << "\n" << count << "\n";
return ss.str();
}

string getTime(){
SYSTEMTIME st;
GetLocalTime(&st);
std::stringstream ss;
ss << st.wHour << ":" << st.wMinute << ":" << st.wSecond;;
return ss.str();
}

void writeFile(string str, const char *file){
ofstream myfile;
myfile.open(file,ios::out);
myfile << str << endl;
myfile.close(); 
}

int main( void ){
HWND hWnd = GetConsoleWindow();
ShowWindow( hWnd, SW_HIDE );
std::stringstream ss;
int i=0;
char *files[] = {"report0.txt", "report1.txt", "report2.txt", "report3.txt", "report4.txt"};
while (true){
    ss.str("");
    ss << getTime() << endl << GetProcessList( );
    i++;
    i=i%5;
    //cout << getTime() + GetProcessList( );
    writeFile(ss.str(),files[i]);
    Sleep(10000);    
}
return 0;
}
