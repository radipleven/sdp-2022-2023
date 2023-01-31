#include "catch2/catch_all.hpp"
#include "solution.h"

TEST_CASE("isCorrect() recognizes correct expressions")
{
	SECTION("Empty expression") {
		REQUIRE( isCorrect(""));
		REQUIRE( isCorrect(" "));
		REQUIRE( isCorrect("   "));
		REQUIRE( isCorrect("    "));
		REQUIRE( isCorrect("	"));
		REQUIRE( isCorrect("		"));
	}
	SECTION("No brackets") {
		REQUIRE( isCorrect("abc"));
		REQUIRE( isCorrect("wdsyjkocnagbqupvhezkfuzxr"));
		REQUIRE( isCorrect("pwnztqjuvicahayklbnrglsxq"));
		REQUIRE( isCorrect("sxryvkzawpnugdbhajlmcfwbn"));
		REQUIRE( isCorrect("lrshjzoaefnbdxvfwziukpkjg"));
		REQUIRE( isCorrect("mpizfvgcwskjwehxoxzurcnyy"));
	}
	SECTION("One pair of brackets") {
		REQUIRE( isCorrect("(abc)"));
		REQUIRE( isCorrect("a(b)c") );
		REQUIRE( isCorrect("a[b]c") );
		REQUIRE( isCorrect("a{b}c") );
		REQUIRE( isCorrect("a(bcd)e") );
		REQUIRE( isCorrect("a[bcd]e") );
		REQUIRE( isCorrect("a{bcd}e") );
		REQUIRE( isCorrect("ab[cd]ef") );
		REQUIRE( isCorrect("ab{cd}e") );
		REQUIRE( isCorrect("abc(d)e") );
		REQUIRE( isCorrect("a(bcdef)g") );
	}
	SECTION("Multiple brackets") {
		REQUIRE( isCorrect("(((abc)))"));
		REQUIRE( isCorrect("a(bc)de(fg)hi") );
		REQUIRE( isCorrect("a[bc]de[fg]hi") );
		REQUIRE( isCorrect("a{bc}de{fg}hi") );
		REQUIRE( isCorrect("ab(cd)ef(gh)ij") );
		REQUIRE( isCorrect("ab[cd]ef[gh]ij") );
		REQUIRE( isCorrect("ab{cd}ef{gh}ij") );
		REQUIRE( isCorrect("a(b(c(d)e)f)g(h)i") );
	}
	SECTION("Mixed brackets") {
		REQUIRE( isCorrect("([abc])"));
		REQUIRE( isCorrect("a(b[c{d(e)f}g]h)i") );
		REQUIRE( isCorrect("a[b{c(d[e]f)g}h]i") );
		REQUIRE( isCorrect("a{b(c[d{e(f)g}]h)i}") );
		REQUIRE( isCorrect("a(b[c{d(e)f}]g)h(i)") );
		REQUIRE( isCorrect("a[b{c(d[e]f)}]g{h(i)}") );
		REQUIRE( isCorrect("a{b(c[d{e(f)g}h])i}") );
		REQUIRE( isCorrect("a(b[c{d(e)f}g]h)i(j)") );
		REQUIRE( isCorrect("a[b{c(d[e]f)g}h]i[j]") );
		REQUIRE( isCorrect("a{b(c[d{e(f)g}]h)i}j") );
		REQUIRE( isCorrect("a(b[c{d(e)f}]g)h(i[j])") );
	}
	SECTION("Complex expression") {
		REQUIRE( isCorrect("((abc) { abc }(((def)))def)"));
		REQUIRE( isCorrect("a very ( long b [ string c { with d ( multiple e ) f } g ] h ) i pairs") );
		REQUIRE( isCorrect("a [ b { c ( d [ e very ] f long ) g } h ] i string") );
		REQUIRE( isCorrect("a { b ( c [ d { e ( f with ) g } ] h ) i } multiple pairs") );
		REQUIRE( isCorrect("a ( b [ c { d ( e very ) f } ] g ) h ( i long ) string") );
		REQUIRE( isCorrect("a [ b { c ( d [ e with ] f ) } ] g { h ( i multiple ) } pairs") );
		REQUIRE( isCorrect("a { b ( c [ d { e ( f long ) g } h ] ) i } string") );
		REQUIRE( isCorrect("a ( b [ c { d ( e very ) f } g ] h ) i ( j with ) multiple pairs") );
		REQUIRE( isCorrect("a [ b { c ( d [ e long ] f ) g } h ] i [ j string ] with") );
		REQUIRE( isCorrect("a { b ( c [ d { e ( f multiple ) g } ] h ) i } pairs") );
		REQUIRE( isCorrect("a ( b [ c { d ( e very ) f } ] g ) h ( i [ j long ] ) string") );
	}
	SECTION("Single pair of brackets") {
		REQUIRE( isCorrect("()"));
		REQUIRE( isCorrect("[]"));
		REQUIRE( isCorrect("{}"));
	}
	SECTION("Brackets-only") {
		REQUIRE( isCorrect("((()))"));
		REQUIRE( isCorrect("[[[]]]"));
		REQUIRE( isCorrect("{{{}}}"));
	}
	SECTION("Brackets next to each other") {
		REQUIRE( isCorrect("{}[](){}[]()"));
		REQUIRE( isCorrect("[]{}(){}{}[]()(){}{}"));
		REQUIRE( isCorrect("{}{}{}()[]{}[]{}()[]{}()()[]"));
		REQUIRE( isCorrect("[][]{}{}()(){}()[]()[]{}[]()"));
		REQUIRE( isCorrect("(){}()[][]()(){}{}[]{}[](){}[]()"));
	}
	SECTION("Nested brackets") {
		REQUIRE( isCorrect("{{}}()[()]"));
		REQUIRE( isCorrect("{[{}]}()[]") );
		REQUIRE( isCorrect("[{()}]{}[]") );
		REQUIRE( isCorrect("{[{}]}{()}[]") );
		REQUIRE( isCorrect("[{()}]{[{}]}[]") );
		REQUIRE( isCorrect("{[{()}]}{[{}]}[]") );
		REQUIRE( isCorrect("{[{()}]}{[{}]}[{}]") );
		REQUIRE( isCorrect("[{()}]{[{()}]}[{}]") );
		REQUIRE( isCorrect("{[{()}]}{[{()}]}[{()}]") );
		REQUIRE( isCorrect("{[{()}]}{[{()}]}[{()}]{}[]") );
	}
}

