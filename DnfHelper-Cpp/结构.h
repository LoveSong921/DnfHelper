#pragma once
#include "����.h"

using namespace std;

typedef struct ����
{
	INT x;
	INT y;
	INT z;
}����;

struct ��ͼ����
{
	CHAR* ��ͼ����;
	DWORD ��ͼ���;
	vector<DWORD> ��ͼͨ��;
	���� ��ʼ����;
	���� �յ�����;
	DWORD ��;
	DWORD ��;
	vector<����> ��ͼ�߷�;
	DWORD ����ƣ��;
	DWORD ͨ������;
	ULONG64 ��ʱ����;
};

struct ��Ϸ��ͼ
{
	���� ��ͼ����;
	BOOL ��ͼ���;
	BOOL ��ͼ�ұ�;
	BOOL ��ͼ�ϱ�;
	BOOL ��ͼ�±�;
	DWORD ��ͼͨ��;
	DWORD ������ɫ;
};

struct ��ͼ�ڵ�
{
	DWORD ��ͼF��;
	DWORD ��ͼG��;
	DWORD ��ͼH��;
	���� ��ǰ����;
	���� ��������;
};

struct ȫ���Զ�
{
	DWORD ȫ������;
	DWORD ȫ_����;
	DWORD �������;
	DWORD �����Ѷ�;
	bool ��_�Ѿ���ͼ;
	bool ��_����˳ͼ;
	bool ��_�л���ɫ;
	DWORD ��_ˢͼ��ɫ;
	DWORD ��_�����ɫ;
	DWORD ��_˳ͼ����;
	DWORD ��_˳ͼ�ƴ�;
	DWORD ��_�ʹ�����;
	DWORD ��_�޵׿ӵ�;
	DWORD ��_����֮��;
	DWORD ��_ʹ�������;
	DWORD ��_�������;
};
extern ȫ���Զ� ȫ��_�Զ�;

struct ��������
{
	ULONG64 ����ָ��;
	ULONG64 ��ͼָ��;
	ULONG64 ����ָ��;
	ULONG64 ����Ѫ��;

	ULONG64 �׵�ַ;
	ULONG64 β��ַ;

	int ��������;
	int ��������;
	int ������Ӫ;

	ULONG64 ��Ʒָ��;

	size_t ��������;
	int ��������;
	int ������Ӫ;
	int ���ܸ���;
	int ����Ѫ��;
	wstring ��������;

	wstring ��Ʒ����;

	int ��Ʒ����;
	int ��Ʒ����;
};
