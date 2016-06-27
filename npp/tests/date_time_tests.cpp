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
#include "../npp/date_time.hpp"
#include <sstream>
#include "boost_unit_test.hpp"

BOOST_AUTO_TEST_SUITE(date_time)

/// @brief TEST: Formatte une date pour la transformer en chaine.
BOOST_AUTO_TEST_CASE(format_simple)
{
	npp::date_time dt;
	std::stringstream ss;
	npp::format_datetime(ss, dt);
	std::string date = ss.str();
}

/// @brief TEST: Formatte une date pour la transformer en chaine.
BOOST_AUTO_TEST_CASE(format_sep)
{
	npp::date_time dt;
	std::stringstream ss;
	npp::format_datetime<'-', ':', 'T'>(ss, dt);
	std::string date = ss.str();
}

BOOST_AUTO_TEST_SUITE_END()
