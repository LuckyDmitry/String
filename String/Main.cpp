#include "String.h"
#include <iostream>
#include <cassert>
#include <string>

using namespace std;


class Test
{
public:

	void test_plus(String& s1,String& s2,string &expected) {
		s1 = s1 + s2;
		assert(s1.length() == expected.length());
		assert(get_string(s1) == expected);
	}
	void test_equal_plus(String& s1, String& s2, string& expected) {
		s1 += s2;
		assert(get_string(s1) == expected);
	}
	void test_reverse(String& s1, string& expected) {
		s1.reverse();
		assert(get_string(s1) == expected);
	}

	string get_string(String& st) {
		string s = "";
		for (size_t i = 0; i != st.length();++i){
			s += st[i];
		}
		return s;
	}

private:

};


int main() {


	String a = "aa";
	String b = "bb";
	string result = "aa";
	Test test;
	test.test_reverse(a, result);
	String s = "123F";
	try {
		String::Iterator it = s.begin();
		cout << *(it + 4);

	}
	catch (std::exception & ex) {
		cout << ex.what();
	}

	return 0;

}