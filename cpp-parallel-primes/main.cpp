//
//  main.cpp
//  cpp-parallel-primes
//
//  Created by MEDLAO on 21/01/2026.
//

#include <iostream>
#include <cmath>


bool is_prime(unsigned long long n)
{
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    unsigned long long limit = static_cast<unsigned long long>(std::sqrt(n));
    
    for (unsigned long long d = 3; d <=  limit; d += 2) {
        if (n % d == 0)
            return false;
    }
    
    return true;
}
    
    
    
int main(int argc, const char * argv[]) {
    
    unsigned long long a = 9;
    unsigned long long b = 11;
    
    std::cout << "Is " << a << " prime? " << (is_prime(a) ? "yes" : "no") << "\n";
    
    std::cout << "Is " << b << " prime? " << (is_prime(b) ? "yes" : "no") << "\n";
    
    return 0;
}

