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

void count_primes_in_range(unsigned long long start,
                           unsigned long long end,
                           unsigned long long& out_count)
{
    for (unsigned long long n = start; n <= end; ++n) {
        if (is_prime(n)) {
            ++out_count;
        }
    }
}
    
    
int main(int argc, const char * argv[]) {
    
    unsigned long long limit = 100000;
    unsigned long long mid = limit / 2;
    
    unsigned long long count1 = 0;
    unsigned long long count2 = 0;
    
    auto start = std::chrono::steady_clock::now();
    
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
    
    
    auto end = std::chrono::steady_clock::now();
    
    unsigned long long total = count1 + count2;
    
    
    auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    
    std::cout << "Limit: " << limit << "\n";
    std::cout << "Prime count: " << total << "\n";
    std::cout << "Time (ms): " << result << "\n";
    
    // two loop result:
    // Limit: 100000
    // Prime count: 9592
    // Time (ms): 15
    
    return 0;
}

