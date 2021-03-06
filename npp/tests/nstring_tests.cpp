﻿/*
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
#include "../npp/nstring.hpp"

#include "boost_unit_test.hpp"

BOOST_AUTO_TEST_SUITE(nstring)

/// @brief TEST: Transforme une chaine std::string en une chaine std::wstring lorsque la chaine d'origine ne contient que des caractères ASCII.
BOOST_AUTO_TEST_CASE(widen_ascii)
{
	BOOST_CHECK_EQUAL(npp::widen("hello éïèà@"), L"hello éïèà@");
}

/// @brief TEST: Transforme une chaine std::wstring en une chaine std::string lorsque la chaine d'origine ne contient que les caractères ASCII.
BOOST_AUTO_TEST_CASE(narrow_ascii)
{
	BOOST_CHECK_EQUAL(npp::narrow(L"hello world"), "hello world");
}

/// @brief TEST: Transforme une chaine std::wstring en une chaine std::string lorsque la chaine d'origine contient de l'unicode.
BOOST_AUTO_TEST_CASE(narrow_unicode)
{
	BOOST_CHECK_EQUAL(npp::narrow(L"hello 日本語"), "hello ???");
}

BOOST_AUTO_TEST_SUITE_END()
