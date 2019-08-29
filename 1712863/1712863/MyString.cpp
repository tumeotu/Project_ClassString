#include "MyString.h"

MyString::MyString()
{
	this->size = 0;
	this->str = NULL;
}
MyString::MyString(const char*exm)
{
	this->str = NULL;
	this->size = 0;
	if (exm != NULL)
	{
		this->size = strlen(exm);
		this->str = new char[this->size + 1];//thêm một kí tự để chứa kí tự kết thúc chuỗi.
		strcpy(this->str, exm);
	}
}
MyString::MyString(const char& content)
{
	this->str = NULL;
	this->size = 0;
	if (content != NULL)
	{
		this->size = 1;
		this->str = new char[this->size + 1];
		this->str[0] = content;
		this->str[1] = '\0';//kí tự nhận biết kết thúc của một chuỗi
	}
}
MyString::MyString(const MyString& str2)
{
	this->size = 0;
	this->str = NULL;
	if (str2.str != NULL)
	{
		this->size = str2.size;
		this->str = new char[this->size + 1];
		strcpy(this->str, str2.str);
	}
}
MyString::MyString(const MyString& a, size_t pos, size_t len)
{
	size = len;
	str = new char[size+1];
	size_t j = 0;
	for (size_t i = pos; i < pos + len; i++)
	{
		str[j] = a.at(i);
		j++;
	}
	str[size] = '\0';
}
MyString::MyString(const char* s, size_t n)
{
	size = n;
	str = new char[n + 1];
	for (size_t i = 0; i < n; i++)
		str[i] = s[i];
	str[size] = '\0';
}
MyString::MyString(size_t n, char c)
{
	size = n;
	str = new char[size + 1];
	for (size_t i = 0; i < size; i++)
		str[i] = c;
	str[size] = '\0';
}
MyString::MyString(iterator first, iterator last)
{
	size_t i = 0;
	str = new char;
	for (iterator it = first; it != last; ++it)
	{
		str = (char *)realloc(str,i + 1);
		str[i] = *it;
		i++;
	}
	size = i; 
	str = (char *)realloc(str, size + 1);
	str[size] = '\0';
}
MyString::~MyString()
{
	this->size = NULL;
	delete[]this->str;
}
const MyString& MyString::operator = (const MyString& str2)
{
	//kiểm tra liệu một MyString có được gán bằng chính nó
	if (this != &str2)
	{
		if (this->str != NULL)
			delete this->str;
		if (str2.str != NULL)
		{
			this->size = str2.size;
			this->str = new char[this->size + 1];
			strcpy(this->str, str2.str);
		}
		else
		{
			this->size = 0;
			this->str = NULL;
		}
	}
	return *this;
}
const MyString& MyString::operator= (const char* s)
{
	if (this->str != NULL)
		delete this->str;
	if (s != NULL)
	{
		this->size = strlen(s);
		this->str = new char[this->size + 1];
		strcpy(this->str, s);
	}
	else
	{
		this->size = 0;
		this->str = NULL;
	}
	return *this;
}
const MyString& MyString::operator= (char c)
{
	if (this->str != NULL)
		delete this->str;
	if (c != NULL)
	{
		this->size = 1;
		this->str = new char[this->size + 1];
		str[0] = c;
		str[1] = '\0';
	}
	else
	{
		this->size = 0;
		this->str = NULL;
	}
	return *this;
}

MyString::iterator MyString::Begin()
{
	return str;
}
MyString::iterator MyString::End()
{
	return str+size;
}
MyString::reverse_iterator MyString::rBegin()
{
	return MyString::reverse_iterator(iterator(str+size));
}
MyString::reverse_iterator MyString::rEnd()
{
	return MyString::reverse_iterator(iterator(str));
}
MyString::const_iterator MyString::cBegin()const
{
	return str;
}
MyString::const_iterator MyString::cEnd() const
{
	return str + size;
}
MyString::const_reverse_iterator MyString::crBegin() const
{
	return MyString::const_reverse_iterator(const_iterator(str));
}
MyString::const_reverse_iterator MyString::crEnd() const
{
	return MyString::const_reverse_iterator(const_iterator(str));
}

