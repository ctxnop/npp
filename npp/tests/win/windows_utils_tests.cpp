#include "../../npp/win/windows_utils.hpp"

#include "../boost_unit_test.hpp"

BOOST_AUTO_TEST_SUITE(windows_utils)

/// @brief TEST: Obtient le message d'erreur avec le code ERROR_NOT_SUPPORTED.
BOOST_AUTO_TEST_CASE(get_error_message_error_not_supported)
{
	BOOST_CHECK_EQUAL(npp::win::get_error_message<std::wstring>(ERROR_NOT_SUPPORTED), L"Cette demande n’est pas prise en charge.\r\n");
}

/// @brief TEST: Obtient le message d'erreur avec un code erreur ne correspondant à aucune erreur.
BOOST_AUTO_TEST_CASE(get_error_message_unknown_error)
{
	BOOST_CHECK_EQUAL(npp::win::get_error_message<std::wstring>(42), L"");
}

BOOST_AUTO_TEST_SUITE_END()
