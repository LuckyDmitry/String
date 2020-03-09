#include "String.h"

String::String() {
	data = nullptr;
	strLength = NULL;
}

String::String(int a, int b) {

	this->data = new char[a + b + 1];
	this->strLength = a + b;
}

String::String(const char* str){

	this->strLength = strlen(str);
	int i = 0;
	
	set_size(strLength);
	while (*str != '\0') {
		*(this->data +i)= *str;
		++i;
		++str;
	}
	*(this->data + i) = '\0';
}

String::String(const String& st) {
	set_size(st.strLength);
	copy_source(st,0);
}

int String::length() const
{
	int count = 0;
	int i = 0;
	if (this->strLength != NULL) {
		return this->strLength;
	}

	while (this->data[i] != '\0') {
		++count;
		++i;
	}
	return count;
}

int String::to_int()
{
	int value = 0;;
	int i = 0;
	while (data[i]!= '\0') {
		if (data[i] >= '1' && data[i] <= '9') {
			value = 10 * value + data[i] - '0';
			++i;
		}
		else {
			throw std::logic_error("excepted int value in: " __FUNCTION__);
		}
	}

	return value;
}

String::Iterator String::begin()
{
	Iterator it(this->data);
	return it;
}

String::Iterator String::end() {
	Iterator it((this->data +this->strLength -1 ));
	return it;
}

char& String::operator[](int index)
{
	if (index >= strLength) {
		throw std::logic_error("excepted less value in: " __FUNCTION__ );
	}
	return *(this->data + index);
	
}

char String::operator[](int index) const
{
	return *(this->data+index);
}

void String::append(const String& st) 
{
	if (st.strLength == 0) {
		throw std::exception("Error in: " __FUNCTION__);
	}
	int i = 0;
	int curr_length = this->strLength;
	set_size_copy(st.strLength);
	while (st[i] != '\0'){
		this->data[curr_length] = st[i];
		++i;
		++curr_length;
	}
	this->data[curr_length] = '\0';
}

int String::length(const char* str)
{
	int count = 0;
	while (*str != '\0') {
		++count;
		++str;
	}
	strLength = count;
	return count;
}

int String::strcmp(const String& st1,const String& st2)
{
	int i = 0;
	while (*(st1.data +i) == *(st2.data +i) &&
		*(st1.data +i) != '\0') {
		++i;
	}
	return *(st1.data +i) - *(st2.data + i);
}

void String::set_size_copy(int new_length)
{
	int old_length = this->strLength;
	char* old_data = new char[old_length];
	int i = 0;
	while (this->data[i] != '\0') {
		old_data[i] = this->data[i];
		++i;
	}
	old_data[i] = '\0';
	set_size(old_length + new_length);

	i = 0;
	while (*old_data != '\0') {
		this->data[i] = *old_data;
		++i;
		++old_data;
	}
}

void String::reverse() {

	for (size_t i = 0, j = strLength - 1; i != strLength / 2; ++i, --j)
	{
		std::swap(this->data[i], this->data[j]);
	}
}

char String::back() const {
	return this->data[strLength - 1];
}

char String::front()const {
	return *this->data;
}

void String::copy(String& str) {

	int i = 0;

	set_size(str.strLength);
	this->strLength = str.length();
	while (i != str.strLength) {
		this->data[i] = str.data[i];
		++i;
	}
	this->data[i] = '\0';
}	  //PRIVATE METHOD

void String::copy(const char* str) {

	this->strLength = length(str);
	set_size(this->strLength);
	int i = 0;
	while (str[i] != '\0') {
		this->data[i] = str[i];
		++i;
	}
	this->data[i] = '\0';
}

void String::replace(const char c, const int index) {

	if (index >= strLength) {
		throw std::out_of_range("expected less value in: " __FUNCTION__);
	}

	size_t i = 0;
	for (; i != this->strLength; ++i) {
		if (i == index) {
			this->data[i] = c;
		}
	}
}

String::Iterator String::find(const Iterator begin, const Iterator end, const char c) const
{
	String::Iterator it;
	it = begin;
	while (it != end) {
		if (*it == c) {
			return it;
		}
		++it;
	}
	throw std::exception("Don't exist in: " __FUNCTION__);
}

void String::copy_source(const String& st, int index) {

	int i = index ;
	while (i != st.strLength) {
		this->data[i] = st.data[i];
		++i;
	}
	this->data[i] = '\0';
}

String::operator int() const
{
	String a(this->data);
	return a.to_int();
}

String::operator double()const 
{
	return 1.0;

}

bool String::operator<(const String& st1)
{
	return (this->strcmp(*this, st1) < 0);
}

bool String::operator>(const String& st) {
	return !(this->operator<(st));
}

String& String::operator+=(String& st)
{
	this->append(st);
	return *this;
}

String String::operator+(String& st) {

	return (this->operator+=(st));
}

bool String::operator==(String& st)
{
	if (this->strLength != st.strLength) {
		return false;
	}
	int i = 0;
	while (i != strLength) {
		if (this->data[i] != st.data[i]) {
			return false;
		}
		++i;
	}
	return true;
}

bool String::operator!=(String& st) {

	return !(this->operator==(st));
}

std::ostream& operator<<(std::ostream& os,String &str)
{
	int i = 0;
	while (*(str.data +i) != '\0') {
		std::cout << *(str.data +i);
		++i;
	}
	return os;
}

std::istream& operator>>(std::istream &is, String& str)
{
	char c[1024];
	is.getline(c, 1024);
	str = String(c);

	return is;
}

void String::set_size(int size) {

	this->data = new char[size + 1];
	this->strLength = size;
}

void String::operator=(const String& st) {

	this->strLength = st.strLength;

	if (this->data != nullptr) {
		delete[] this->data;
	}
	set_size(strLength);
	copy_source(st,0);

}

String::~String()
{
	delete[] this->data;
}
