#include "poly.h"
using namespace std;

namespace main_savitch_5
{
	/*DESCRIPTION OF POLYNOMIAL MEMBER VARIABLES:
	 * 1) double EPSILON - the smallest double that the
	 *    computer considers non-zero, used when comparing
	 *    two doubles for equality (if |a - b| < EPSILON then
	 *    a == b)
	 * 2) polynode* head_ptr - this is a pointer to the 
	 *    first node in the list, the x^0 term
	 * 3) polynode* tail_ptr - this is a pointer to the 
	 *    last term in the list, the term with the highest
	 *    exponent
	 * 4) mutable polynode* recent_ptr - a pointer to the
	 *    most recently accessed term in the list
	 * 5) unsigned int current_degree - the value of the highest
	 *    exponent in the list
	 */
	polynomial::polynomial(double c, unsigned int exponent)
	{
		// store machine epsilon
		EPSILON = std::numeric_limits<double>::epsilon();
		// write the rest
		current_degree = exponent;
		head_ptr = new polynode;
		recent_ptr = head_ptr;
		head_ptr->set_exponent(0);
		head_ptr->set_back(nullptr);
		if (exponent == 0 || fabs(c) < EPSILON){
			current_degree = 0;
			tail_ptr = head_ptr;
			head_ptr->set_fore(nullptr);
			head_ptr->set_coef(c);
		}else{
			head_ptr->set_coef(0);
			tail_ptr = new polynode;
			head_ptr->set_fore(tail_ptr);
			tail_ptr->set_back(head_ptr);
			tail_ptr->set_fore(nullptr);
			tail_ptr->set_coef(c);
			tail_ptr->set_exponent(exponent);
		}
		set_recent(exponent);		
    }

    polynomial& polynomial::operator=(const polynomial& source)
    {
		// store machine epsilon
		EPSILON = std::numeric_limits<double>::epsilon();
		// write the rest
		if (&source != this){
			clear();
			current_degree = source.current_degree;
			head_ptr->set_coef(source.head_ptr->coef());
			polynode* temp = head_ptr;
			tail_ptr = head_ptr;
			polynode* sourceTemp = source.head_ptr->fore();
			while (sourceTemp != nullptr){
				temp->set_fore(new polynode);
				temp->fore()->set_back(temp);
				temp = temp->fore();
				tail_ptr = temp;
				temp->set_exponent(sourceTemp->exponent());
				temp->set_coef(sourceTemp->coef());
				sourceTemp = sourceTemp->fore();
			}
			temp->set_fore(nullptr);
		}
		return *this;
		
	}
	
    polynomial::polynomial(const polynomial& source)
    {
		// store machine epsilon
		EPSILON = std::numeric_limits<double>::epsilon();
		// write the rest
		current_degree = source.current_degree;
		head_ptr = new polynode;
		tail_ptr = head_ptr;
		head_ptr->set_exponent(0);
		head_ptr->set_coef(source.head_ptr->coef());
		head_ptr->set_back(nullptr);
		polynode* curr = head_ptr;
		polynode* next = source.head_ptr->fore();
		while (next != nullptr){
			curr->set_fore(new polynode);
			curr->fore()->set_back(curr);
			curr = curr->fore();
			tail_ptr = curr;
			curr->set_exponent(next->exponent());
			curr->set_coef(next->coef());
			next = next->fore();
		}
		set_recent(source.degree()); // THIS IS THE LINE THAT SEG FAULTS
    }

    polynomial::~polynomial()
    {
		clear();
		delete head_ptr;
    }

    void polynomial::clear()
    {
		polynode* temp = head_ptr;
			while (head_ptr->fore() != nullptr){
				temp = head_ptr->fore();
				head_ptr->set_fore(temp->fore());
				delete temp;
			}
		tail_ptr = head_ptr;
		current_degree = 0;
    }
    
