#pragma once
#include <ostream>
#include <istream>
#include <iostream>

class String
{
public:
	class Iterator
	{
	public:
		Iterator(char *T);
		Iterator();
		virtual char operator*();
		Iterator operator++();
		Iterator operator--();
		bool operator!=(const Iterator&);
		bool operator==(const Iterator&);
		Iterator operator+(int value);
		~Iterator() {}

	private:
		char* it;
	};

	String(const char *str);
	String(char c);
	String(const String& st);
	String();


	int length()const ;
	int length(const char*);
	int to_int();
	void append(const String&);
	void replace(const char c, const int index);
	Iterator begin();
	Iterator end();
	void reverse();
	char back() const;
	char front() const;
	void copy(String&);
	void copy(const char*);
	Iterator find(const Iterator begin, const Iterator end, const char c)const ;

	friend std::ostream& operator<<(std::ostream &os,String&);
	friend std::istream& operator>>(std::istream &is,String&);
	explicit operator int() const;
	explicit operator double() const;
	bool operator<(const String&);
	bool operator>(const String&);
	String& operator+=(String&);
	String operator+(String&);
	bool operator!=(String&);
	bool operator==(String&);
	char& operator[](int index);
	char operator[](int index)const;
	void operator=(const String& st);

	~String();
private:

	String(int, int);
	int strcmp(const String &st1,const String &s2);
	int strLength;
	void set_size_copy(int new_length);
	void set_size(int size);
	char *data;
	void copy_source(const String& st,int idx);
	

};

