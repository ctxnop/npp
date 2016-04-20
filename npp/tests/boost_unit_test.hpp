#pragma once

#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test_log.hpp>

namespace boost { namespace test_tools { namespace tt_detail {

/// @brief Permet d'afficher les tests qui s'évaluent avec des std::wstring.
template<>
struct BOOST_TEST_DECL print_log_value<std::wstring> {
	void  operator()(std::ostream& ostr, const std::wstring& t) { ostr << t.c_str(); }
};

} } }