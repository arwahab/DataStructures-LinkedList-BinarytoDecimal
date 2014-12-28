#include <algorithm>
#include <iostream>
#include <string>
#include "binary.h"

// CS3424 - 001
// Programming Assignment 1
// Abdul Wahab 

Binary::Binary(int x) {
firstTerm = nullptr;

while (x > 0) {
unsigned int degree = (unsigned int) (log(float(x)) / log(float(2)));
set_bit(1, degree);
x -= (int) pow(float(2), float(degree));
}
}
Binary::~Binary() {  
BinaryNode *first = firstTerm;

while (first != nullptr) {
BinaryNode *tempBinary = first->next;
delete first;
first = tempBinary;
}
firstTerm = nullptr;
}

void Binary::set_bit(int bit, int degree) {			
	BinaryNode *setCurrentDel, *currSetAdd, *target;
	setCurrentDel = firstTerm;
	
if (bit == 0 && get_bit(degree)) {
		
if (setCurrentDel->degree == degree) {
			
firstTerm = setCurrentDel->next;
delete setCurrentDel;
			
}
else {
target = setCurrentDel;
			
while (setCurrentDel != nullptr) {
				
if (setCurrentDel->degree == degree) {
					
target->next = setCurrentDel->next;
					
setCurrentDel = nullptr;
delete setCurrentDel;
					
}
else {
					
target = setCurrentDel;
setCurrentDel = setCurrentDel->next;
					
}}}}

else if (bit == 1 && get_bit(degree) == 0) {
if (firstTerm == nullptr) {
firstTerm = new BinaryNode(degree, nullptr);
}
else if (firstTerm->degree < degree) {
firstTerm = new BinaryNode(degree, firstTerm);
			
		
}else {
currSetAdd = firstTerm;
while (currSetAdd->next != nullptr) {
if (currSetAdd->next->degree < degree) {
currSetAdd = new BinaryNode(degree, currSetAdd->next);
}
				
currSetAdd = currSetAdd->next;
}
currSetAdd->next = new BinaryNode(degree, nullptr);
}
}
}

int Binary::get_bit(int degree) const {      
BinaryNode *getCurrent = firstTerm;
while (getCurrent != nullptr) {
if (getCurrent->degree == degree) {
return 1;
}
getCurrent = getCurrent->next;
}
return 0;
}

int Binary::convert() const {
	if (firstTerm == nullptr) {
		return -1;
}else {
int decimal = 0;
BinaryNode *setCurrent = firstTerm;
int degreeLink = setCurrent->degree;
int power = 1;
while (setCurrent != nullptr) {
degreeLink = setCurrent->degree;
while (degreeLink > 0) {
power *= 2;
degreeLink--;
}
if (setCurrent->degree == 0) {
decimal++;
				degreeLink--;
				setCurrent = setCurrent->next;
			}
			else if (setCurrent->degree != 0) {
				decimal += power;
				power = 1;
				setCurrent = setCurrent->next;
			}
		}
		return decimal;
	}
}

int Binary::get_degree() const {   //
	if (firstTerm != nullptr) {
		return firstTerm->degree;
	}
	return -1;
}

Binary::Binary(const Binary &b) {     
	if (b.firstTerm == nullptr) {
		firstTerm = nullptr;
	}
	else {
		firstTerm = new BinaryNode(b.firstTerm->degree, nullptr);
		BinaryNode *copy = firstTerm;
		BinaryNode *curr = b.firstTerm->next;
		while (curr != nullptr) {
			copy->next = new BinaryNode(curr->degree, nullptr);
			copy = copy->next;
			curr = curr->next;
		}
	}
}

Binary& Binary::operator=(const Binary &other) {  
	if (this == &other) {
		return *this;
	}
	else {
		Binary::~Binary();
		
	
		if (other.firstTerm == nullptr) {
			firstTerm = nullptr;
		}
		else {
			firstTerm = new BinaryNode(other.firstTerm->degree, nullptr);
			BinaryNode *copy = firstTerm;
			BinaryNode *curr = other.firstTerm->next;
			while (curr != nullptr) {
				copy->next = new BinaryNode(curr->degree, nullptr);
				copy = copy->next;
				curr = curr->next;
			}
		}
		return *this;
	}
}

std::ostream& operator<<(std::ostream &o, const Binary &b) {   
	if (!b.get_degree()) {
		o << 0;
		return o;
	}
	int bits = b.get_degree();
	std::string bitString = "";
	for (bits; bits >= 0; bits--) {
		if (b.get_bit(bits)) {
			bitString.append("1");
		}
		else {
			bitString.append("0");
		}
	}
	o << bitString;
	return o;
}

Binary operator+(const Binary &b1, const Binary &b2) {    
Binary newBinary = Binary();
unsigned int iMax = std::max(b1.get_degree(), b2.get_degree());

	
	unsigned int carriedBit = 0;

	
	for (unsigned int i = 0; i <= iMax; ++i)
	{
		unsigned int sum = b1.get_bit(i) + b2.get_bit(i) + carriedBit;

		
		if (sum >= 2)
		{
			carriedBit = 1;
			sum -= 2;
		}
		else
		{
			carriedBit = 0;
		}

		if (1 == sum)
		{
			newBinary.set_bit(1, i);
		}
	}

	
	if (1 == carriedBit)
	{
		newBinary.set_bit(1, iMax + 1);
	}
return newBinary;
}
Binary operator-(const Binary &b1, const Binary &b2)  {    
	Binary newBinary = Binary();
	Binary one = Binary();
	one.set_bit(1, 0);
	Binary negate = Binary();
	int bits = std::max(b1.get_degree(), b2.get_degree());
	for (int i = 0; i <= bits; ++i) {
		if (b2.get_bit(i)) {
			negate.set_bit(0, i);
		}
		else if (!b2.get_bit(i)) {
			negate.set_bit(1, i);
		}
	}
	negate = operator+(negate, one);
	newBinary = operator+(b1, negate);
	if (newBinary.get_degree() > std::max(negate.get_degree(), b1.get_degree())) {
		newBinary.set_bit(0, newBinary.get_degree());
	}
	return newBinary;
}

Binary operator*(const Binary& b1, const Binary& b2) {     // Done by: Tony Dang
	Binary tempBinary = Binary();
	Binary sum = Binary();
	int bits2 = b2.get_degree();
	int bits1 = b1.get_degree();
	for (int outer = 0; outer <= bits2; ++outer) {
		for (int inner = 0; inner <= bits1; ++inner) {
			if (b2.get_bit(outer)) {
				if (b1.get_bit(inner)) {
					sum.set_bit(1, inner+outer);
				}
			}
		}
		tempBinary = tempBinary + sum;
		sum = 0;
	}
	return tempBinary;
}
