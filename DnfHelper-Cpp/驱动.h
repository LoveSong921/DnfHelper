#pragma once
#include "����.h"

class Driver
{
public:
	Driver();
	~Driver();

public:
	DWORD dwLastError;   //���Ĵ���
	HANDLE hDriver;      //�������
	SC_HANDLE hSCManager;  //SCM���
	SC_HANDLE hService;    //������

public:

	BOOL LoadDriver(LPCWSTR �����ļ�·��, LPCWSTR ������, LPCWSTR ������ʾ��);

	//example: \\\\.\\xxoo
	BOOL OpenDriver(LPCWSTR pLinkName);

	BOOL UnLoadDriver(LPCWSTR ������);

	// ����ͨѶ
	BOOL IoControl(DWORD dwIoCode, PVOID InBuff, DWORD InBuffLen, PVOID OutBuff, DWORD OutBuffLen, DWORD* RealRetBytes);
};

extern Driver drive;