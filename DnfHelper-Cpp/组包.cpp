#include "���.h"
#include "��д.h"
#include "Call.h"
#include "����.h"
#include "��ַ.h"

static vector<BYTE> packData;


VOID ����Call(_int64 �������)
{
	packData = �ֽڼ�׷��(packData, { { 72, 129, 236, 0, 1, 0, 0 } });
	packData = �ֽڼ�׷��(packData, { { 72, 185 }, IntToByteArr(������ַ,8) });
	packData = �ֽڼ�׷��(packData, { { 186 }, IntToByteArr(�������,8) });
	packData = �ֽڼ�׷��(packData, { {72, 184 }, IntToByteArr(����CALL,8) });
	packData = �ֽڼ�׷��(packData, { { 255, 208 } });
	packData = �ֽڼ�׷��(packData, { {72, 129, 196, 0, 1, 0, 0 } });
}
VOID ����Call(__int64 ���ܲ���, int  ���ܳ���)
{
	packData = �ֽڼ�׷��(packData, { { 72, 129, 236, 0, 1, 0, 0 } });
	packData = �ֽڼ�׷��(packData, { { 72, 185 }, IntToByteArr(������ַ,8) });
	packData = �ֽڼ�׷��(packData, { {72, 186 }, IntToByteArr(���ܲ���,8) });
	switch (���ܳ���)
	{
	case 1:
		packData = �ֽڼ�׷��(packData, { { 72, 184 }, IntToByteArr(���ܰ�CALL,8) });
		break;
	case 2:
		packData = �ֽڼ�׷��(packData, { { 72, 184 }, IntToByteArr(���ܰ�CALL2,8) });
		break;
	case 4:
		packData = �ֽڼ�׷��(packData, { {72, 184 }, IntToByteArr(���ܰ�CALL4,8) });
		break;
	case 8:
		packData = �ֽڼ�׷��(packData, { {72, 184 }, IntToByteArr(���ܰ�CALL8,8) });
		break;
	}
	packData = �ֽڼ�׷��(packData, { { 255, 208 } });
	packData = �ֽڼ�׷��(packData, { { 72, 129, 196, 0, 1, 0, 0 } });
}


VOID ����Call()
{
	packData = �ֽڼ�׷��(packData, { { 72, 129, 236, 0, 1, 0, 0 } });
	packData = �ֽڼ�׷��(packData, { {72, 184 }, IntToByteArr(����CALL,8) });
	packData = �ֽڼ�׷��(packData, { { 255, 208 } });
	packData = �ֽڼ�׷��(packData, { {72, 129, 196, 0, 1, 0, 0 } });
	���ִ��(packData);
	packData.clear();
}


VOID �ύ����(int id)
{
	����Call(34);
	����Call(34, 2);
	����Call(id, 2);
	����Call(-1, 2);
	����Call(1, 2);
	����Call(-1, 2);
	����Call();
}
VOID ��ȡ����(int id)
{
	����Call(31);
	����Call(31, 2);
	����Call(id, 2);
	����Call();
}
VOID ��������(int id)
{
	����Call(32);
	����Call(32, 2);
	����Call(id, 2);
	����Call();

}
VOID �������(int id, int type)
{
	type = 1;
	����Call(33);
	����Call(33, 2);
	����Call(id, 2);
	if (type == 1) {
		����Call(16, 1);
	}
	if (type == 2) {
		����Call(32, 1);
	}
	if (type == 3) {
		����Call(64, 1);
	}
	����Call(0, 1);
	����Call(0, 1);
	����Call();

}
VOID ���_����(int ��ȡ��λ��, int װ��λ��)
{
	����Call(408);
	����Call(2, 1);
	����Call(��ȡ��λ��, 2);
	����Call(0, 1);
	����Call(װ��λ��, 2);
	����Call();
}
void �������()
{
	����Call(20);
	����Call(6, 4);
	����Call(16, 1);
	����Call(0, 1);
	����Call(24, 1);
	����Call(1, 1);
	����Call(32, 1);
	����Call(0, 1);
	����Call();
}
VOID �������()
{
	����Call(1449);
	����Call();
}


