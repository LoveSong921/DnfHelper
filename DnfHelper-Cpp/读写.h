#pragma once
#include "����.h"
#include <vector>

VOID SetProcessId(DWORD id);

LPVOID �����ڴ�64(DWORD ���볤��);

BOOL ���ֽڼ�(DWORD64 ��ַ, PVOID ����ֵ, INT32 д�볤��);
BOOL д�ֽڼ�(DWORD64 ��ַ, PVOID д��ֵ, INT32 д�볤��);

DWORD ��������(DWORD64 ��ַ);
BOOL д������(DWORD64 ��ַ, DWORD ����);

DWORD64 ����������(DWORD64 ��ַ);
BOOL д��������(DWORD64 ��ַ, DWORD64 ����);

vector<BYTE> ���ֽ�����(DWORD64 ��ַ, INT32 ����);

BOOL д�ֽ�����(DWORD64 ��ַ, vector<byte> ֵ);