size_t   MyString::length()const
{
	return strlen(str);
}
size_t   MyString::Size()const
{
	return strlen(str);
}
size_t   MyString::maxLength()const
{
	return 300000;
}
void     MyString::reSize(const size_t& value)
{
	size = value;
	str = (char *)realloc(str, size + 1);
	this->str[size] = '\0';
}
void     MyString::reSize(size_t n, char c)
{
	if (n < size)
	{
		reSize(n);
	}
	else
	{
		str = (char *)realloc(str, n + 1);
		for (size_t i = size; i < n; i++)
			str[i] = c;
		size = n;
		this->str[size] = '\0';
	}
}
size_t   MyString::capacity()const
{
	return strlen(str);
}
bool     MyString::Emty()
{
	if (str == NULL)
		return true;
	return false;
}
void     MyString::Clear()
{
	delete[]this->str;
	this->str = NULL;
}
void     MyString::shrink_to_fit(size_t)
{
	reSize(strlen(str));
}

char  MyString::at(size_t& inDex)
{
	if (inDex >= 0 && inDex < size)
		return str[inDex];
	return NULL;
}
char  MyString::font()
{
	if (this->str != NULL)
		return this->str[0];
	return NULL;
}
char  MyString::back()
{
	if (this->str != NULL)
		return this->str[size - 1];
	return NULL;
}
char  MyString::operator[](const size_t& index)
{
	if (index >= 0 && index < this->size)
		return this->str[index];
	else
		return NULL;
}
const char& MyString::at(size_t inDex) const
{
	if (inDex >= 0 && inDex < size)
		return str[inDex];
	return NULL;
}
const char& MyString::back() const
{
	if (this->str != NULL)
		return this->str[size - 1];
	return NULL;
}
const char& MyString::front() const
{
	if (this->str != NULL)
		return this->str[0];
	return NULL;
}
const char&  MyString::operator[] (size_t index) const
{
	if (index >= 0 && index < this->size)
		return this->str[index];
	else
		return NULL;
}

MyString& MyString::append(const MyString& str2)
{

	char* content = NULL;
	if (this->str == NULL)
	{
		if (str2.str == NULL)
			content = NULL;
		else
		{
			this->size += str2.size;
			this->str = new char[this->size+1];
			strcpy(this->str, str2.str);
		}
	}
	else
	{
		if (str2.str == NULL)
		{
		}
		else
		{
			content = new char[this->size + 1];
			strcpy(content, this->str);
			this->size += str2.size;
			this->str = new char[this->size+1];
			strcpy(this->str, content);
			strcat(this->str, str2.str);
		}
	}
	return *this;
}
MyString& MyString::append(const char* s)
{
	char* content = NULL;
	if (this->str == NULL)
	{
		if (s == NULL)
			content = NULL;
		else
		{
			this->size += 1;
			this->str = new char[this->size + 1];
			strcpy(this->str, s);
		}
	}
	else
	{
		if (s == NULL)
		{
		}
		else
		{
			content = new char[this->size + 1];
			strcpy(content, this->str);
			this->size += 1;
			this->str = new char[this->size + 1];
			strcpy(this->str, content);
			strcat(this->str, s);
		}
	}
	return *this;
}
MyString& MyString::append(const MyString& a, const size_t& subpos,const size_t& sublen)
{
	char* c = new char[size + 1];
	size_t i = 0;
	str = (char *)realloc(str, size + 1 + a.Size());
	for (size_t j = subpos; j < +subpos+sublen; j++)
	{
		str[size+i] = a.at(j);
		i++;
	}
	size = size + a.Size();
	str[size] = '\0';
	return *this;
}
MyString& MyString::append(const char* s, size_t n)
{
	str = (char *)realloc(str, size + n + 1);
	for (size_t i = size; i < size + n; i++)
		str[i] = s[i-size];
	size = size + n;
	str[size] = '\0';
	return *this;
}
MyString& MyString::append(size_t n, char c)
{
	str = (char *)realloc(str, size + n + 1);
	for (size_t i = size; i < size + n; i++)
		str[i] = c;
	size = size + n;
	str[size] = '\0';
	return *this;
}
MyString& MyString::append(iterator first, iterator last)
{
	size_t i = 0;
	for (iterator it = first; it != last; ++it)
	{
		i++;
		str = (char *)realloc(str, size + i + 1);
		str[size + i - 1] = *it;
	}
	size += i;
	str[size] = '\0';
	return *this;
}

