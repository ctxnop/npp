#include <iostream>

#include "npp/nstring.hpp"
#include "npp/win/winerror.hpp"

#define ASSERT_EQUAL(name, expected, result) (std::wcout << L"[" << ((result == expected) ? L"SUCCESS] " : L"ERROR] ") << name << L" { expected: \"" << expected << L"\", result: \""<< result << L"\"}" << std::endl)

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

void test_win_nwinerror_01()
{
	npp::win::nwinerror_t e = npp::win::nwinerror_t::from_error(ERROR_NOT_SUPPORTED);
	std::wstring expected = L"Cette demande n’est pas prise en charge.\r\n";
	ASSERT_EQUAL(L"test_win_nwinerror_01", expected, e.message());
}

/// @brief Point d'entré du programme.
/// @return Code de sortie.
int main()
{
	test_string_widen_01();
	test_string_narrow_01();
	test_win_nwinerror_01();

    return 0;
}

