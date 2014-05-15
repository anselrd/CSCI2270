// FILENAME: BigNum.cxx
// This is the implementation file of the BigNum class


#ifndef HW3_BIGNUM_CXX
#define HW3_BIGNUM_CXX
#include <algorithm>   // Provides copy function
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include "BigNum.h"
using namespace std;

namespace HW3
{
	BigNum::BigNum()
	{
		capacity = DEFAULT_CAPACITY;
		used = 1;
		digits = new unsigned int[capacity];
		digits[0] = 0;
		positive = true;
	}    

	BigNum::BigNum(int num)
	{
		capacity = DEFAULT_CAPACITY;
		digits = new unsigned int[capacity];
		if (num >= 0 ){
			 positive = true;
		}
		else{
			positive = false;
			num *= -1;
		}
		for (unsigned int i = 0; i < DEFAULT_CAPACITY; i++){
			digits[i] = num % 10;
			num /= 10;
		}
		used = 1; //there is at least one slot in use
		for (unsigned int i = (DEFAULT_CAPACITY - 1); i > 0; i--){
			//scan backwards until a non-zero number is found in order to determine
			//the value of the 'used' variable. if num == 0, the loop will not break but
			//used will already be 1.
			if (digits[i] != 0){
				used = (i + 1);
				break;
			}
		
		}
	}
/*
	// Constructor that receives a string; leading 0's will be ignored
	BigNum::BigNum(const string& strin)
	{
		//if the input string is invalid, my constructor will set used to zero so the bignum essentially does not
		//exist, however it still exists in memory (no call to delete [] digits) so it can be reassigned later
		capacity = (unsigned) (int) strin.length();
		digits = new unsigned int[capacity * 2];//we will adjust capacity later
		positive = true;
		if (strin[0] == '-')
			positive = false;
		int strtpt = -1; //the starting point of the number in the input string
								  //initailized to -1 for a later check (line 74)
		
		for (unsigned int i = 0; i < capacity; i++){
			if (strin[i] <= 57 && strin[i] > 48){ //search for the beginning of the real number (nubmers are ASCII)
				strtpt = i;
				break;
			}
		}
		if (strtpt == -1){ //if the loop has executed without finding a non-zero integer, the argument is zero
			strtpt = capacity - 1; //last position in the input string
		}
		used = capacity - (unsigned) strtpt;
		for (unsigned int i = 0; i < used; i++){
			if (strin[(capacity - 1) - i] < 48 || strin[(capacity - 1) - i] > 57){
				//if the string contains anything but integers (excluding the '-' sign), set used to zero
				used = 0;
				break;
			} 
				digits[i] = strin[(capacity - 1) - i] - 48;
		}
		capacity *= 2;
	}*/
 
    BigNum::BigNum(const BigNum& anotherBigNum)
    {
		capacity = anotherBigNum.capacity;
		used = anotherBigNum.used;
		positive = anotherBigNum.positive;
		digits = new unsigned int[capacity];
		for (unsigned int i = 0; i < used; i++)
		{
			digits[i] = anotherBigNum.digits[i];
		}
    }

    BigNum::~BigNum()
    {
		delete [] digits;
    }
    
    void BigNum::resize(unsigned int n)
	{
		if (n <= capacity) return;
		BigNum temp = *this;
		delete [] digits;
		capacity = n;
		digits = new unsigned int[capacity];
		for (unsigned int i = 0; i < used; i++)
		{
			digits[i] = temp.digits[i];
		}
	}

