#include "winapiwindowbuilder.h"

LPWSTR tow(const std::string &s)
{
    LPWSTR ws = new wchar_t[s.size()+1];
    copy( s.begin(), s.end(), ws );
    ws[s.size()] = 0;
    return ws;
}

WinApiWindowBuilder::WinApiWindowBuilder(std::string className)
{
    _className = className;
}

WinApiWindowBuilder &WinApiWindowBuilder::geometry(int x, int y, int width, int height)
{
    _x = x;
    _y = y;
    _width = width;
    _height = height;
    return *this;
}

WinApiWindowBuilder &WinApiWindowBuilder::className(std::string className)
{
    _className = className;
    return *this;
}

WinApiWindowBuilder &WinApiWindowBuilder::title(std::string title)
{
    _title = title;
    return *this;
}

WinApiWindowBuilder &WinApiWindowBuilder::parent(HWND parent = HWND_DESKTOP)
{
    _parent = parent;
    return *this;
}

WinApiWindowBuilder &WinApiWindowBuilder::style(DWORD style)
{
    _style = style;
    return *this;
}

WinApiWindowBuilder &WinApiWindowBuilder::menu(HMENU menu)
{
    _menu = menu;
    return *this;
}

WinApiWindowBuilder &WinApiWindowBuilder::param(LPVOID param)
{
    _param = param;
    return *this;
}

WinApiWindowBuilder &WinApiWindowBuilder::hinstance(HINSTANCE hinstance)
{
    _hinstance = hinstance;
    return *this;
}

HWND WinApiWindowBuilder::build()
{
    return
    CreateWindow(
        tow(_className),
        tow(_title),
        _style,
        _x, _y, _width, _height,
        _parent,
        _menu,
        _hinstance,
        _param
    );
}

