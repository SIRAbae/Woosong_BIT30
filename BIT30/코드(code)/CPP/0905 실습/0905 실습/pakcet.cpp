//packet.cpp
#include "std.h"


MESSAGE pack_Message(TCHAR* G_name)
{
	MESSAGE pack;

	pack.flage = PACK_MESSAGE;
	_tcscpy_s(pack.G_name, G_name);

	return pack;
}