#include "String.h"

String::Iterator::Iterator(char* T) {
	this->it = T;
}

String::Iterator::Iterator()
{
	this->it = NULL;
}

char String::Iterator::operator*()
{
	if (*it == NULL) {
		throw std::range_error("it is NULL in: " __FUNCTION__);
	}
	return *it;
}

String::Iterator String::Iterator::operator++()
{
	++it;
	if (*it == NULL) {
		throw std::range_error("range error in: " __FUNCTION__);
	}
	return this->it;
}

String::Iterator String::Iterator::operator--() {
	--it;
	if (*it == NULL) {
		throw std::range_error("range error in: " __FUNCTION__);
	}
	return this->it;
}

bool String::Iterator::operator!=(const Iterator& it)
{
	if (this->it != it.it) {
		return true;
	}
	return false;
}

bool String::Iterator::operator==(const Iterator& it) {

	if (this->it == it.it) {
		return true;
	}
	return false;

}

String::Iterator String::Iterator::operator+(int value)
{
	while (value != 0) {
		++this->it;
		if (*this->it == NULL) {
			throw std::out_of_range("out_of_range in: " __FUNCTION__);
		}
		--value;
	}
	return this->it;
}

