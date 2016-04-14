#include <iostream>
#include <io.h>
#include <fcntl.h>

#include "npp/nstring.hpp"
#include "npp/win/winerror.hpp"
#include "npp/win/windows_utils.hpp"
#include "npp/win/wininet_utils.hpp"

template<typename TValue>
void ASSERT_EQUAL(const std::wstring& name, const TValue& expected, const TValue& result)
{
	std::wcout
		<< L"[" << ((result == expected) ? L"SUCCESS] " : L"ERROR] ")
		<< name
		<< L" =\r\n{\r\n\texpected: \"" << expected
		<< L"\",\r\n\tresult: \"" << result
		<< L"\"\r\n}" << std::endl;
}

void test_string_widen_01()
{
	std::string input = "hello éïèà@";
	std::wstring result = npp::widen(input);
	std::wstring expected = L"hello éïèà@";
	ASSERT_EQUAL(L"test_string_widen_01", expected, result);
}

void test_string_narrow_01()
{
	std::wstring input = L"hello 日本語";
	std::string result = npp::narrow(input);
	std::string expected = "hello ???";
	ASSERT_EQUAL(L"test_string_narrow_01", expected, result);
}

void test_windowsutils_geterrormessage_01()
{
	std::wstring result = npp::win::get_error_message<std::wstring>(ERROR_NOT_SUPPORTED);
	std::wstring expected = L"Cette demande n’est pas prise en charge.\r\n";
	ASSERT_EQUAL(L"test_windowsutils_geterrormessage_01", expected, result);
}

void test_windowsutils_geterrormessage_02()
{
	std::wstring result = npp::win::get_error_message<std::wstring>(42);
	std::wstring expected = L"";
	ASSERT_EQUAL(L"test_windowsutils_geterrormessage_02", expected, result);
}

void test_win_winerror_01()
{
	npp::win::winerror_t e = npp::win::winerror_t(ERROR_NOT_SUPPORTED);
	std::wstring expected = L"Cette demande n’est pas prise en charge.\r\n";
	ASSERT_EQUAL(L"test_win_winerror_01", expected, e.message<std::wstring>());
}

void test_win_winerror_02()
{
	npp::win::winerror_t e = npp::win::winerror_t(42);
	std::wstring expected = L"";
	ASSERT_EQUAL(L"test_win_winerror_02", expected, e.message<std::wstring>());
}

void test_win_winerror_03()
{
	npp::win::winerror_t e = npp::win::winerror_t(ERROR_INTERNET_CANNOT_CONNECT);
	std::wstring expected = L"Impossible d'établir une connexion avec le serveur.\r\n";
	ASSERT_EQUAL(L"test_win_winerror_03", expected, e.message<std::wstring, npp::win::winineterror_trait<std::wstring>>());
}

void test_win_winerror_04()
{
	npp::win::winerror_t e = npp::win::winerror_t(ERROR_INTERNET_EXTENDED_ERROR);
	std::wstring expected = L"Impossible d'établir une connexion avec le serveur.\r\n";
	ASSERT_EQUAL(L"test_win_winerror_04", expected, e.message<std::wstring, npp::win::winineterror_trait<std::wstring>>());
}

/// @brief Point d'entré du programme.
/// @return Code de sortie.
int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);

	test_string_widen_01();
	test_string_narrow_01();

	test_windowsutils_geterrormessage_01();
	test_windowsutils_geterrormessage_02();

	test_win_winerror_01();
	test_win_winerror_02();
	test_win_winerror_03();
	test_win_winerror_04();

	std::wcout.flush();
    return 0;
}

