#include "����.h"
// ȡ·������
#include <Shlobj.h>

// ȡʱ��
#include <cwchar>
#include <chrono>
#include <sstream>
#include <iomanip>


DWORD GetProcessIdByName(LPCWSTR ����) {
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);

	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hSnap) {
		return 0;
	}

	if (Process32First(hSnap, &pe))
	{
		while (Process32Next(hSnap, &pe)) {
			if (lstrcmpi(����, pe.szExeFile) == 0) {
				return pe.th32ProcessID;
			}
		}
	}
	CloseHandle(hSnap);
	return 0;
}

vector<byte> �ֽڼ�׷��(vector<byte> oldByteArr, vector<vector<byte>> newByteArrs) {
	for (const auto& arr : newByteArrs) {
		oldByteArr.insert(oldByteArr.end(), arr.begin(), arr.end());
	}
	return oldByteArr;
}

// ����ת�ֽ�����
vector<byte>& IntToByteArr(DWORD64 num, int length)
{
	vector<byte>& bytes = *(new vector<byte>);

	const int BITS_PER_BYTE = 8;
	for (int i = 0; i < length; ++i) {
		int offset = i * BITS_PER_BYTE;
		byte byte_tmp = (num >> offset) & 0xFF;
		bytes.push_back(byte_tmp);
	}

	return bytes;
}

vector<byte> MakeByteArr(int num)
{
	vector<byte> res;
	res.resize(num);
	return res;
}

vector<byte> AnsiToUnicode(string str)
{
	vector<byte> Ret;
	int len = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
	unique_ptr<wchar_t[]> pwText(new wchar_t[len]);
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, pwText.get(), len);

	for (int i = 0; i < len * 2; i++)
	{
		Ret.push_back(reinterpret_cast<const char*>(&pwText.get()[i])[0]);
	}
	Ret.push_back(0);
	Ret.push_back(0);
	return Ret;
}

string UnicodeToAnsi(const vector<byte>& vby)
{
	const wchar_t* pwstr = reinterpret_cast<const wchar_t*>(vby.data());
	wstring wstr(pwstr, pwstr + (vby.size() / sizeof(wchar_t)));

	wstring_convert<codecvt_utf8<wchar_t>> converter;
	string str = converter.to_bytes(wstr);

	return str;
}

wstring GetDesktopPath()
{
	wchar_t desktop[MAX_PATH] = { 0 };
	SHGetFolderPathW(NULL, CSIDL_DESKTOPDIRECTORY, NULL, SHGFP_TYPE_CURRENT, desktop);
	return wstring(desktop);
}


void д����(wstring ��, wstring ��, wstring ֵ)
{
	wstring filePath = GetDesktopPath() + L"\\DnfHelper.ini";
	WritePrivateProfileStringW(��.c_str(), ��.c_str(), ֵ.c_str(), filePath.c_str());
}

DWORD ������(wstring ��, wstring ��)
{
	wstring filePath = GetDesktopPath() + L"\\DnfHelper.ini";
	DWORD result = GetPrivateProfileIntW(��.c_str(), ��.c_str(), 0, filePath.c_str());
	return result;
}


const wchar_t* format_string(const wchar_t* format, ...)
{
	const size_t message_size = 256;
	wchar_t* message = new wchar_t[message_size];

	va_list args;
	va_start(args, format);
	vswprintf(message, message_size, format, args);
	va_end(args);

	return message;
}

wstring get_current_time_string()
{
	// ��ȡ��ǰϵͳʱ��
	auto now = chrono::system_clock::now();

	// ��ʱ��ת��Ϊ����ʱ��
	time_t t = chrono::system_clock::to_time_t(now);
	struct tm tm;
	localtime_s(&tm, &t);

	// ��ʽ��ʱ��Ϊ�ַ���
	char buffer[80];
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", &tm);

	// ת��Ϊ���ַ����͵��ַ���
	const size_t output_size = strlen(buffer) + 1;
	wchar_t* output = new wchar_t[output_size];
	mbstowcs_s(nullptr, output, output_size, buffer, _TRUNCATE);

	wstring result(output);
	delete[] output;

	return result;
}


wstring get_running_time_string()
{
	static auto start_time = chrono::high_resolution_clock::now(); // ��¼��������ʱ��
	auto current_time = chrono::high_resolution_clock::now();      // ��ȡ��ǰʱ��

	// ����ʱ���
	auto duration = chrono::duration_cast<chrono::seconds>(current_time - start_time);
	long long duration_seconds = duration.count();

	// ��ʱ���ת��Ϊʱ�������ʽ
	int hours = static_cast<int>(duration_seconds) / 3600;
	int minutes = (static_cast<int>(duration_seconds) % 3600) / 60;
	int seconds = static_cast<int>(duration_seconds) % 60;

	// ��ʽ��ʱ���ַ���
	wstringstream ss;
	ss << setfill(L'0') << setw(2) << hours << L":"
		<< setfill(L'0') << setw(2) << minutes << L":"
		<< setfill(L'0') << setw(2) << seconds;

	return ss.str();
}

