#include <gtest/gtest.h>
#include "subst.h"

#include <boost/regex.hpp>

TEST(SubstTests, parse_grep) {
	std::string fname;
	int line_no;
	std::string line;

	EXPECT_TRUE(substitution::parse_grep("hello.cpp:10:    x = 10;", fname, line_no, line));
	EXPECT_STREQ(fname.c_str(), "hello.cpp");
	EXPECT_EQ(10, line_no);
	EXPECT_STREQ(line.c_str(), "    x = 10;");
}

TEST(SubstTests, escape_subst_str) {

    std::string s1 = "'quoted' \\escaped tom & jerry";
    std::string expected = "'\\''quoted'\\'' \\\\escaped tom \\& jerry";

    substitution::escape_subst_str(s1);
    EXPECT_EQ(s1, expected);

}

TEST(SubstTests, subst_line) {

    std::string code(R"(
func1("the %s temperature is %f over %d sites", mode, temp, nsites, "address %p, size %ld", &n, sizeof(n));
)");

    substitution::HashTable ht;
    std::string result = substitution::subst_line(code, ht);

    boost::regex r1(R"(.*%s.*%f.*%d.*mode, temp, nsites.*%p.*%ld.*)");

    std::cerr << result << std::endl;
    EXPECT_TRUE(boost::regex_match(result, r1));
    
}

