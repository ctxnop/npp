#pragma once
#ifndef WIN32
#error This file belongs to Window's platforms.
#endif

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
