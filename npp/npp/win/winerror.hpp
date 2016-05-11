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

namespace npp { namespace win {

	/// @brief Ce trait permet d'obtenir le message d'un code erreur en utilisant FormatMessage.
	/// @tparam TString Type de chaine pour le message.
	template<class TString>
	struct winerror_trait
	{
		/// @brief Obtient le message.
		/// @param[in] code Code erreur.
		/// @return Message obtenu.
		static TString get_message(DWORD code)
		{
			return get_error_message<TString>(code);
		}
	};

	/// @brief Représente une erreur Windows.
	class winerror_t
	{
	private:
		DWORD code_;
		
	public:
		/// @brief Construit un code erreur.
		explicit winerror_t() : code_{ 0 } {}

		/// @brief Construit un code erreur.
		/// @param[in] c Code erreur.
		explicit winerror_t(DWORD c) : code_{ c } {}

		/// @brief Construit un code erreur.
		/// @param[in] e Autre instance à copier.
		winerror_t(const winerror_t& e) : code_{ e.code_ } {}

		/// @brief Construit un code erreur.
		/// @param[in] e Autre instance à déplacer.
		winerror_t(winerror_t&& e) : code_{ e.code_ } {}

		/// @brief Affecte cette instance avec la valeur d'une autre instance.
		/// @param[in] o Instance dont la valeur est copiée.
		/// @return Cette instance.
		winerror_t& operator=(const winerror_t& o)
		{
			if (this != &o) 
			{
				code_ = o.code_;
			}
			return *this;
		}

		/// @brief Obtient le code de l'erreur.
		/// @return Code de l'erreur.
		DWORD code() const { return code_; }

		/// @brief Obtient le message de l'erreur.
		/// @tparam TString type de la chaine à obtenir.
		/// @tparam TTrait Trait pour obtenir le message.
		/// @return Message de l'erreur.
		template<class TString, class TTrait = winerror_trait<TString>>
		TString message() const { return TTrait::get_message(code_); }

		/// @brief Opérateur de conversion implicite pour obtenir le code de l'erreur.
		/// @return Code de l'erreur.
		operator DWORD() const { return code_; }
	};

} }
