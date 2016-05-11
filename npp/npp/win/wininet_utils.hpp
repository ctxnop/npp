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

#include "windows_utils.hpp"
#include <wininet.h>

namespace npp { namespace win {

	/// @brief Obtient la dernière réponse obtenue après appel d'une fonction de WinInet.
	/// @tparam TString Type du message.
	/// @return La réponse obtenue.
	template<typename TString>
	TString internet_get_last_response_info()
	{
		TString msg;
		DWORD error;
		DWORD buffer_size = 0;
		
		if (::InternetGetLastResponseInfo(&error, nullptr, &buffer_size) && buffer_size)
		{
			TString::pointer buffer = new TString::value_type[buffer_size + 1];
			if (buffer)
			{
				::InternetGetLastResponseInfo(&error, buffer, &buffer_size);
				msg.assign(buffer, buffer_size);
				delete[] buffer;
			}
		}

		return msg;
	}

	/// @brief Ce trait permet d'obtenir le message d'un code erreur en utilisant FormatMessage.
	/// @tparam TString Type de chaine pour le message.
	template<typename TString>
	struct winineterror_trait
	{
		/// @brief Obtient le message.
		/// @param[in] code Code erreur.
		/// @return Message obtenu.
		static TString get_message(DWORD code)
		{
			if (code >= INTERNET_ERROR_BASE && code <= INTERNET_ERROR_LAST)
			{
				if (code == ERROR_INTERNET_EXTENDED_ERROR) return internet_get_last_response_info<TString>();
				return get_error_message<TString>(code, TEXT("wininet.dll"));
			}
			return get_error_message<TString>(code);
		}
	};
} }
