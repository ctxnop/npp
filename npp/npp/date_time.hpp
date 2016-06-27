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
#include <cstdint>
#include <iomanip>

namespace npp
{
	class date_time
	{
	private:
		std::uint16_t m_sec;
		std::uint16_t m_min;
		std::uint16_t m_hour;
		std::uint16_t m_mday;
		std::uint16_t m_mon;
		std::int16_t m_year;
		std::uint16_t m_wday;
		std::uint16_t m_yday;
		std::int32_t m_isdst;

	public:
		date_time();
		date_time(const date_time&) = default;
		date_time(date_time&&) = default;
		~date_time() = default;

		std::uint16_t sec() const;
		std::uint16_t min() const;
		std::uint16_t hour() const;
		std::uint16_t mday() const;
		std::uint16_t mon() const;
		std::int16_t year() const;
		std::uint16_t wday() const;
		std::uint16_t yday() const;
		std::int32_t isdst() const;

		void sec(const std::uint16_t value);
		void min(const std::uint16_t value);
		void hour(const std::uint16_t value);
		void mday(const std::uint16_t value);
		void mon(const std::uint16_t value);
		void year(const std::int16_t value);
		void wday(const std::uint16_t value);
		void yday(const std::uint16_t value);
		void isdst(const std::int32_t value);
	};

	template<typename TStream>
	TStream& format_date(TStream& s, const date_time& dt)
	{
		s << std::setfill('0')
			<< std::setw(4) << dt.year()
			<< std::setw(2) << dt.mon()
			<< std::setw(2) << dt.mday();
		return s;
	}

	template<char DATE_SEPARATOR, typename TStream>
	TStream& format_date(TStream& s, const date_time& dt)
	{
		s << std::setfill('0')
			<< std::setw(4) << dt.year() << DATE_SEPARATOR
			<< std::setw(2) << dt.mon() << DATE_SEPARATOR
			<< std::setw(2) << dt.mday();
		return s;
	}

	template<typename TStream>
	TStream& format_time(TStream& s, const date_time& dt)
	{
		s	<< std::setfill('0')
			<< std::setw(2) << dt.hour()
			<< std::setw(2) << dt.min()
			<< std::setw(2) << dt.sec();
			return s;
	}

	template<char TIME_SEPARATOR, typename TStream>
	TStream& format_time(TStream& s, const date_time& dt)
	{
		s	<< std::setfill('0')
			<< std::setw(2) << dt.hour() << TIME_SEPARATOR
			<< std::setw(2) << dt.min() << TIME_SEPARATOR
			<< std::setw(2) << dt.sec();
			return s;
	}

	template<typename TStream>
	TStream& format_datetime(TStream& s, const date_time& dt)
	{
		format_date(s, dt);
		format_time(s, dt);
		return s;
	}

	template<char DATE_SEPARATOR, char TIME_SEPARATOR, char DATETIME_SEPARATOR, typename TStream>
	TStream& format_datetime(TStream& s, const date_time& dt)
	{
		format_date<DATE_SEPARATOR>(s, dt);
		s << DATETIME_SEPARATOR;
		format_time<TIME_SEPARATOR>(s, dt);
		return s;
	}
}