MyString& MyString::assign(const MyString& a)
{
	size = a.Size();
	str = new char[a.Size()+1];
	for (int i = 0; i < size; i++)
		str[i] = a[i];
	str[size] = '\0';
	return *this;
}
MyString& MyString::assign(const MyString& a, size_t subpos, size_t sublen)
{
	size = sublen;
	str = new char[size + 1];
	for (int i = subpos; i < subpos+sublen; i++)
		str[i-subpos] = a[i];
	str[size] = '\0';
	return *this;
}
MyString& MyString::assign(const char* s)
{
	size = strlen(s);
	str = new char[size + 1];
	for (int i = 0; i < size; i++)
		str[i] = s[i];
	str[size] = '\0';
	return *this;
}
MyString& MyString::assign(const char* s, size_t n)
{
	size = n;
	str = new char[size + 1];
	for (int i = 0; i < size; i++)
		str[i] = s[i];
	str[size] = '\0';
	return *this;
	return *this;
}
MyString& MyString::assign(size_t n, char c)
{
	size = n;
	str = new char[size + 1];
	for (int i = 0; i < size; i++)
		str[i] = c;
	str[size] = '\0';
	return *this;
}
MyString& MyString::assign(iterator first, iterator last)
{
	delete[]str;
	str = NULL;
	size = 0;
	size_t i = 0;
	for (iterator it = first; it != last; ++it)
	{
		i++;
		str = (char *)realloc(str, size + i + 1);
		str[size + i - 1] = *it;
	}
	size += i;
	str[size] = '\0';
	return *this;
}

MyString& MyString::insert(size_t pos, const MyString& a)
{ 
	char* c = new char[size+1];
	strcpy(c, str);
	str = (char *)realloc(str, size + a.Size() + 1);
	for (int i = pos; i < a.Size() + pos; i++)
		str[i] = a[i-pos];
	for (int i = pos + a.Size(); i < a.Size() + size; i++)
		str[i] = c[i - a.Size()];
	size += a.Size();
	str[size] = '\0';
	return *this;
}
MyString& MyString::insert(size_t pos, const MyString& a, size_t subpos, size_t sublen)
{
	char* c = new char[size+1];
	char*d = new char[sublen + 1];
	for (int i = subpos; i < subpos+sublen; i++)
		d[i-subpos] = a[i];
	d[sublen] = '\0';
	MyString b = d;
	this->insert(pos, b);
	return *this;
}
MyString& MyString::insert(size_t pos, const char* s)
{
	MyString a = s;
	this->insert(pos, a);
	return *this;
}
MyString& MyString::insert(size_t pos, const char* s, size_t n)
{
	MyString a = s;
	this->insert(pos, a, 0, n);
	return *this;
}
MyString& MyString::insert(size_t pos, size_t n, char c)
{
	char*d = new char[n + 1];
	for (int i = 0; i < n; i++)
		d[i] = c;
	d[n] = '\0';
	this->insert(pos, d);
	return *this;
}
void MyString::insert(iterator &p, size_t n, char c)
{
	iterator a = this->Begin();
	int i = 0;
	while (a!=NULL)
	{
		if (a == p)
			break;
		i++;
		++a;
	}
	this->insert(i, n, c);
	p = this->Begin()+i;
}
MyString::iterator MyString::insert(iterator p, char c)
{
	this->insert(p, 1, c);
	return p;
}
void MyString::insert(iterator p, iterator first, iterator last)
{
	iterator a = this->Begin();
	int i = 0;
	while (a != NULL)
	{
		if (a == p)
			break;
		i++;
		++a;
	}
	for (iterator b = first; b != last; ++b)
	{
		this->insert(i, *b);
		i++;
	}
}