	BigNum& BigNum::operator=(const BigNum& anotherBigNum)
	{
		if (this != &anotherBigNum){
			delete [] digits;
			this->capacity = anotherBigNum.used * 2;
			digits = new unsigned int[capacity];
			this->used = anotherBigNum.used;
			for (unsigned int i = 0; i < used; i++)
			{
				digits[i] = anotherBigNum.digits[i];
			}
			positive = anotherBigNum.positive;
		}
		return *this;
	}
	/*
	BigNum::BigNum()
	{
		capacity = DEFAULT_CAPACITY;
		digits = new unsigned int[capacity]; 
		digits[0] = 0;
		positive = true;      
		used = 1;
	}    

	BigNum::BigNum(int num)
	{
		digits = nullptr;

		if (num == 0) 
		{
			BigNum zero;
			*this = zero;
		}
    
		else 
		{
			if (num > 0) 
			{
				positive = true;
			}
			else 
			{
				positive = false;
				num = -num;
			}
      
			unsigned int i = 0, temp = num;
      
			// count the digits
			while (temp > 0) 
			{
				temp = temp/10; 
				i++;
			}

			capacity = i; 
		
			digits = new unsigned int[capacity];

			temp = num;
		
			for (used = 0; used < i; ++used) 
			{
				digits[used] = temp % 10;
				temp /= 10;
			}
		}
	}
*/
	// Constructor that receives a string; leading 0's will be ignored
	BigNum::BigNum(const string& strin)
	{
		digits = nullptr;
		
		int len = strin.length();
		
		if (len == 0)
		{
			BigNum zero;
			*this = zero;
			return;
		}

		used = len;
		positive = true;
		
		int i = 0;

		if(strin[i] == '-')  
		{
			positive = false;
			i = 1;
			used--;
		}
		else if(strin[i] == '+')  
		{
			i = 1;
			used--;
		}
		
		capacity = used;
	
		digits = new unsigned int[capacity];

		for(unsigned int k = 0; k < used; ++k) 
		{
			digits[used - k - 1] = strin[i++] - '0';
		}
		
		if (used == 1 && digits[0] == 0)
			positive = true;
			
		trim();
	}/*
 
    BigNum::BigNum(const BigNum& anotherBigNum)
    {
		digits = nullptr;
		
		// makes operator = do the work; use that function if you use this
		*this = anotherBigNum;
    }

    BigNum::~BigNum()
    {
		delete [] digits;
    }
        
    // assume doubling is done before passing in n
	void BigNum::resize(unsigned int n)
	{
		unsigned int *largerArray;

		if (n < used) return; // Can't allocate less than we are using

		capacity = n;
		largerArray = new unsigned int[capacity];
		
		copy(digits, digits + used, largerArray);
		
		delete [] digits;
		digits = largerArray;
	}

	BigNum& BigNum::operator=(const BigNum& anotherBigNum)
	{
		if (this == &anotherBigNum)  return *this;
		
		if (digits != nullptr)
			delete [] digits;
			
		capacity = anotherBigNum.capacity;
		digits = new unsigned int[capacity];
		
		positive = anotherBigNum.positive;
		used = anotherBigNum.used;
		copy(anotherBigNum.digits, anotherBigNum.digits + used, digits);
  
		return *this;
	}*/
  
	BigNum& BigNum::operator+=(const BigNum& addend)  
	{
		BigNum temp = BigNum(*this);
		*this = temp + addend;
		return *this;
	}

	BigNum& BigNum::operator-=(const BigNum& subtractand)
	{
		*this = *this - subtractand;
		return *this;
	}

	BigNum& BigNum::operator*=(const BigNum& multiplicand)
	{
		*this = *this * multiplicand;
		return *this;
	}

	BigNum& BigNum::operator/=(const BigNum& divisor)
	{
		*this = *this / divisor;
		return *this;
	}

	BigNum& BigNum::operator%=(const BigNum& divisor)
	{
		*this = *this % divisor;
		return *this;
	}

	BigNum& BigNum::operator++()
	{
		BigNum one = 1;
		*this = *this + one;
		return *this;
	}

	BigNum& BigNum::operator--()
	{
		BigNum one = 1;
		*this = *this - one;
		return *this;
	}

	BigNum& BigNum::diff(const BigNum& a, const BigNum& b)
	{
		return *this;
	}
  

	BigNum& BigNum::mult(const BigNum& a, const BigNum& b)
	{
		return *this;
	}
	
	BigNum& BigNum::sum(const BigNum& a, const BigNum& b) 
	{
		return *this;
	}

