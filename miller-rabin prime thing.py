#Miller-Rabin primality test
import random

# mod exponentiation, x^y mod p
def power(x, y, p):
    res = 1;
    x = x % p;
    while (y > 0):
         
        # If y is odd, multiply
        # x with result
        if (y & 1):
            res = (res * x) % p;
 
        # y = even
        y = y>>1; # y = y/2
        x = (x * x) % p;
     
    return res;
 
# miller rabin test
def miillerTest(d, n):
     
    # Pick a random number in [2..n-2]
    # make sure that n > 4
    a = 2 + random.randint(1, n - 4);
 
    # mod exponentiation: a^d mod n
    x = power(a, d, n);
 
    if (x == 1 or x == n - 1):
        return True;
 
    # keep squaring until this is satisfied:
    # 1. d does not reach n-1
    # 2. (x^2) mod n is not 1
    # 3. (x^2) mod n is not n-1
    while (d != n - 1):
        x = (x * x) % n;
        d *= 2;
 
        if (x == 1):
            return False;
        if (x == n - 1):
            return True;
 
    # Return composite
    return False;
 
# It returns false if n is composite and returns true if n is probably prime. k is an input parameter that determines accuracy level. Higher value of k indicates more accuracy.
def isPrime( n, k):
    if (n <= 1 or n == 4):
        return False;
    if (n <= 3):
        return True;
    d = n - 1;
    while (d % 2 == 0):
        d //= 2;
 
    # check the number k times for accuracy
    for i in range(k):
        if (miillerTest(d, n) == False):
            return False;
 
    return True;
 
# Driver Code
k = 4;
 
print("List of primes: ");
for n in range(1,100000000000000):
    if (isPrime(n, k)):
        print(n , end=" ");
