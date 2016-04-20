#pragma once

namespace npp
{
	template<class TCType>
	class default_deleter_t
	{
	public:
		static void delete_value(TCType value) {}
	};

	template<class TCType, class TDeleter = default_deleter_t<TCType>>
	class cwrap_t
	{
	private:
		TCType value_;

		cwrap_t(const TCType&) = delete;
		cwrap_t& operator=(const TCType&) = delete;
	public:
		cwrap_t(TCType value) : value_{ value } {}
		cwrap_t(TCType&& value) : value_{ std::move(value) } {}
		cwrap_t(cwrap_t&& value) : value_{ std::move(value.value_) } {}
		cwrap_t& operator=(cwrap_t&& value)
		{
			value_ = std::move(value.value_);
			return *this;
		}
	};
}