	BigNum operator+(const BigNum& a, const BigNum& b)
	{
		BigNum result;
		BigNum aCopy = a;
		BigNum bCopy = b;
		int remainder = 0;
		if ((a.positive && b.positive) || (!a.positive && !b.positive)){
			if (a.positive) result.positive = true;
			else result.positive = false;
			if (a.used >= b.used){
				//for easy addition, make bignums with different amounts of digits
				//filled with leading zeros (e.g. 7 + 100 -> 007 + 100)
				result.resize(a.used * 2);
				result.used = a.used + 1;
				for (unsigned int i = 0; i < result.used; i++)
					result.digits[i] = 0; //fill with zeros for easy trimming
				bCopy.resize(a.used + 1);
				bCopy.used = a.used;
				for (unsigned int i = b.used; i < a.used; i++){
					bCopy.digits[i] = 0;
				}
				for (unsigned int i = 0; i < a.used; i++){
					result.digits[i] = ((a.digits[i] + bCopy.digits[i] + remainder) % 10);
					if ((a.digits[i] + bCopy.digits[i] + remainder) > 9){
						remainder = 1;
					}else{
						remainder = 0;
					}
				}
				if (remainder == 1){
					result.digits[a.used] = 1;
				}else{
					result.used -= 1;
				}
			}
			if (b.used > a.used){
				//for easy addition, make bignums with different amounts of digits
				//filled with leading zeros (e.g. 7 + 100 -> 007 + 100)
				result.resize(b.used * 2);
				result.used = b.used + 1;
				for (unsigned int i = 0; i < result.used; i++)
					result.digits[i] = 0;
				aCopy.resize(b.used + 1);
				aCopy.used = b.used;
				for (unsigned int i = a.used; i < b.used; i++){
					aCopy.digits[i] = 0;
				}
				for (unsigned int i = 0; i < b.used; i++){
					result.digits[i] = ((aCopy.digits[i] + b.digits[i] + remainder) % 10);
					if ((aCopy.digits[i] + b.digits[i] + remainder) > 9){
						remainder = 1;
					}else{
						remainder = 0;
					}
				}
				if (remainder == 1){
					result.digits[b.used] = 1;
				}else{
					result.used -= 1;
				}
			}
		}
		if (a.positive && !b.positive){
			bCopy.positive = true;
			result = aCopy - bCopy;
		}
		if (!a.positive && b.positive){
			aCopy.positive = true;
			result = bCopy - aCopy;
		}
		return result;
	}

	BigNum operator-(const BigNum& a, const BigNum& b)
	{
		BigNum result;
		BigNum aCopy = a;
		BigNum bCopy = b;
		if (a.positive && !b.positive){
			bCopy.positive = true;
			result = aCopy + bCopy;
		}
		if (!a.positive && b.positive){
			aCopy.positive = true;
			result = aCopy + bCopy;
			result.positive = false;
		}
		if (!a.positive && !b.positive){
			aCopy.positive = true;
			bCopy.positive = true;
			result = bCopy - aCopy;
		}
		if (a.positive && b.positive){
			if (a >= b){
				result.resize(a.used * 2);
				result.used = a.used;
				bCopy.resize(a.used);
				for (unsigned int i = b.used; i < a.used; i++){
					bCopy.digits[i] = 0; //fill smaller number with leading zeros
										 //so that the number of digits matches
				}
				for (unsigned int i = 0; i < aCopy.used; i++){//subtract
					if (aCopy.digits[i] < bCopy.digits[i]){//we need to borrow
						aCopy.digits[i] += 10;
						for (unsigned int k = i + 1; k < aCopy.used; k++){
							if (aCopy.digits[k] == 0){
								aCopy.digits[k] = 9;
							}else{
								aCopy.digits[k] -= 1;
								break;
							}
						}//close nested for
					}//close borrow if
					result.digits[i] = aCopy.digits[i] - bCopy.digits[i];
				}//close subrtraction for
				result.trim();
			}else{//b > a, result = -(b-a)
				result = bCopy - aCopy;
				result.positive = false;
			}
		}
		return result;
	}
	