    double polynomial::coefficient(unsigned int exponent) const
    {
		polynode* temp = head_ptr;
		while (temp != nullptr){
			if (temp->exponent() == exponent)
				return temp->coef();
			temp = temp->fore();
		}
		return 0.0;
    }

    void polynomial::add_to_coef(double amount, unsigned int exponent)
    {
		if (amount == 0) return;
		double newval = amount;
		polynode* temp = head_ptr;
		while (temp != nullptr){
			if (temp->exponent() == exponent){
				newval += temp->coef();
				break;
			}
			temp = temp->fore();
		}
		assign_coef(newval, exponent);
	}

    void polynomial::assign_coef(double coefficient, unsigned int exponent)
    {
		polynode* temp = head_ptr;
		if (exponent == 0){
			head_ptr->set_coef(coefficient);
			return;
		}
		if (exponent > current_degree && fabs(coefficient) >= EPSILON){
			tail_ptr->set_fore(new polynode);
			tail_ptr->fore()->set_back(tail_ptr);
			tail_ptr->fore()->set_fore(nullptr);
			tail_ptr->fore()->set_exponent(exponent);
			tail_ptr->fore()->set_coef(coefficient);
			tail_ptr = tail_ptr->fore();
			current_degree = exponent;
		}
		if (exponent == current_degree){
			if (fabs(coefficient) >= EPSILON){
				tail_ptr->set_coef(coefficient);
			}
			if (fabs(coefficient) < EPSILON){
				temp = tail_ptr;
				tail_ptr = tail_ptr->back();
				tail_ptr->set_fore(nullptr);
				delete temp;
				current_degree = tail_ptr->exponent();
			}
		}else{
			while (temp != nullptr){
				if (temp->exponent() == exponent && fabs(coefficient) >= EPSILON){
					temp->set_coef(coefficient);
					break;
				}
				if (temp->exponent() == exponent && fabs(coefficient) < EPSILON){
					if (temp == tail_ptr){
						tail_ptr->back()->set_fore(nullptr);
						tail_ptr = tail_ptr->back();
						delete temp;
						current_degree = tail_ptr->exponent();
						break;
					}else{
						temp->fore()->set_back(temp->back());
						temp->back()->set_fore(temp->fore());
						delete temp;
						break;
					}	
				}
				if (temp->exponent() > exponent && fabs(coefficient) >= EPSILON){
					temp = temp->back();
					temp->fore()->set_back(new polynode);
					temp->fore()->back()->set_back(temp);
					temp = temp->fore();
					temp->back()->set_fore(temp);
					temp->back()->back()->set_fore(temp->back());
					temp->back()->set_exponent(exponent);
					temp->back()->set_coef(coefficient);
					break;
				}
				temp = temp->fore();
			}
		}
		current_degree = tail_ptr->exponent();
	}


    unsigned int polynomial::next_term(unsigned int exponent) const
    {
			set_recent(exponent);
			if (recent_ptr != tail_ptr){
				recent_ptr = recent_ptr->fore();
				return recent_ptr->exponent();
			}else{
				return 0;
			}
    }

	unsigned int polynomial::previous_term(unsigned int exponent) const
    {
		set_recent(exponent);
		if (recent_ptr == head_ptr){
			if (recent_ptr->exponent() == exponent){
				return UINT_MAX;
			}
			if (recent_ptr->exponent() < exponent){
				if (fabs(recent_ptr->coef()) < EPSILON) return UINT_MAX;
				else return recent_ptr->exponent();
			}
		}
		if (recent_ptr == head_ptr->fore()){
			if (recent_ptr->exponent() == exponent){
				if (fabs(head_ptr->coef()) < EPSILON)
					return UINT_MAX;
				else return head_ptr->exponent();
			}
			if (recent_ptr->exponent() < exponent)
				return recent_ptr->exponent();
		}else{
			if (recent_ptr->exponent() < exponent)
				return recent_ptr->exponent();
			if (recent_ptr->exponent() == exponent)
				return recent_ptr->back()->exponent();
		}
		return 0;
    }
    