MyString& MyString::erase(size_t pos, size_t len)
{
	char* c = new char[size + 1];
	strcpy(c, str);
	str = (char *)realloc(str, size - len + 1);
	for (int i = pos + len; i < size; i++)
		str[i-len ] = c[i];
	size -= len;
	str[size] = '\0';
	return *this;
}
MyString::iterator MyString::erase(iterator p)
{

	iterator a = this->Begin();
	int i = 0;
	while (a != NULL)
	{
		if (a == p)
			break;
		i++;
		++a;
	}
	this->erase(i, 1);
	return str;
}
MyString::iterator MyString::erase(iterator first, iterator last)
{
	iterator a = first; 
	while(a != last)
	{
		this->erase(a);
		last--;
	}
	return str;
}

MyString& MyString::replace(size_t pos, size_t len, const MyString& a)
{
	this->erase(pos, len);
	this->insert(pos, a);
	return *this;
}
MyString& MyString::replace(iterator i1, iterator i2, const MyString& b)
{
	iterator a = this->Begin();
	int i = 0;
	while (a != NULL)
	{
		if (a == i1)
			break;
		i++;
		++a;
	}
	this->erase(i1, i2);
	this->insert(i, b);
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, const MyString& a, size_t subpos, size_t sublen)
{
	char*b = new char[sublen + 1];
	for (int i = 0; i < sublen; i++)
	{
		b[i] = str[subpos + i];
	}
	MyString c = b;
	replace(pos, len, c);
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, const char* s)
{
	MyString b = s;
	this->replace(pos, len, b);
	return *this;
}
MyString& MyString::replace(iterator i1, iterator i2, const char* s)
{
	MyString a = s;
	this->replace(i1, i2, a);
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, const char* s, size_t n)
{
	char* b = new char[strlen(s)];
	for (int i = 0; i < strlen(s) - 1; i++)
		b[i] = s[i];
	b[strlen(s)] = '\0';
	MyString c = b;
	this->replace(pos, len, c);
		return *this;
}
MyString& MyString::replace(iterator i1, iterator i2, const char* s, size_t n)
{
	char* b = new char[strlen(s)];
	for (int i = 0; i < strlen(s) - 1; i++)
		b[i] = s[i];
	b[strlen(s)] = '\0';
	MyString c = b;
	this->replace(i1, i2, c);
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, size_t n, char c)
{
	char* b = new char[n+1];
	for (int i = 0; i < n ; i++)
		b[i] = c;
	b[n] = '\0';
	MyString d = b;
	this->replace(pos, len, d);
	return *this;
}
MyString& MyString::replace(iterator i1, iterator i2, size_t n, char c)
{
	char* b = new char[n + 1];
	for (int i = 0; i < n; i++)
		b[i] = c;
	b[n] = '\0';
	MyString d = b;
	this->replace(i1, i2, d);
	return *this;
}
MyString& MyString::replace(iterator i1, iterator i2, iterator first, iterator last)
{
	char *b = new char;
	int i = 0;
	for (iterator a = first; a != last; ++a)
	{
		i++;
		
		str = (char *)realloc(str, i + 1);
		b[i - 1] = *a;
	}
	b[i] = '\0';
	MyString c = b;
	this->replace(i1, i2, c);
	return *this;
}
void  MyString::swap(MyString& str)
{
	MyString a;
	a = str;
	str = *this;
	*this = a;
}
void  MyString::push_back(const char& c)
{
	size++;
	str = (char *)realloc(str, size + 1);
	this->str[size - 1] = c;
	this->str[size] = '\0';
}
void  MyString::pop_back()
{
	size--;
	str = (char *)realloc(str, size + 1);
	this->str[size] = '\0';
}

