#pragma once

#if WIN32

#include <string>
#include <windows.h>
#include "../nstring.hpp"

//#define ERROR_INTERNET_EXTENDED_ERROR
//#if defined(ERROR_INTERNET_EXTENDED_ERROR)
//#include <wininet.h>
//#endif

namespace npp { namespace win {

	template<typename TMessage>
	struct winerror_trait
	{
		static TMessage get_message(DWORD code)
		{
/*
#if defined(ERROR_INTERNET_EXTENDED_ERROR)
			if (c == ERROR_INTERNET_EXTENDED_ERROR)
			{
				DWORD error;
				DWORD buffer_size;

				::InternetGetLastResponseInfo(&error, nullptr, &buffer_size);
				buffer = new TMessage::value_type[buffer_size + 1];
				::InternetGetLastResponseInfo(&error, buffer, &buffer_size);

				msg.assign(buffer, buffer_size);
				delete[] buffer;

				return basic_win32error_t(error, msg);
			}
#endif
*/

			TMessage msg;
			TMessage::value_type* buffer = nullptr;
			::FormatMessage(
				FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
				nullptr,
				code,
				MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL),
				reinterpret_cast<TMessage::value_type*>(&buffer),
				0,
				nullptr);
			if (buffer)
			{
				msg.assign(buffer);
				::LocalFree(buffer);
			}
			return msg;
		}
	};

	template<typename TMessage, typename TTrait = winerror_trait<TMessage>>
	class basic_winerror_t
	{
	private:
		DWORD code_;
		TMessage message_;
		explicit basic_winerror_t(DWORD c, TMessage m) : code_{ c }, message_{ m } {}

	public:
		basic_winerror_t(const basic_winerror_t<TMessage>& e) : code_{ e.code_ }, message_{ e.message } {}
		basic_winerror_t(basic_winerror_t&& e) : code_{ e.code_ }, message_{ std::move(e.message_) } {}
		basic_winerror_t<TMessage>& operator=(const basic_winerror_t& o)
		{
			if (this != &o)
			{
				code_ = o.code_;
				message_ = o.message_;
			}
			return *this;
		}

		DWORD code() const { return code_; }
		TMessage message() const { return message_; }
		operator DWORD() const { return code_; }

		static basic_winerror_t<TMessage> from_last_error()
		{
			return from_error(::GetLastError());
		}

		static basic_winerror_t<TMessage> from_error(DWORD c)
		{
			return basic_winerror_t(c, TTrait::get_message(c));
		}
	};

	using awinerror_t = basic_winerror_t<std::wstring>;
	using wwinerror_t = basic_winerror_t<std::string>;
	using nwinerror_t = basic_winerror_t<npp::nstring>;

} }

#endif