    void polynomial::set_recent(unsigned int exponent) const
    {
		if (exponent == 0){
			recent_ptr = head_ptr;
			return;
		}
		if (exponent >= current_degree){
			recent_ptr = tail_ptr;
			return;
		}
		if (exponent > recent_ptr->exponent()){
			while (recent_ptr->fore()->exponent() <= exponent){
				recent_ptr = recent_ptr->fore();
			}
		}
		if (exponent < recent_ptr->exponent()){
			while (recent_ptr->back()->exponent() >= exponent){
				recent_ptr = recent_ptr->back();
			}
			if (recent_ptr->exponent() != exponent)
				recent_ptr = recent_ptr->back();
		}
	}
    
    double polynomial::eval(double x) const
    {
		double total = head_ptr->coef();
		double partial;
		polynode* temp = head_ptr->fore();
		while (temp != nullptr){
			partial = x;
			for (unsigned int i = 1; i < temp->exponent(); i++)
				partial *= x;
			total += partial * temp->coef();
			temp = temp->fore();
		}
		return total;
    }

    polynomial polynomial::derivative() const
    {
		if (current_degree == 0){
			polynomial p(0, 0);
			return p;
		}
		polynomial p_prime(coefficient(1), 0);
		if (current_degree == 1){
			return p_prime;
		}
		polynode* temp = head_ptr->fore();
		while (temp != nullptr){
			p_prime.assign_coef(temp->coef() * (double) temp->exponent(), (temp->exponent())-1);
			temp = temp->fore();
		}
		p_prime.current_degree = current_degree - 1;
		return p_prime;
    }
    
    polynomial operator+(const polynomial& p1, const polynomial& p2)
    {
		unsigned int exp = 0;
		if (p1.degree() > p2.degree()){
			polynomial p = p2;
			while (exp <= p1.degree()){
				p.add_to_coef(p1.coefficient(exp), exp);
				exp++;
			}
			return p;
		}else{
			polynomial p = p1;
			while (exp <= p2.degree()){
				p.add_to_coef(p2.coefficient(exp), exp);
				exp++;
			}
			return p;
		}
    }
    
    polynomial operator-(const polynomial& p1, const polynomial& p2)
    {
		polynomial p = p2;
		unsigned int exp = 0;
		while (exp <= p2.degree()){
			p.assign_coef(-1 * p2.coefficient(exp), exp);
			exp++;
		}
		return p1 + p;
    }
    
    polynomial operator*(const polynomial& p1, const polynomial& p2)
    {		
		polynomial p;
		unsigned int exp = 0;
		while (exp <= p2.degree()){
			for(unsigned int i = 0; i <= p1.degree(); i++){
				p.add_to_coef(p2.coefficient(exp) * p1.coefficient(i), i + exp);
			}
			exp++;
		}
		return p;
    }

    ostream& operator << (ostream& out, const polynomial& p)
    {
		unsigned int expo = 0; 
		do { 
			out << p.coefficient(expo) << "*x^" << expo; 
			expo = p.next_term(expo); 
			if (expo != 0) out << " + "; 
		} while(expo != 0); 
		return out;
    }
    
    void polynomial::find_root(double& answer, bool& success, unsigned int& iterations,
				double guess, unsigned int maximum_iterations, double epsilon) const
    {
		double x = guess;
		iterations = 0;
		success = false;
		polynomial temp(*this);
		while (!success){
			if (iterations == maximum_iterations){
				answer = x;
				return;
			}

			if (fabs(temp.eval(x)) < epsilon){
				success = true;
				answer = x;
				return;
			}
			if (fabs(temp.derivative().eval(x)) < epsilon){
				answer = guess;
				return;
			}
			iterations++;
			x = x - (temp.eval(x) / temp.derivative().eval(x));
		}
	}
}
