#pragma once

#if WIN32

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

#endif