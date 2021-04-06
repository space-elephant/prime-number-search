// miller-rabin primality test
#include <bits/stdc++.h>
using namespace std;
 
// modular exponentiation,(x^y) % p
int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
                // equal to p
    while (y > 0)
    {
        // y = odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y = even
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
 
// This function is called for all k stuff. It returns false if n is composite and returns true if n is probably prime. also d is an odd number such that  d*2<sup>r</sup> = n-1 for some r >= 1
bool miillerTest(int d, int n)
{
    // Pick a random number in [2..n-2]
    // make sure that n > 4
    int a = 2 + rand() % (n - 4);
 
    // modular exponentiation a^d % n
    int x = power(a, d, n);
 
    if (x == 1  || x == n-1)
       return true;
 
    // Keep squaring x while one of the following doesn't happen
    // 1.   d does not reach n-1
    // 2.  (x^2) % n is not 1
    // 3. (x^2) % n is not n-1
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;
 
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
 
    // Return composite
    return false;
}
 
// It returns false if n is composite and returns true if n is probably prime.  k is an input parameter that determines accuracy level. Higher value of k indicates more accuracy.
bool isPrime(int n, int k)
{
    // more cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
 
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;
   
    // check for prime k times
    for (int i = 0; i < k; i++)
         if (!miillerTest(d, n))
              return false;
 
    return true;
}
 
// Driver program
int main()
{
    int k = 4;  
    cout << "List of primes: \n";
    for (int n = 1; n < 10000000000; n++)
       if (isPrime(n, k))
          cout << n << " ";
 
    return 0;
}

