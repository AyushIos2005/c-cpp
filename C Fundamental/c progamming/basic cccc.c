#include <windows.h>

// Function Prototypes
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

// Global variables
HWND hEdit1, hEdit2, hResult; // Input and result fields
HWND hAdd, hSub, hMul, hDiv; // Buttons

// WinMain: Entry point for Windows applications
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"CalculatorWindow";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc)) return -1;

    CreateWindowW(L"CalculatorWindow", L"Basic Calculator", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  100, 100, 300, 300, NULL, NULL, NULL, NULL);

    MSG msg = {0};

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// Function to create GUI components
void AddControls(HWND hWnd) {
    CreateWindowW(L"Static", L"Enter Number 1:", WS_VISIBLE | WS_CHILD, 20, 20, 120, 20, hWnd, NULL, NULL, NULL);
    hEdit1 = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 20, 100, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Static", L"Enter Number 2:", WS_VISIBLE | WS_CHILD, 20, 50, 120, 20, hWnd, NULL, NULL, NULL);
    hEdit2 = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 100, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Static", L"Result:", WS_VISIBLE | WS_CHILD, 20, 110, 120, 20, hWnd, NULL, NULL, NULL);
    hResult = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY, 150, 110, 100, 20, hWnd, NULL, NULL, NULL);

    hAdd = CreateWindowW(L"Button", L"+", WS_VISIBLE | WS_CHILD, 20, 80, 50, 25, hWnd, (HMENU)1, NULL, NULL);
    hSub = CreateWindowW(L"Button", L"-", WS_VISIBLE | WS_CHILD, 80, 80, 50, 25, hWnd, (HMENU)2, NULL, NULL);
    hMul = CreateWindowW(L"Button", L"*", WS_VISIBLE | WS_CHILD, 140, 80, 50, 25, hWnd, (HMENU)3, NULL, NULL);
    hDiv = CreateWindowW(L"Button", L"/", WS_VISIBLE | WS_CHILD, 200, 80, 50, 25, hWnd, (HMENU)4, NULL, NULL);
}

// Window Procedure to Handle Events
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    char buffer1[20], buffer2[20], resultStr[50];
    double num1, num2, result;

    switch (msg) {
        case WM_CREATE:
            AddControls(hWnd);
            break;

        case WM_COMMAND:
            GetWindowText(hEdit1, buffer1, 20);
            GetWindowText(hEdit2, buffer2, 20);
            num1 = atof(buffer1);
            num2 = atof(buffer2);

            switch (wp) {
                case 1: result = num1 + num2; break;
                case 2: result = num1 - num2; break;
                case 3: result = num1 * num2; break;
                case 4:
                    if (num2 != 0) result = num1 / num2;
                    else {
                        SetWindowText(hResult, "Error! Div by 0");
                        return 0;
                    }
                    break;
            }

            sprintf(resultStr, "%.2lf", result);
            SetWindowText(hResult, resultStr);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProcW(hWnd, msg, wp, lp);
    }

    return 0;
}