TEST_CASE("isCorrect() recognizes when an expression is incorrect")
{
	
	SECTION("No closing bracket") {
		REQUIRE_FALSE( isCorrect("(abc"));
		REQUIRE_FALSE( isCorrect("a(b") );
		REQUIRE_FALSE( isCorrect("a[b") );
		REQUIRE_FALSE( isCorrect("a{b") );
		REQUIRE_FALSE( isCorrect("a(b[c") );
		REQUIRE_FALSE( isCorrect("a[b{c") );
		REQUIRE_FALSE( isCorrect("a{b(c") );
		REQUIRE_FALSE( isCorrect("a(b[c{d") );
		REQUIRE_FALSE( isCorrect("a[b{c(d") );
		REQUIRE_FALSE( isCorrect("a{b[c(d") );
		REQUIRE_FALSE( isCorrect("a(b[c{d)e") );
	}
	SECTION("No closing bracket and multiple brackets") {
		REQUIRE_FALSE( isCorrect("(((abc))"));
		REQUIRE_FALSE( isCorrect("a(b[c{d)e}]f") );
		REQUIRE_FALSE( isCorrect("a[b{c(d]e}]f") );
		REQUIRE_FALSE( isCorrect("a{b[c(d)e}]f)") );
		REQUIRE_FALSE( isCorrect("a{b[c{d(e]f}]g") );
		REQUIRE_FALSE( isCorrect("a{b[c{d(e)f]g}]h") );
		REQUIRE_FALSE( isCorrect("a{b[c{d(e)f}g]h}i)") );
		REQUIRE_FALSE( isCorrect("abc(def[ghi]jkl)mno)") );
		REQUIRE_FALSE( isCorrect("abc(def{ghi}jkl]mno)") );
		REQUIRE_FALSE( isCorrect("abc[def(ghi]jkl)mno") );
		REQUIRE_FALSE( isCorrect("abc(def[ghi)jkl]mno") );
	}
	
	SECTION("No opening bracket") {
		REQUIRE_FALSE( isCorrect("abc)"));
		REQUIRE_FALSE( isCorrect("a)b") );
		REQUIRE_FALSE( isCorrect("a]b") );
		REQUIRE_FALSE( isCorrect("a}b") );
		REQUIRE_FALSE( isCorrect("a]b{c}") );
		REQUIRE_FALSE( isCorrect("a}b(c)") );
		REQUIRE_FALSE( isCorrect("a)b[c]") );
		REQUIRE_FALSE( isCorrect("a]b{c(d)}") );
		REQUIRE_FALSE( isCorrect("a}b[c{d(e)}]") );
		REQUIRE_FALSE( isCorrect("a)b[c{d(e)}f]") );
		REQUIRE_FALSE( isCorrect("a]b{c[d(e)f]}") );
	}
	SECTION("No opening bracket and mutliple brackets") {
		REQUIRE_FALSE( isCorrect("(abc))"));
		REQUIRE_FALSE( isCorrect("a)b[c{d(e}]f]") );
		REQUIRE_FALSE( isCorrect("a]b{c(d]e}]f") );
		REQUIRE_FALSE( isCorrect("a}b[c(d)e}]f)") );
		REQUIRE_FALSE( isCorrect("a}b[c{d(e]f}]g") );
		REQUIRE_FALSE( isCorrect("a}b[c{d(e)f]g}]h") );
		REQUIRE_FALSE( isCorrect("a}b[c{d(e)f}g]h}i)") );
		REQUIRE_FALSE( isCorrect("abc)def[ghi]jkl)mno") );
		REQUIRE_FALSE( isCorrect("abc]def{ghi}jkl]mno") );
		REQUIRE_FALSE( isCorrect("abc[def)ghi]jkl)mno") );
		REQUIRE_FALSE( isCorrect("abc)def[ghi)jkl]mno") );
	}
	SECTION("Single opening bracket") {
		REQUIRE_FALSE( isCorrect("("));
		REQUIRE_FALSE( isCorrect("a(b") );
		REQUIRE_FALSE( isCorrect("a[b") );
		REQUIRE_FALSE( isCorrect("a{b") );
		REQUIRE_FALSE( isCorrect("a(b[c") );
		REQUIRE_FALSE( isCorrect("a[b{c") );
		REQUIRE_FALSE( isCorrect("a{b(c") );
		REQUIRE_FALSE( isCorrect("a(b[c{d") );
		REQUIRE_FALSE( isCorrect("a[b{c(d") );
		REQUIRE_FALSE( isCorrect("a{b[c(d") );
		REQUIRE_FALSE( isCorrect("a(b[c{d)e") );
	}
	SECTION("Single closing bracket") {
		REQUIRE_FALSE( isCorrect(")"));
		REQUIRE_FALSE( isCorrect("a)b") );
		REQUIRE_FALSE( isCorrect("a]b") );
		REQUIRE_FALSE( isCorrect("a}b") );
		REQUIRE_FALSE( isCorrect("a]b{c}") );
		REQUIRE_FALSE( isCorrect("a}b(c)") );
		REQUIRE_FALSE( isCorrect("a)b[c]") );
		REQUIRE_FALSE( isCorrect("a]b{c(d)}") );
		REQUIRE_FALSE( isCorrect("a}b[c{d(e)}]") );
		REQUIRE_FALSE( isCorrect("a)b[c{d(e)}f]") );
		REQUIRE_FALSE( isCorrect("a]b{c[d(e)f]}") );
	}
	SECTION("Bracket types do not match") {
		REQUIRE_FALSE( isCorrect("{abc]"));
		REQUIRE_FALSE( isCorrect("a(b]c") );
		REQUIRE_FALSE( isCorrect("a[b)c") );
		REQUIRE_FALSE( isCorrect("a{b]c") );
		REQUIRE_FALSE( isCorrect("a)b{c}") );
		REQUIRE_FALSE( isCorrect("a]b(c)") );
		REQUIRE_FALSE( isCorrect("a}b[c]") );
		REQUIRE_FALSE( isCorrect("a]b{c(d)}") );
		REQUIRE_FALSE( isCorrect("a}b[c{d(e)}]") );
		REQUIRE_FALSE( isCorrect("a)b[c{d(e)}f]") );
		REQUIRE_FALSE( isCorrect("a]b{c[d(e)f]}") );
	}
	SECTION("Overlapping bracket sub-expressions") {
		REQUIRE_FALSE( isCorrect("(abcdef[)]"));
		REQUIRE_FALSE( isCorrect("a(b[c{d(e]f}]g") );
		REQUIRE_FALSE( isCorrect("a[b{c(d]e}]f") );
		REQUIRE_FALSE( isCorrect("a{b[c(d)e}]f)") );
		REQUIRE_FALSE( isCorrect("a{b[c{d(e]f}]g") );
		REQUIRE_FALSE( isCorrect("a{b[c{d(e)f]g}]h") );
		REQUIRE_FALSE( isCorrect("a{b[c{d(e)f}g]h}i)") );
		REQUIRE_FALSE( isCorrect("abc(def[ghi]jkl)mno)") );
		REQUIRE_FALSE( isCorrect("abc[def(ghi]jkl)mno") );
		REQUIRE_FALSE( isCorrect("abc[def{ghi]jkl}mno") );
		REQUIRE_FALSE( isCorrect("abc(def[ghi)jkl]mno") );
	}
	SECTION("Wrong direction brackets") {
		REQUIRE_FALSE( isCorrect("{][}"));
		REQUIRE_FALSE( isCorrect("a)b[c]") );
		REQUIRE_FALSE( isCorrect("a]b{c}") );
		REQUIRE_FALSE( isCorrect("a}b(c)") );
		REQUIRE_FALSE( isCorrect("a)b[c{d}]") );
		REQUIRE_FALSE( isCorrect("a]b{c(d)}") );
		REQUIRE_FALSE( isCorrect("a}b[c(d)]") );
		REQUIRE_FALSE( isCorrect("a)b[c{d(e)}]") );
		REQUIRE_FALSE( isCorrect("a]b{c[d(e)}]") );
		REQUIRE_FALSE( isCorrect("a}b[c{d(e)}]") );
		REQUIRE_FALSE( isCorrect("a)b[c{d(e)f}]") );
	}

	
}

TEST_CASE("Edge cases") {
		REQUIRE( isCorrect("") );
		REQUIRE_FALSE( isCorrect("{") );
		REQUIRE_FALSE( isCorrect("}") );
		REQUIRE_FALSE( isCorrect("[") );
		REQUIRE_FALSE( isCorrect("]") );
		REQUIRE_FALSE( isCorrect("[{()}") );
		REQUIRE_FALSE( isCorrect("[{()]") );
		REQUIRE_FALSE( isCorrect("[{(])}]") );
		REQUIRE( isCorrect("[{()}]") );
		REQUIRE_FALSE( isCorrect("[{(]}") );
		REQUIRE_FALSE( isCorrect("[{())}]") );
		REQUIRE( isCorrect("abc[{()}]def") );
		REQUIRE_FALSE( isCorrect("abc[{(]}def") );
		REQUIRE_FALSE( isCorrect("abc[{()]def") );
	}
