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

#include "date_time.hpp"
#define __STDC_WANT_LIB_EXT1__ 1
#include <time.h>

namespace npp
{
	date_time::date_time()
	{
		time_t t = ::time(nullptr);
		struct tm local;
		::localtime_s(&local, &t);
		m_sec = local.tm_sec;
		m_min = local.tm_min;
		m_hour = local.tm_hour;
		m_mday = local.tm_mday;
		m_mon = local.tm_mon + 1;
		m_year = local.tm_year + 1900;
		m_wday = local.tm_wday;
		m_yday = local.tm_yday;
		m_isdst = local.tm_isdst;
	}

	std::uint16_t date_time::sec() const { return m_sec; }
	std::uint16_t date_time::min() const { return m_min; }
	std::uint16_t date_time::hour() const { return m_hour; }
	std::uint16_t date_time::mday() const { return m_mday; }
	std::uint16_t date_time::mon() const { return m_mon; }
	std::int16_t date_time::year() const { return m_year; }
	std::uint16_t date_time::wday() const { return m_wday; }
	std::uint16_t date_time::yday() const { return m_yday; }
	std::int32_t date_time::isdst() const { return m_isdst; }

	void date_time::sec(const std::uint16_t value) { m_sec = value; }
	void date_time::min(const std::uint16_t value) { m_min = value; }
	void date_time::hour(const std::uint16_t value) { m_hour = value; }
	void date_time::mday(const std::uint16_t value) { m_mday = value; }
	void date_time::mon(const std::uint16_t value) { m_mon = value; }
	void date_time::year(const std::int16_t value) { m_year = value; }
	void date_time::wday(const std::uint16_t value) { m_wday = value; }
	void date_time::yday(const std::uint16_t value) { m_yday = value; }
	void date_time::isdst(const std::int32_t value) { m_isdst = value; }
}