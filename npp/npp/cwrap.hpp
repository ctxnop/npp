#pragma once

namespace npp
{
	/// @brief Ce est à utiliser avec cwrap_t lorsqu'il n'y à rien à faire au moment de la destruction de la ressource C.
	template<class TCType>
	class ctype_trait_t
	{
	public:
		/// @brief Détruit la ressource C.
		/// @param[in] value La valeur à détruire.
		static void delete_value(TCType value) {}

		/// @brief Obtient la valeur par défaut pour ce type.
		/// @return Valeur par défaut.
		static TCType default_value() { return TCType(); }		
	};

	/// @brief Permet d'encapsuler une ressource C afin d'y appliquer un mode RAII.
	template<class TCType, class TTrait = ctype_trait_t<TCType>>
	class cwrap_t
	{
	private:
		TCType value_;

		cwrap_t(const TCType&) = delete;
		cwrap_t& operator=(const TCType&) = delete;

	public:
		/// @brief Construit une nouvelle instance.
		cwrap_t() : value_{ TTrait::default_value() } {}

		/// @brief Construit une nouvelle instance.
		/// @param[in] value Valeur à encapsuler.
		cwrap_t(TCType value) : value_{ value } {}

		/// @brief Construit une nouvelle instance.
		/// @param[in] value Valeur à encapsuler.
		cwrap_t(TCType&& value) : value_{ std::move(value) } { }

		/// @brief Construit une nouvelle instance.
		/// @param[in] wrap Instance à déplacer.
		cwrap_t(cwrap_t&& wrap) : value_{ std::move(wrap.value_) } { wrap.value_ = TTrait::default_value(); }

		/// @brief Détruit l'instance.
		~cwrap_t() { TTrait::delete_value(value_); value_t = TTrait::default_value(); }

		/// @brief Affecte cette instance avec une autre valeur.
		/// @param[in] wrap Instance à déplacer.
		/// @return Cette instance.
		cwrap_t& operator=(cwrap_t&& wrap)
		{
			TTrait::delete_value(value_);
			value_ = std::move(value.value_);
			return *this;
		}

		/// @brief Cast implicite vers le type encapsulé.
		operator TCType() const { return value_; }
	};
}
