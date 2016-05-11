/*
The MIT License (MIT)

Copyright (c) 2016 Collignon Loïc

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once
#ifndef WIN32
#error This file belongs to Window's platforms.
#endif

#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <windows.h>

namespace npp { namespace win {

	/// @brief Obtient le message d'erreur associé à un code.
	/// @tparam TString Type de chaine.
	/// @param[in] code Le code de l'erreur.
	/// @param[in] module Le nom du module depuis lequel on effectue la recherche.
	/// @param[in] flags Les drapeaux de format (voir ::FormatMessage).
	/// @param[in] lang La langue principale.
	/// @param[in] sublang La langue secondaire.
	/// @return Le message.
	template<typename TString>
	TString get_error_message(DWORD code, const TString& module, DWORD flags, WORD lang = LANG_NEUTRAL, WORD sublang = SUBLANG_NEUTRAL)
	{
		TString msg;
		HMODULE hMod = (module.size()) ? ::GetModuleHandle(module.c_str()) : nullptr;
		TString::pointer buffer = nullptr;
		::FormatMessage(
			flags,
			hMod,
			code,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL),
			reinterpret_cast<TString::pointer>(&buffer),
			0,
			nullptr);

		if (buffer)
		{
			msg.assign(buffer);
			::LocalFree(buffer);
		}

		return msg;
	}

	/// @brief Obtient le message d'erreur associé à un code.
	/// @tparam TString Type de chaine.
	/// @param[in] code Le code de l'erreur.
	/// @param[in] module Le nom du module depuis lequel on effectue la recherche.
	/// @param[in] lang La langue principale.
	/// @param[in] sublang La langue secondaire.
	/// @return Le message.
	template<typename TString>
	TString get_error_message(DWORD code, const TString& module, WORD lang = LANG_NEUTRAL, WORD sublang = SUBLANG_NEUTRAL)
	{
		return get_error_message(code, module, FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS, lang, sublang);
	}

	/// @brief Obtient le message d'erreur associé à un code.
	/// @tparam TString Type de chaine.
	/// @param[in] code Le code de l'erreur.
	/// @param[in] lang La langue principale.
	/// @param[in] sublang La langue secondaire.
	/// @return Le message.
	template<typename TString>
	TString get_error_message(DWORD code, WORD lang = LANG_NEUTRAL, WORD sublang = SUBLANG_NEUTRAL)
	{
		return get_error_message(code, TString(), FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS, lang, sublang);
	}

} }
