#include "minicrt.h"
char *itoa(int n, char *str, int radix)
{
	char digit[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *p = str;
	char *head = str;
	if (!p || radix < 2 || radix > 36)
	{
		return p;
	}

	if (radix != 10 && n < 0)
	{
		return p;
	}

	if (n == 0)
	{
		*p++ = '0';
		*p = 0;
		return p;
	}

	if (radix == 10 && n < 0)
	{
		*p++ = '-';
		n = -n;
	}

	while (n)
	{
		*p++ = digit[n % radix];
		n /= radix;
	}

	*p = 0;
	for (--p; head < p; ++head, --p)
	{
		char temp = *head;
		*head = *p;
		*p = temp;
	}

	return str;
}

int strcmp(const char *src, const char *dst)
{
	int ret = 0;
	unsigned char *p1 = (unsigned char *)src;
	unsigned char *p2 = (unsigned char *)dst;

	while (!(ret = *p1 - *p2) && *p2)
		++p1, ++p2;
	if (ret < 0)
	{
		ret = -1;
	}
	else if (ret > 0)
	{
		ret = 1;
	}

	return (ret);
}

char *strcpy(char *dest, const char *src)
{
	char *ret = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return ret;
}

unsigned strlen(const char *str)
{
	int cnt = 0;
	if (!str)
		return 0;
	for (; *str != '\0'; ++str)
	{
		++cnt;
	}

	return cnt;
}

//string
/*
namespace std {

class string
{
	unsigned len;
	char* pbuf;

public:
	explicit string(const char* str);
	string(const string&);
	~string();
	string& operator=(const string&);
	string& operator=(const char* s);
	const char& operator[](unsigned idx) const;
	char& operator[](unsigned idx);
	const char* c_str() const;
	unsigned length() const;
	unsigned size() const;
};

string::string(const char* str) :
	len(0), pbuf(0)
{
	*this = str;
}

string::string(const string& s):
	len(0), pbuf(0)
{
	*this = s;
}

string::~string()
{
	if(pbuf != 0)
	{
		delete[] pbuf;
		pbuf = 0;
	}
}

string& string::operator=(const string& s)
{
	if(&s == this)
		return *this;
	this->~string();
	len = s.len;
	pbuf = strcpy(new char[len+1], s.pbuf);
	return *this;
}

string& string::operator=(const char* s)
{
	this->~string();
	len = strlen(s);
	pbuf = strcpy(new char[len + 1], s);
	return *this;
}

const char& string::operator[](unsigned idx) const
{
	return pbuf[idx];
}

char& string::operator[](unsigned idx)
{
	return pbuf[idx];
}

const char* string::c_str() const
{
	return pbuf;
}

unsigned string::length() const
{
	return len;
}

unsigned string::size() const
{
	return len;
}

ofstream& operator<<(ofstream& o, const string& s)
{
	return o << s.c_str();
}

}//namespace

*/