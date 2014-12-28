#ifndef _BINARY_H_
#define _BINARY_H_
#include <iostream>

// CS3424 - 001
// Programming Assignment 1
// Abdul Wahab 

class Binary {
private:
        struct BinaryNode {
                int degree;
                BinaryNode* next;
                BinaryNode(int d, BinaryNode* n): degree(d),next(n) {}
        };
        BinaryNode *firstTerm;
        
public:
        // default constructor
        Binary() {firstTerm = nullptr;}
        
        // constructor
        // takes a value representing a decimal number and creates
        // the binary linked list representation of it.
        Binary(int x);
        
        // sets the term with degree d and bit b
        // notice a node is created if bit is 1 AND a node 
        // for that degree doesn't exist, or the node is removed
        // if the bit is 0 AND the node with that degree already exists
        void set_bit(int b, int d);
        
        // returns one if a term with degree d exists, zero otherwise
        int get_bit(int d) const;
        
        // returns the decimal integer representation of the binary number.
        int convert() const ;
        
        // returns the highest degree of any term in the binary number
        // returns -1 if the the list is empty.
        int get_degree() const;
        
        // destructor
        // make sure that all memory is returned (freed up) correctly
        ~Binary();
        
        // copy constructor
        // creates a new linked list where the contents are a deep copy of the provided list
        Binary(const Binary &b);
        
        // assignment operator
        // sets the current link list to be a deep copy of the provided list.
        // make sure to check if assigning to itself, and make sure to free old memory
        // before making the copy.
        Binary& operator=(const Binary &other); 
        
        // prints the binary number to the output stream o
        // please use like:                10001101
        // terms must be printed in descending order of degree
        friend std::ostream& operator<<(std::ostream &o, const Binary &b);
        
        // returns a new binary number representing the addition of 2 provided binary numbers.
        // do NOT simply convert the numbers to decimal using convert(),add them,
        // then convert back to binary.
        friend Binary operator+(const Binary &b1, const Binary &b2);
        
        // returns a new binary number representing the subtraction 
        // of 2 provided binary numbers. can assume b1 will always be
        // larger than b2.
        // do NOT simply convert the numbers to decimal using convert(),subtract them,
        // then convert back to binary.
        friend Binary operator-(const Binary &b1, const Binary &b2);
        
        // returns a new binary number representing the multiplication
        // of 2 provided binary numbers.
        // do NOT simply convert the numbers to decimal using convert(),multiply them,
        // then convert back to binary.
        friend Binary operator*(const Binary &b1, const Binary &b2);
        
};

std::ostream& operator<<(std::ostream &o, const Binary &b);
                
Binary operator+(const Binary &b1, const Binary &b2);
Binary operator-(const Binary &b1, const Binary &b2);
Binary operator*(const Binary &b1, const Binary &b2);

#endif
