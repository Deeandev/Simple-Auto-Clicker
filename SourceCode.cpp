#include <iostream>
#include <Windows.h>

using namespace std;

bool bState(false);
bool shiftPressed(false);
bool windowVisible(true);

void menu(bool bState)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    system("mode con: cols=84 lines=19");
    SetConsoleTitleA("BluePhanter");
    SetConsoleTextAttribute(colors, 9);

       cout << "                           " << '\n';                
    cout << "                  .--.            .--          " << '\n';
    cout << "                 ( (`\\." "--``--" ".//`)   )             " << '\n';
    cout << "                  '-.   __   __    .-        [ F2 ] On/Off " << '\n';
    cout << "                   /   /__\\ /__\\   \\          " << '\n';
    cout << "                  |    \\ 0/ \\ 0/    |        [ Shift ] Hide window   " << '\n';
    cout << "                  \\     `/   \\`     /          " << '\n';
   cout << "                   `-.  /-\"/\"/\"-\\ .-`        [ Mouse5 ] Left Click  " << '\n';
    cout << "                     /  '.___.'  \\          " << '\n';
    cout << "                     \\     I     /           [ Mouse4 ] Rigth Click" << '\n';
    cout << "                      `;--'`'--;`          " << '\n';
    cout << "                        '.___.'              [ F12 ] Self Destruck  " << '\n';

       cout << "                           " << '\n';    
    cout << "                                             " << '\n';
    if (bState)
    {
        cout << "" << '\n';
        cout << "" << '\n';
    SetConsoleTextAttribute(colors, 1);


        cout << "                      Status: ON\n";
    }
    else
    {
        cout << "" << '\n';
        cout << "" << '\n';
    SetConsoleTextAttribute(colors, 1);
        cout << "                      Status: OFF\n";
    }
    SetConsoleTextAttribute(colors, 15);
    cout << "" << '\n';
    cout << "" << '\n';
    SetConsoleTextAttribute(colors, 2);
    SetConsoleTextAttribute(colors, 12);
    SetConsoleTextAttribute(colors, 15);
}

int main()
{
    menu(bState);
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_SHOW);
    while (true)
    {
        if (GetAsyncKeyState(VK_F2) & 1)
        {
            bState = !bState;
            menu(bState);
        }

        if (GetAsyncKeyState(VK_SHIFT) & 1)
        {
            shiftPressed = !shiftPressed;
            windowVisible = !windowVisible;
            ShowWindow(hWnd, windowVisible ? SW_SHOW : SW_HIDE);
        }

        if (bState && !shiftPressed)
        {
            if (GetAsyncKeyState(VK_XBUTTON2))  // mouse5
            {
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0); //left mouse down
                Sleep(15 + (rand() % 10)); //delay
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); //left mouse up
                Sleep(15 + (rand() % 10)); //delay
            }
        }

        if (GetAsyncKeyState(VK_F12))
        {
            TCHAR szFilePath[_MAX_PATH];

            // Get current executable path
            GetModuleFileName(NULL, szFilePath, _MAX_PATH);

            // Delete specified file
            DeleteFile(szFilePath);
            return 0;
        }

        if (GetAsyncKeyState(VK_XBUTTON1)) { // mouse4
            mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0); //right mouse down
            Sleep(15 + (rand() % 10)); //delay
            mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0); //right mouse up
            Sleep(15 + (rand() % 10)); //delay
        }
        Sleep(10);
    }
    return 0;
}
