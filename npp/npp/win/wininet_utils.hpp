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
