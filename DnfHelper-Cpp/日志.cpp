#include "��־.h"
#include "����.h"

HELE	editContent;


VOID ������־���(HELE hele) {
	editContent = hele;
}

VOID ��־���(const wchar_t* message) {
	XEdit_AddTextUser(editContent, message);
}