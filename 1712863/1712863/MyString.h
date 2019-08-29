
#ifndef _MYSTRING_
#define _MYSTRING_
#include<iostream>
#include <iterator>
#include<vector>
#include<string.h>
#include <algorithm>
using namespace std;
class MyString
{
private:
	char* str;
	size_t size;
public:
	typedef char*iterator;
	typedef const char*const_iterator;
	typedef std::reverse_iterator<iterator>reverse_iterator;
	typedef std::reverse_iterator<const_iterator>const_reverse_iterator;
	typedef size_t size_type;
	static const size_t npos = -1;

	MyString();
	MyString(const char*exm);
	MyString(const char&);
	MyString(const MyString&);
	MyString(const MyString& str, size_t pos, size_t len);
	MyString(const char* s, size_t n);
	MyString(size_t n, char c);
	MyString(iterator first, iterator last);
	~MyString();
	const MyString& operator = (const MyString& str2);
	const MyString& operator= (const string& str);
	const MyString& operator= (const char* s);
	const MyString& operator= (char c);

	iterator Begin();
	iterator End();
	const_iterator cBegin()const;
	const_iterator cEnd() const;
	reverse_iterator rBegin();
	reverse_iterator rEnd();
	const_reverse_iterator crBegin() const;
	const_reverse_iterator crEnd() const;

	size_t length()const;
	size_t Size()const;
	size_t maxLength()const;
	size_t capacity()const;
	bool Emty();
	void Clear();
	void shrink_to_fit(size_t);
	void reSize(const size_t& value);
	void reSize(size_t n, char c);

	char operator[] (const size_t & index);
	const char& operator[] (size_t index) const;
	char at(size_t& inDex);
	const char& at(size_t inDex) const;
	char font();
	const char& back() const;
	char back();
	const char& front() const;

	const MyString& operator += (const MyString& str2);
	const MyString& operator += (const char* s);
	const MyString& operator += (char c);
	MyString& append(const MyString& str);
	MyString& append(const char* s);
	MyString& append(const MyString& a, const size_t& subpos, const size_t& sublen);
	MyString& append(const char* s, size_t n);
	MyString& append(size_t n, char c);
	MyString& append(iterator first, iterator last);

	MyString& assign(const MyString& str);
	MyString& assign(const MyString& str, size_t subpos, size_t sublen);
	MyString& assign(const char* s);
	MyString& assign(const char* s, size_t n);
	MyString& assign(size_t n, char c);
	MyString& assign(iterator first, iterator last);

	MyString& insert(size_t pos, const MyString& str);
	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen);
	MyString& insert(size_t pos, const char* s);
	MyString& insert(size_t pos, const char* s, size_t n);
	MyString& insert(size_t pos, size_t n, char c);
	void insert(iterator &p, size_t n, char c);
	iterator insert(iterator p, char c);
	void insert(iterator p, iterator first, iterator last);
	MyString& erase(size_t pos, size_t len);
	iterator erase(iterator p);
	iterator erase(iterator first, iterator last);
	MyString& replace(size_t pos, size_t len, const MyString& str);
	MyString& replace(iterator i1, iterator i2, const MyString& str);
	MyString& replace(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen);
	MyString& replace(size_t pos, size_t len, const char* s);
	MyString& replace(iterator i1, iterator i2, const char* s);
	MyString& replace(size_t pos, size_t len, const char* s, size_t n);
	MyString& replace(iterator i1, iterator i2, const char* s, size_t n);
	MyString& replace(size_t pos, size_t len, size_t n, char c);
	MyString& replace(iterator i1, iterator i2, size_t n, char c);
	MyString& replace(iterator i1, iterator i2, iterator first, iterator last);
	void swap(MyString& str);
	void push_back(const char& c);
	void pop_back();

	const char* c_str() const;
	const char* data() const;
	size_t copy(char* s, size_t len, size_t pos) const;
	size_t compare(const MyString& str);
	size_t compare(size_t pos, size_t len, const MyString& str);
	size_t compare(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen);

	size_t find(const char* s, size_t pos, size_type n);
	size_t find(char c, size_t pos);
	size_t rfind(const char* s, size_t pos, size_type n);
	size_t rfind(char c, size_t pos);
	size_t find_first_of(const char* buff, size_t pos, size_t n);
	size_t find_first_of(char c, size_t pos);
	size_t find_last_of(const char* buff, size_t pos, size_t n);
	size_t find_last_of(char c, size_t pos);
	size_t find_first_not_of(const char* buff, size_t pos, size_t n);
	size_t find_first_not_of(char c, size_t pos);
	size_t find_last_not_of(const char* buff, size_t pos, size_t n);
	size_t find_last_not_of(char c, size_t pos);
	MyString substr(size_type pos = 0, size_type len = npos)const;

	const MyString& operator + (const MyString& str2);
	bool MyString::operator==(const MyString& x);
	bool MyString::operator!=(const MyString& x);
	bool MyString::operator>=(const MyString& x);
	bool MyString::operator<(const MyString& x);
	bool MyString::operator<=(const MyString& x);
	bool MyString::operator>(const MyString& x);
	friend ostream& operator<<(ostream&, const MyString& a);
	friend istream& operator>> (istream& is, MyString& s);
	static void getLine(istream& is, MyString& s);
	static void swap(MyString &a, MyString &b);


};

#endif