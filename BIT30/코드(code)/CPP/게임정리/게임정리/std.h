//std.h
#define WIN32_LEAN_AND_MEAN   //windows.h�� winsock2.h �浹 ����

#include <Windows.h>
//==============  ���� ��Ʈ�� ���� ȹ�� (page140)
#include <commctrl.h>					//�Լ� ����� 
#pragma comment(lib, "comctl32.lib")	//�Լ� ������ 
//======================================================
#include <tchar.h>
#include <vector>
using namespace std;
#pragma warning(disable : 4996)
#include "resource.h"
#include "member.h"
#include "ui.h"
#include "handler.h"
#include "InsertProc.h"
#include "wbclient.h"