const char*  MyString::c_str() const
{
	return str;
}
const char* MyString::data() const
{
	return str;
}
size_t MyString::copy(char* s, size_t len, size_t pos) const
{
	if (pos + len > size)
		len = size - pos;
	else
	{
		for (int i = pos; i < pos + len; i++)
			s[i - pos] = str[i];
	}
	return len;
}
size_t MyString::compare(const MyString& str)
{
	return strcmp(this->c_str(), str.c_str());
}
size_t MyString::compare(size_t pos, size_t len, const MyString& str)
{
	if (pos == 0 && len >= size)
		return compare(str);
	MyString temp = this->substr(pos, len);
	return strcmp(temp.c_str(), str.c_str());
}
size_t MyString::compare(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen)
{
	if (pos == 0 && len >= size && subpos == 0 && sublen >= str.length())
		return compare(str);
	if (subpos == 0 && sublen >= str.length())
		return compare(pos, len, str);
	MyString str1 = this->substr(pos, len);
	MyString str2 = str.substr(subpos, sublen);
	return strcmp(str1.c_str(), str2.c_str());
}

size_t MyString::find(const char* s, size_t pos, size_type n)
{
	this->Begin();
	if (pos > size)
		return npos;
	MyString::iterator it = std::search(this->Begin() + pos, this->End(), s, s + n);
	if (it != this->End())
		return it - Begin();
	return npos;
}
size_t MyString::find(char c, size_t pos)
{
	if (pos > size)
		return npos;
	MyString::iterator it = std::find(this->Begin() + pos, this->End(), c);
	if (it != End())
		return it - Begin();
	return npos;
}
size_t MyString::rfind(const char* s, size_t pos, size_type n)
{
	pos = (pos >= size) ? 0 : size - 1 - pos;
	MyString temp(s, n);
	MyString::reverse_iterator it = std::search(rBegin() + pos, rEnd(), temp.rBegin(), temp.rEnd());
	if (it != rEnd())
		return rEnd() - it - n;
	return npos;
}
size_t MyString::rfind(char c, size_t pos)
{
	pos = (pos >= size) ? 0 : size - 1 - pos;
	for (reverse_iterator it = rBegin() + pos; it != rEnd(); it++)
	{
		if (*it == c)
			return rEnd() - it - 1;
	}
	return npos;
}
size_t MyString::find_first_of(const char* buff, size_t pos, size_t n)
{
	if (pos > size)
		return npos;
	for (iterator i = Begin() + pos; i != End(); i++)
	{
		for (const char* k = buff; k != buff + n; k++)
		{
			if (*i == *k)
				return i - Begin();
		}
	}
	return npos;
}
size_t MyString::find_first_of(char c, size_t pos)
{
	return find(c, pos);
}
size_t MyString::find_last_of(const char* buff, size_t pos, size_t n)
{
	pos = (pos >= size) ? 0 : size - 1 - pos;
	for (reverse_iterator it = rBegin() + pos; it != rEnd(); it++)
	{
		for (const char* k = buff; k != buff + n; k++)
		{
			if (*it == *k)
				return rEnd() - it - 1;
		}
	}
	return npos;
}
size_t MyString::find_last_of(char c, size_t pos)
{
	return rfind(c, pos);
}
size_t MyString::find_first_not_of(const char* buff, size_t pos, size_t n)
{
	if (pos > size)
		return npos;
	MyString cache(buff, n);
	for (iterator i = this->Begin() + pos; i != this->End(); i++)
	{
		if (cache.find_first_of(*i, 0) == npos)
			return i - Begin();
	}
	return npos;
}
size_t MyString::find_first_not_of(char c, size_t pos)
{
	if (pos > size)
		return npos;
	for (iterator i = Begin() + pos; i != End(); i++)
	{
		if (*i != c)
			return i - Begin();
	}
	return npos;
}
size_t MyString::find_last_not_of(const char* buff, size_t pos, size_t n)
{
	pos = (pos >= size) ? 0 : size - 1 - pos;
	MyString cache(buff, n);
	for (reverse_iterator i = rBegin() + pos; i != rEnd(); i++)
	{
		if (cache.find_last_of(*i, 0) == npos)
			return rEnd() - i - 1;
	}
	return npos;
}
size_t MyString::find_last_not_of(char c, size_t pos)
{
	pos = (pos >= size) ? 0 : size - 1 - pos;
	for (reverse_iterator i = rBegin() + pos; i != rEnd(); i++)
	{
		if (*i != c)
			return rEnd() - i - 1;
	}
	return npos;
}
MyString MyString::substr(size_type pos, size_type len) const
{
	return MyString(*this, pos, len);
}
const MyString& MyString::operator += (const MyString& str2)
{
	char* content = NULL;
	if (this->str == NULL)
	{
		if (str2.str == NULL)
			content = NULL;
		else
		{
			this->size += str2.size;
			this->str = new char[this->size + 1];
			strcpy(this->str, str2.str);
		}
	}
	else
	{
		if (str2.str == NULL)
		{
		}
		else
		{
			content = new char[this->size + 1];
			strcpy(content, this->str);
			this->size += str2.size;
			this->str = new char[this->size + 1];
			strcpy(this->str, content);
			strcat(this->str, str2.str);
		}
	}
	return this->str;
}
const MyString& MyString::operator += (const char* s)
{
	char* content = NULL;
	if (this->str == NULL)
	{
		if (s == NULL)
			content = NULL;
		else
		{
			this->size += strlen(s);
			this->str = new char[this->size + 1];
			strcpy(this->str, s);
		}
	}
	else
	{
		if (s == NULL)
		{
		}
		else
		{
			content = new char[this->size + 1];
			strcpy(content, this->str);
			this->size += strlen(s);
			this->str = new char[this->size + 1];
			strcpy(this->str, content);
			strcat(this->str, s);
		}
	}
	return this->str;
}
const MyString& MyString::operator += (char c)
{
	char* content = NULL;
	if (this->str == NULL)
	{
		if (c == NULL)
			content = NULL;
		else
		{
			this->size += 1;
			this->str = new char[this->size + 1];
			str[size-1] = c;
			str[size] = '\0';
		}
	}
	else
	{
		if (c == NULL)
		{
		}
		else
		{
			content = new char[this->size + 1];
			strcpy(content, this->str);
			this->size += 1;
			this->str = new char[this->size + 1];
			strcpy(this->str, content);
			str[size - 1] = c;
			str[size] = '\0';
		}
	}
	return this->str;
}

