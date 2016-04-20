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
