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