void  MyString::getLine(istream& is, MyString& s)
{
	s.str = new char[300000];
	is.getline(s.str, 300000, '\n');
	s.reSize(s.length());
}
const MyString& MyString::operator + (const MyString& str2)
{
	char* content = NULL;
	if (this->str == NULL)
	{
		if (str2.str == NULL)
			content = NULL;
		else
		{
			this->size += str2.length();
			this->str = new char[this->size + 1];
			strcpy(content, str2.str);
		}
	}
	else
	{
		if (str2.str == NULL)
		{
			content = new char[this->size + 1];
			strcpy(content, this->str);
		}
		else
		{
			this->size += str2.length();
			content = new char[this->size + 1];
			strcpy(content, this->str);
			strcat(content, str2.str);
		}
	}
	return MyString(content);
}
bool  MyString::operator==(const MyString& x)
{
	for (size_t i = 0; i < x.size; i++)
	if (this->str[i] != x.str[i])
		return false;
	return true;
}
bool  MyString::operator!=(const MyString& x)
{
	return !operator==(x);
}
bool  MyString::operator>=(const MyString& x)
{
	for (size_t i = 0; i<x.size; i++)
	if (this->str[i] < x.str[i])
		return false;
	return true;
}
bool  MyString::operator<(const MyString& x)
{
	return !operator>=(x);
}
bool  MyString::operator<=(const MyString& x)
{
	for (size_t i = 0; i<x.size; i++)
	if (this->str[i] > x.str[i])
		return false;
	return true;
}
bool  MyString::operator>(const MyString& x)
{
	return !operator<=(x);
}
ostream& operator<<(ostream& os, const MyString& a)
{
	os << a.str;
	return os;
}
istream& operator>> (istream& is, MyString& s)
{
	s.str = new char[300000];
	is.getline(s.str, 300000, ' ');
	s.reSize(s.length());
	return is;
};
void MyString::swap(MyString &a, MyString &b)
{
	MyString c;
	c = b;
	b = a;
	a = c;
}