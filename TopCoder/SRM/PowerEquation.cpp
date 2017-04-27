// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Ciel is learning about exponentiation.
While doing so, she has noticed some cute identities such as 9^3 = 27^2 and 2^10 = 32^2.


You are given an int n.
Fox Ciel is going to write down all identities of the form a^b = c^d where 1 <= a,b,c,d <= n.


Let X be the number of such identities.
Compute and return the value (X modulo (10^9 + 7)).

DEFINITION
Class:PowerEquation
Method:count
Parameters:int
Returns:int
Method signature:int count(int n)


CONSTRAINTS
-n will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
2

Returns: 6

We have these solutions:

1^1=1^1
1^1=1^2
1^2=1^1
1^2=1^2
2^1=2^1
2^2=2^2


1)
3

Returns: 15

Now we have:

1^1=1^1
1^1=1^2
1^1=1^3
1^2=1^1
1^2=1^2
1^2=1^3
1^3=1^1
1^3=1^2
1^3=1^3
2^1=2^1
2^2=2^2
2^3=2^3
3^1=3^1
3^2=3^2
3^3=3^3


2)
100

Returns: 21620



3)
22306

Returns: 68467

The answer is 1000068474 mod 10^9+7.

4)
1

Returns: 1



// END CUT HERE
#line 90 "PowerEquation.cpp"
#include <string>
#include <vector>
class PowerEquation {
	public:
	int count(int n) {
		
	}
};
