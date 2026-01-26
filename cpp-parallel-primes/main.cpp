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
    
    unsigned long long limit = 100000;
    unsigned long long mid = limit / 2;
    
    unsigned long long count1 = 0;
    unsigned long long count2 = 0;
    
    // first half
    for (unsigned long long n = 2; n <= mid; ++n) {
        if (is_prime(n)) {
            ++count1;
        }
    }
    
    // second half
    for (unsigned long long n = mid + 1; n <= limit; ++n) {
        if (is_prime(n)) {
            ++count2;
        }
    }
    
    auto start = std::chrono::steady_clock::now();
    
    
    /*for (unsigned long long n = 2; n <=  limit; ++n) {
        if (is_prime(n)) {
            ++count;
        }
    }*/
    
    unsigned long long total = count1 + count2;
    
    auto end = std::chrono::steady_clock::now();
    auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    
    std::cout << "Limit: " << limit << "\n";
    std::cout << "Prime count: " << count << "\n";
    std::cout << "Time (ms): " << result << "\n";
    
    return 0;
}