	BigNum operator*(const BigNum& a, const BigNum& b)
	{
		BigNum result;
		if (a == 0 || b == 0){
			return result;//result is initialized to 0;
		}
		BigNum aCopy = a;
		BigNum bCopy = b;
		BigNum partialprod;
		unsigned int carry = 0;
		unsigned int k;
		partialprod.resize(a.used + b.used + 1);
		partialprod.used = aCopy.used;
		if ((a.used + b.used + 1) > 20)//result only has default capacity
			result.resize((a.used + b.used + 1) * 2);
		//**begin multiplication**
		for (unsigned int i = 0; i < bCopy.used; i++){
			partialprod.used += 1;
			for (unsigned int j = 0; j < partialprod.used; j++){
				partialprod.digits[j] = 0; //fill partialprod w/ zeros
			}
			carry = 0;//reset carry
			for (k = 0; k < aCopy.used; k++){
				partialprod.digits[i + k] = ((bCopy.digits[i] * aCopy.digits[k]) + carry) % 10;
				carry = ((bCopy.digits[i] * aCopy.digits[k]) + carry) / 10;
			}
			if (carry != 0){
				partialprod.digits[i + k] = carry;
			}
			result += partialprod;
		}
		//**end multiplication**
		if (aCopy.positive != bCopy.positive)
			result.positive = false;//we only need to check this case
			//because result is initialized to positive
		result.trim();
		
		/*for(int i = (result.used-1); (result.digits[i] == 0) && (i > 0); i--)
		{
			result.used--;
		}*/
		return result;
	}

	BigNum operator / (const BigNum& a, const BigNum& b)
	{
		BigNum result;
		result.resize(a.used * 2);
		result.used = a.used;
		BigNum aCopy = a;
		BigNum bCopy = b;
		aCopy.positive = true;
		bCopy.positive = true;
		if (a.positive == b.positive){
			result.positive = true;
		}else{
			result.positive = false;
		}
		if (bCopy > aCopy)
			return result;
		int cnt = -1;
		BigNum curr = aCopy;
		while (curr >= 0){
			cnt++;
			curr -= b;
		}
		result = cnt;
		return result;
	}


