// Copyright (c) 2016 Damien Dart, <http://www.robotinaponcho.net/>.
// This file is distributed under the MIT licence. For more information,
// please refer to the accompanying "LICENCE" file.


#define WIN32_LEAN_AND_MEAN
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif

#include <windows.h>
#include <magnification.h>


LRESULT CALLBACK HostWndProc(HWND hWnd, UINT message, WPARAM wParam,
    LPARAM lParam)
{
  switch (message) {
    LRESULT cursorPosition;
    RECT hostClientRect;

    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    case WM_NCHITTEST:
      cursorPosition = DefWindowProc(hWnd, message, wParam, lParam);
      return (cursorPosition == HTCLIENT ? HTCAPTION : cursorPosition);
    case WM_SIZE:
      GetClientRect(hWnd, &hostClientRect);
      SetWindowPos(GetWindow(hWnd, GW_CHILD), NULL, hostClientRect.left,
          hostClientRect.top, hostClientRect.right, hostClientRect.bottom, 0);
      break;
    default:
      return DefWindowProc(hWnd, message, wParam, lParam);
  }
  return 0;
}


void CALLBACK UpdateMagnificationWindow(HWND hWnd, UINT uMsg,
    UINT_PTR idEvent, DWORD dwTime)
{
  MAGTRANSFORM magnifierTranformationMatrix;
  RECT hostWindowRect, magnificationSourceRect;

  GetWindowRect(GetParent(hWnd), &hostWindowRect);
  magnificationSourceRect = { hostWindowRect.left +
      GetSystemMetrics(SM_CYFRAME), hostWindowRect.top +
      GetSystemMetrics(SM_CYCAPTION) + (GetSystemMetrics(SM_CYFRAME) * 2),
      hostWindowRect.right - GetSystemMetrics(SM_CYFRAME),
      hostWindowRect.bottom - GetSystemMetrics(SM_CXFRAME)};
  magnifierTranformationMatrix = {-1.0f, 0,
      (float)(magnificationSourceRect.right - magnificationSourceRect.left),
      0, 1.0f, 0, 0, 0, 1.0f};
  MagSetWindowTransform(hWnd, &magnifierTranformationMatrix);
  MagSetWindowSource(hWnd, magnificationSourceRect);
  InvalidateRect(hWnd, NULL, TRUE);
}


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
  HWND hwndHost, hwndMagnifier;
  MSG msg;
  UINT_PTR timerId;

  if (MagInitialize()) {
    WNDCLASSEX wcex = {};

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hInstance = hInstance;
    wcex.lpfnWndProc = HostWndProc;
    wcex.lpszClassName = TEXT("FlippyWindowWindow");
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClassEx(&wcex);
    hwndHost = CreateWindowEx(WS_EX_TOPMOST | WS_EX_LAYERED,
        TEXT("FlippyWindowWindow"), TEXT("FlippyWindow"), WS_CLIPCHILDREN |
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, GetSystemMetrics(
        SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) / 2, NULL, NULL,
        hInstance, NULL);
    if (hwndHost) {
      RECT hostClientRect;

      SetLayeredWindowAttributes(hwndHost, 0, 255, LWA_ALPHA);
      GetClientRect(hwndHost, &hostClientRect);
      hwndMagnifier = CreateWindow(WC_MAGNIFIER, TEXT("MagnifierWindow"),
        MS_SHOWMAGNIFIEDCURSOR | WS_CHILD | WS_VISIBLE, hostClientRect.left,
        hostClientRect.top, hostClientRect.right, hostClientRect.bottom,
        hwndHost, NULL, hInstance, NULL);
      if (!hwndMagnifier) {
        return 0;
      }
    } else {
      return 0;
    }
  } else {
    return 0;
  }
  ShowWindow(hwndHost, nCmdShow);
  UpdateWindow(hwndHost);
  // Update the magnification window 60 times a second.
  timerId = SetTimer(hwndMagnifier, 0, 16, UpdateMagnificationWindow);
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  KillTimer(NULL, timerId);
  MagUninitialize();
  return msg.wParam;
}
