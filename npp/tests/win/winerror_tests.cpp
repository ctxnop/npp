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
#include "../../npp/win/winerror.hpp"

#include "../boost_unit_test.hpp"

BOOST_AUTO_TEST_SUITE(winerror)

/// @brief TEST: Construit un message d'erreur avec le code ERROR_NOT_SUPPORTED.
BOOST_AUTO_TEST_CASE(winerror_error_not_supported)
{
	npp::win::winerror_t e = npp::win::winerror_t(ERROR_NOT_SUPPORTED);
	BOOST_CHECK_EQUAL(e.message<std::wstring>(), L"Cette demande n’est pas prise en charge.\r\n");
}

/// @brief TEST: Construit un message d'erreur avec un code erreur ne correspondant à aucune erreur.
BOOST_AUTO_TEST_CASE(winerror_unknown_error)
{
	npp::win::winerror_t e = npp::win::winerror_t(42);
	BOOST_CHECK_EQUAL(e.message<std::wstring>(), L"");
}

BOOST_AUTO_TEST_SUITE_END()