	BigNum operator%(const BigNum& a, const BigNum& b)
	{
		BigNum result;
		result.resize(a.used * 2);
		result.used = a.used;
		BigNum aCopy = a;
		BigNum bCopy = b;
		aCopy.positive = true;
		bCopy.positive = true;
		if (a.positive == b.positive){
			result.positive = true;
		}else{
			result.positive = false;
		}
		if (bCopy > aCopy)
			return result;
		BigNum curr = aCopy;
		while (curr >= 0){
			curr -= b;
		}
		result = b + curr;
		return result;
	}
/*
	bool operator>(const BigNum& a, const BigNum& b)
	{
		if (a.positive == true && b.positive == false) return true;
		
		else if (a.positive == false && b.positive == true) return false;
		
		else 
		{
			if (a.used > b.used) 
			{
				if (a.positive == true) return true;
				else return false;
			}
			
			else if (a.used < b.used) 
			{
				if (a.positive == true) return false;
				else return true;
			}
	
			else 
			{
				for (unsigned int i = 0; i < a.used; ++i) 
				{
					if (a.digits[a.used - 1 - i] < b.digits[b.used - 1 - i])  
					{
						if(a.positive == true) return false;
						else return true;
					}
					if (a.digits[a.used - 1 - i] > b.digits[b.used - 1 - i])  
					{
						if(a.positive == true) return true;
						else return false;
					}
				}
			}          
		}
		return false;
	}


	bool operator>=(const BigNum& a, const BigNum& b)
	{
		return ((a > b) || (a == b));
	}


	bool operator<(const BigNum& a, const BigNum& b)
	{
		return !(a >= b);
	}


	bool operator<=(const BigNum& a, const BigNum& b)
	{
		return !(a > b);
	}


	bool operator==(const BigNum& a, const BigNum& b)
	{
		if ((a.positive != b.positive) || (a.used != b.used))
			return false;

		for (unsigned int i = 0; i < a.used; i++) 
		{
			if (a.digits[a.used - 1 - i] != b.digits[b.used - 1 - i]) 
				return false;
		}

		return true;
	}


	bool operator!=(const BigNum& a, const BigNum& b)
	{
		return !(a == b);
	}

	// trim leading zeros
	void BigNum::trim()
	{
		while (used > 1 && digits[used-1] == 0)
			used--;
	}
	
	std::ostream& operator<<(std::ostream &os, const BigNum& bignum)
	{
		unsigned int i = 0;
		unsigned int j = 0;

		if (bignum.positive == false)  os << '-';

		for (i=0; i<bignum.used; ++i) 
		{
			os << bignum.digits[bignum.used - i - 1];
			if (j < 60) ++j; 
			else 
			{
				os << endl;
				j = 0;
			}
		}
    
		return os;
	}	 

	std::istream& operator>>(std::istream &is, BigNum& bignum)
	{
		string str;
		is >> str;

		BigNum temp = str;
		bignum = temp;
		return is;
	}*/
	bool operator>(const BigNum& a, const BigNum& b)
	{
		if (a == b) return false;
		if (a.positive && !b.positive) return true;
		if (!a.positive && b.positive) return false;
		if (a.positive){ //if they are both positive
			if (a.used > b.used) return true;
			if (a.used < b.used) return false;
			//if the checks have reached this point, a and b have the same number of digits and are both positive
			//so scan backwards to find which is greater
			for (int i = (int) a.used - 1; i >= 0; i--){
				if (a.digits[i] > b.digits[i]) return true;
				if (a.digits[i] < b.digits[i]) return false;
			}
		}
		if (!a.positive){//if they are both negative all the checks flip
			if (a.used < b.used) return true;
			if (a.used > b.used) return false;
			//if the checks have reached this point, a and b have the same number of digits and are both negative
			//so scan backwards to find which is smaller
			for (int i = (int) a.used - 1; i >= 0; i--){
				if (a.digits[i] < b.digits[i]) return true;
				if (a.digits[i] > b.digits[i]) return false;
			}
		}
		return true;
	}


	bool operator>=(const BigNum& a, const BigNum& b)
	{
		if (a > b || a == b) return true;
		else return false;
	}


	bool operator<(const BigNum& a, const BigNum& b)
	{
		if (a > b || a == b) return false;
		else return true;
	}


	bool operator<=(const BigNum& a, const BigNum& b)
	{
		if (a < b || a == b) return true;
		else return false;
	}


	bool operator==(const BigNum& a, const BigNum& b)
	{
		if (a.used != b.used) return false;
		if (a.positive != b.positive) return false;
		for (unsigned int i = 0; i < a.used; i++){
			if (a.digits[i] != b.digits[i]){
				return false;
			}
		}
		return true;
	}


	bool operator!=(const BigNum& a, const BigNum& b)
	{
		if (a == b) return false;
		else return true;
	}

	// trim leading zeros
	void BigNum::trim()
	{
		while (used > 1 && digits[used-1] == 0)
			used--;
	}
	
	
	std::ostream& operator<<(std::ostream &os, const BigNum& bignum)
	{
		if (bignum.positive){
			for (unsigned int i = 0; i < bignum.used; i++)
				os << bignum.digits[(bignum.used - 1) - i];
		}else{
			os << "-";
			for (unsigned int i = 0; i < bignum.used; i++)
				os << bignum.digits[(bignum.used - 1) - i];
		}
		return os;
	}
		 

	std::istream& operator>>(std::istream &is, BigNum& bignum)
	{
		string a;
		is >> a;		
		BigNum temp = BigNum(a);
		bignum = temp;
		return is;
	}
	
	BigNum factorial(const BigNum& a)
	{
		BigNum result = 1;
		for (BigNum i = 2; i <= a; ++i)
			result *= i;
		return result;
    }
  }


#endif



