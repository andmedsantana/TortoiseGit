// TortoiseGit - a Windows shell extension for easy version control

// Copyright (C) 2003-2007 - TortoiseSVN

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
#pragma once

#include <string>
#include <WinDef.h>
#pragma warning (push,1)
#ifndef stdstring
	typedef std::wstring wide_string;
#	ifdef UNICODE
#		define stdstring wide_string
#	else
#		define stdstring std::string
#	endif
#endif
#pragma warning (pop)

/**
 * \ingroup Utils
 * Class to convert strings from/to UTF8 and UTF16.
 */
class CUnicodeUtils
{
public:
	CUnicodeUtils(void);
	~CUnicodeUtils(void);
#if defined(_MFC_VER) || defined(CSTRING_AVAILABLE)
	static CStringA GetUTF8(const CStringW& string);
	static CStringA GetMulti(const CStringW& string, int acp);
	static CStringA GetUTF8(const CStringA& string);
	static CString GetUnicode(const CStringA& string, int acp=CP_UTF8);
	static CStringA ConvertWCHARStringToUTF8(const CString& string);
	static int GetCPCode(CString & codename);
#endif
#ifdef UNICODE
	static std::string StdGetUTF8(const wide_string& wide);
	static wide_string StdGetUnicode(const std::string& multibyte);
#else
	static std::string StdGetUTF8(std::string str) {return str;}
	static std::string StdGetUnicode(std::string multibyte) {return multibyte;}
#endif
};

std::string WideToMultibyte(const wide_string& wide);
std::string WideToUTF8(const wide_string& wide);
wide_string MultibyteToWide(const std::string& multibyte);
wide_string UTF8ToWide(const std::string& multibyte);

#ifdef UNICODE
	stdstring UTF8ToString(const std::string& string); 
	std::string StringToUTF8(const stdstring& string); 
#else
	stdstring UTF8ToString(const std::string& string); 
	std::string StringToUTF8(const stdstring& string);
#endif

int LoadStringEx(HINSTANCE hInstance, UINT uID, LPTSTR lpBuffer, int nBufferMax, WORD wLanguage);
