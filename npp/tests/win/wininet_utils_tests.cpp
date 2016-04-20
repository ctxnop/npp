#include "../../npp/win/wininet_utils.hpp"
#include "../../npp/win/winerror.hpp"

#include "../boost_unit_test.hpp"

BOOST_AUTO_TEST_SUITE(wininet_utils)

/// @brief TEST: Construit un message d'erreur avec le code WinInet ERROR_INTERNET_CANNOT_CONNECT.
BOOST_AUTO_TEST_CASE(wininet_error_internet_cannot_connect)
{
	npp::win::winerror_t e = npp::win::winerror_t(ERROR_INTERNET_CANNOT_CONNECT);
	BOOST_CHECK_EQUAL((e.message<std::wstring, npp::win::winineterror_trait<std::wstring>>()), L"Impossible d'établir une connexion avec le serveur.\r\n");
}

/// @brief TEST: Construit un message d'erreur avec le code WinInet ERROR_INTERNET_EXTENDED_ERROR.
BOOST_AUTO_TEST_CASE(wininet_error_internet_extended_error)
{
	npp::win::winerror_t e = npp::win::winerror_t(ERROR_INTERNET_EXTENDED_ERROR);
	BOOST_CHECK_EQUAL((e.message<std::wstring, npp::win::winineterror_trait<std::wstring>>()), L"");
}

BOOST_AUTO_TEST_SUITE_END()
