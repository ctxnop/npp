#pragma once

#include <string>
#include <vector>
#include <locale>

#ifndef NPP_STRING_DEFAULT_LOCALE
#define NPP_STRING_DEFAULT_LOCALE "english"
#endif

#ifndef NPP_STRING_CONVERT_FALLBACK
#define NPP_STRING_CONVERT_FALLBACK '?'
#endif

namespace npp
{
	/// @brief Convertit une chaine std::wstring en une chaine std::string.
	/// @tparam TLocale La locale à utiliser pour la convertion.
	/// @tparam TFallback Le caractère de subsitution en cas d'impossibilité de conversion.
	/// @param[in] ws Chaine à convertir.
	/// @return Chaine résultante.
	inline std::string narrow(const std::wstring& ws)
	{
		std::vector<char> buffer(ws.size());
		std::locale loc(NPP_STRING_DEFAULT_LOCALE);
		std::use_facet< std::ctype<wchar_t> >(loc).narrow(ws.data(), ws.data() + ws.size(), NPP_STRING_CONVERT_FALLBACK, &buffer[0]);

		return std::string(&buffer[0], buffer.size());
	}

	/// @brief Convertit une chaine std::string en une chaine std::wstring.
	/// @tparam TLocale La locale à utiliser pour la convertion.
	/// @param[in] s Chaine à convertir.
	/// @return Chaine résultante.
	inline std::wstring widen(const std::string& s)
	{
		std::vector<wchar_t> buffer(s.size());
		std::locale loc(NPP_STRING_DEFAULT_LOCALE);
		std::use_facet< std::ctype<wchar_t> >(loc).widen(s.data(), s.data() + s.size(), &buffer[0]);

		return std::wstring(&buffer[0], buffer.size());
	}

#if defined(UNICODE)
	typedef std::wstring nstring;

	inline std::wstring& text(std::wstring& value) { return value; }
	inline std::wstring text(const std::string& value) { return widen(value); }

#else
	typedef std::string nstring;

	inline std::string& text(std::string& value) { return value; }
	inline std::string text(const std::wstring& value) { return narrow(value); }
#endif

}

/// @brief Ajout d'un opérateur pour permettre l'écriture de std::string sur des flux unicodes.
/// @param[in] out Flux unicode.
/// @param[in] value La chaine à écrire.
/// @return Le flux dans lequel l'écriture à été effectuée.
/// Cette fonction doit être en dehors du namespace afin d'être utilisable.
inline std::wostream& operator<<(std::wostream& out, const std::string& value)
{
	out << value.c_str();
	return out;
}