// λ�� 0��ɫ1 λ��1��
// λ�� 0��ɫ1 λ��1��ɫ2
VOID ���ѡ���ɫ(int λ��)
{
	if (λ�� < 0) {
		return;
	}
	����Call(4);
	����Call(λ��, 2);
	����Call();
}

VOID ����ֽ�(int װ��λ��)
{
	if (װ��λ�� < 0)
	{
		return;
	}
	����Call(26);
	����Call(0, 1);
	����Call(65535, 2);
	����Call(317, 4);
	����Call(1, 1);
	����Call(װ��λ��, 2);
	����Call();
}

VOID ���_����(int װ��λ��)
{
	����Call(22);
	����Call(317, 4);
	����Call(95, 4);
	����Call(1, 1);
	����Call(0, 1);
	����Call(װ��λ��, 2);
	����Call(1, 4);
	����Call(23, 4);
	����Call();
}

VOID ���ʰȡ(ULONG64 ��Ʒ��ַ)
{
	����Call(43);
	����Call(��Ʒ��ַ, 4);
	����Call(0, 1);
	����Call(1, 1);
	����Call(566, 2);
	����Call(291, 2);
	����Call(9961, 2);
	����Call(553, 2);
	����Call(285, 2);
	����Call(18802, 2);
	����Call(24743, 2);

	����Call();
}


VOID ������ؽ�ɫ()
{
	����Call(7);
	����Call();
}

VOID ���ѡͼ()
{
	����Call(15);
	����Call(0, 4);
	����Call();
}

VOID �����ͼ(int ���, int �Ѷ�, int ��Ԩ, int ��ϰ)
{
	����Call(16);
	����Call(���, 4);
	����Call(�Ѷ�, 1);
	����Call(0, 2);
	����Call(��Ԩ, 1);//  ' 0���� 1��Ԩ
	����Call(��ϰ, 1);//  ' 0���� 1��ϰ
	����Call(65535, 2);
	����Call(0, 4);
	����Call(0, 1);
	����Call(0, 4);//  ' ����
	����Call(0, 1);
	����Call(0, 4);
	����Call();
}

VOID �������(int ��, int ��)
{
	����Call(69);
	����Call();
	����Call(70);
	����Call();
	����Call(71);
	����Call(��, 1);
	����Call(��, 1);
	����Call();
	����Call(1426);
	����Call();
}

VOID �����ͼ()
{
	����Call(42);
	����Call();
}

VOID �����ͼ(int X, int Y)
{
	����Call(45);
	����Call(X, 1);
	����Call(Y, 1);
	����Call(0, 4);
	����Call(0, 4);
	����Call(0, 1);
	for (int i = 1; i <= 9; i++)
	{
		����Call(0, 2);
	}
	for (int i = 1; i <= 8; i++)
	{
		����Call(0, 4);
	}
	for (int i = 1; i <= 7; i++)
	{
		����Call(0, 2);
	}
	����Call(0, 4);
	for (int i = 1; i <= 3; i++)
	{
		����Call(0, 2);
	}
	for (int i = 1; i <= 3; i++)
	{
		����Call(0, 4);
	}
	����Call(0, 2);
	����Call(0, 1);
	����Call();
}

VOID ����ƶ�(int ���ͼID, int С��ͼID, int ����X����, int ����Y����)
{
	����Call(36);
	����Call(���ͼID, 4);
	����Call(С��ͼID, 4);
	����Call(����X����, 2);
	����Call(����Y����, 2);
	����Call(5, 1);
	����Call(38, 4);
	����Call(1, 2);
	����Call(0, 4);
	����Call(0, 1);
	����Call();
}