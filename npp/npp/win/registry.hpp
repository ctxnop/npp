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
#include "../cwrap.hpp"
#include "../nstring.hpp"

namespace npp {

	template<>
	class ctype_trait_t<HKEY>
	{
	public:
		/// @brief Détruit la ressource C.
		/// @param[in] value La valeur à détruire.
		static void delete_value(HKEY value) { if (value) ::RegCloseKey(value); }

		/// @brief Obtient la valeur par défaut pour ce type.
		/// @return Valeur par défaut.
		static HKEY default_value() { return nullptr; }

		static cwrap_t<HKEY> open_key(HKEY base_key, const npp::nstring& value)
		{
			HKEY k;
			::RegOpenKey(base_key, value.c_str(), &k);
			return cwrap_t<HKEY>(k);
		}
	};

	namespace win
	{
		typedef cwrap_t<HKEY> regkey_t;
	}
}
