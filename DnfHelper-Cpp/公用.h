// winsdk
#include "Windows.h"
// win����
#include <winsvc.h>
// ����
#include "tlhelp32.h"

// ��ӡ���
#include <iostream>

#include <string>
// �ַ���ת��
#include <codecvt>

// ����
#include <vector>

// �������
#include <cstdlib>

using namespace std;

DWORD GetProcessIdByName(LPCWSTR ����);

vector<byte> �ֽڼ�׷��(vector<byte> oldByteArr, vector<vector<byte>> newByteArrs);

// ����ת�ֽ�����
vector<byte>& IntToByteArr(DWORD64 num, int length);

vector<byte> MakeByteArr(int num);

vector<byte> AnsiToUnicode(string str);

string UnicodeToAnsi(const vector<byte>& vby);

wstring GetDesktopPath();


void д����(wstring ��, wstring ��, wstring ֵ);

DWORD ������(wstring ��, wstring ��);

const wchar_t* format_string(const wchar_t* format, ...);

wstring get_current_time_string();

wstring get_running_time_string();