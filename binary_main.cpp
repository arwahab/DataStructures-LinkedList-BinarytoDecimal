#include <iostream>
#include "binary.h"

// CS3424 - 001
// Programming Assignment 1
// Abdul Wahab & Tony Dang

using namespace std;

int main (void)
{
        // test default constructor
        Binary b1;
        cout << "TESTING DEFAULT CONSTRUCTOR" << endl;
        if (b1.get_degree() == -1)
                cout << "\tThe binary number b1 is empty." << endl;
        else
                cout << "\tThe binary number b1 is NOT empty. (INCORRECT)" << endl;
        
        // test get_bit, set_bit, and get_degree
        cout << "\nTESTING GET AND SET METHODS" << endl;
        b1.set_bit(1, 2);
        b1.set_bit(1, 5);
        b1.set_bit(1, 0);
        b1.set_bit(0, 2);

        if (b1.get_degree() == 5)
                cout << "\tThe highest bit of binary number b1 is 5." << endl;
        else
                cout << "\tThe highest bit of binary number b1 is NOT 5. (INCORRECT)" << endl;
        if (b1.get_bit(5) == 1)
                cout << "\tThe bit of binary number b1 at degree 5 is 1." << endl;
        else
                cout << "\tThe bit of binary number b1 at degree 5 is 0. (INCORRECT)" << endl;
        if (b1.get_bit(2) == 0)
                cout << "\tThe bit of binary number b1 at degree 2 is 0." << endl;
        else
                cout << "\tThe bit of binary number b1 at degree 2 is 1. (INCORRECT)" << endl;
        if (b1.get_bit(1) == 0)
                cout << "\tThe bit of binary number b1 at degree 1 is 0." << endl;
        else
                cout << "\tThe bit of binary number b1 at degree 1 is 1. (INCORRECT)" << endl;
        
        // test parameter constructor
        cout << "\nTESTING PARAMETER CONSTRUCTOR" << endl;
        Binary b2(5);
        
        if (b2.get_bit(2) == 1)
                cout << "\tThe bit of binary number b2 at degree 2 is 1." << endl;
        else
                cout << "\tThe bit of binary number b2 at degree 2 is 0. (INCORRECT)" << endl;
        if (b2.get_bit(0) == 1)
                cout << "\tThe bit of binary number b2 at degree 0 is 1." << endl;
        else
                cout << "\tThe bit of binary number b2 at degree 0 is 0. (INCORRECT)" << endl;
        if (b2.get_bit(1) == 0)
                cout << "\tThe bit of binary number b2 at degree 1 is 0." << endl;
        else
                cout << "\tThe bit of binary number b2 at degree 1 is 1. (INCORRECT)" << endl;

        // test copy constructor
        cout << "\nTESTING COPY CONSTRUCTOR" << endl;
        Binary b3(b2);
        b2.set_bit(1, 1);

        if (b3.get_bit(2) == 1)
                cout << "\tThe bit of binary number b3 at degree 2 is 1." << endl;
        else
                cout << "\tThe bit of binary number b3 at degree 2 is 0. (INCORRECT)" << endl;
        if (b3.get_bit(0) == 1)
                cout << "\tThe bit of binary number b3 at degree 0 is 1." << endl;
        else
                cout << "\tThe bit of binary number b3 at degree 0 is 0. (INCORRECT)" << endl;
        if (b3.get_bit(1) == 0)
                cout << "\tThe bit of binary number b3 at degree 1 is 0." << endl;
        else
                cout << "\tThe bit of binary number b3 at degree 1 is 1. (INCORRECT)" << endl;

        // test assignment operator
        cout << "\nTESTING ASSIGNMENT OPERATOR" << endl;
        b2 = b3;
        b3.set_bit(1, 1);
        
        if (b2.get_bit(2) == 1)
                cout << "\tThe bit of binary number b2 at degree 2 is 1." << endl;
        else
                cout << "\tThe bit of binary number b2 at degree 2 is 0. (INCORRECT)" << endl;
        if (b2.get_bit(0) == 1)
                cout << "\tThe bit of binary number b2 at degree 0 is 1." << endl;
        else
                cout << "\tThe bit of binary number b2 at degree 0 is 0. (INCORRECT)" << endl;
        if (b2.get_bit(1) == 0)
                cout << "\tThe bit of binary number b2 at degree 1 is 0." << endl;
        else
                cout << "\tThe bit of binary number b2 at degree 1 is 1. (INCORRECT)" << endl;
                

        // test convert
        cout << "\nTESTING CONVERT METHOD" << endl;
        if (b1.convert() == 33)
                cout << "\tThe decimal value of binary number b1 is 33." << endl;
        else
                cout << "\tThe decimal value of binary number b1 is NOT 33. (INCORRECT)" << " decimal is " << b1.convert() << " binary is " << b1 << endl;
                
        // test output operator
        cout << "\nTESTING OUTPUT OPERATOR" << endl;
        cout << "\tThe binary number b1 is " << b1 << endl;
        cout << "\tThe number b1 should be 100001" << endl;
        
        // test addition
        cout << "\nTESTING ADDITION OPERATOR" << endl;
        Binary b4 = b2 + b3;
        
        if (b4.convert() == 12)
                cout << "\t101 + 111 = 1100." << endl;
        else
                cout << "\t101 + 111 != 1100. (INCORRECT)" << " b4 is in decimal " <<b4.convert() << " b4 is in binary " << b4 << endl;
        
        // test subtraction
        cout << "\nTESTING SUBTRACTION OPERATOR" << endl;
        Binary b5(b1 - b2);

        if (b5.convert() == 28)
                cout << "\t100001 - 101 = 11100." << endl;
        else
                cout << "\t100001 - 101 != 11100. (INCORRECT)" << endl;
        
        // test multiplication
        cout << "\nTESTING MULTIPLICATION OPERATOR" << endl;
        Binary b6 = b3 * b2;
        cout << "b6 binary is " << b6 << " b6 decimal is " << b6.convert() << endl;
        
        if (b6.convert() == 35)
                cout << "\t111 * 101 = 100011." << endl;
        else
                cout << "\t111 * 101 != 100011. (INCORRECT)" << endl;
        
        system("pause");
}
