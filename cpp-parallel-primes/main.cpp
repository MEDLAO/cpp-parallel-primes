//
//  main.cpp
//  cpp-parallel-primes
//
//  Created by MEDLAO on 21/01/2026.
//

#include <iostream>
#include <cmath>
#include <thread>


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
    
    unsigned int n = std::thread::hardware_concurrency();
    unsigned long long chunk_size = limit/n;
    
    unsigned long long count1 = 0;
    unsigned long long count2 = 0;
    
    for (unsigned int i = 0; i < n; ++i) {
        unsigned long long range_start = i * chunk_size + 2;
        unsigned long long range_end;
        
        if (i == n - 1)
            range_end = limit;
        else
            range_end = (i + 1) * chunk_size + 1;
        
        std::cout << "Worker " << i << " -> [" << range_start << ", " << range_end << "]\n";
                    
        }
    
    
    /*auto start = std::chrono::steady_clock::now();
    
    count_primes_in_range(2, mid, count1);
    count_primes_in_range(mid + 1, limit, count2);
    
    std::thread t1(count_primes_in_range, 2, mid, std::ref(count1));
    std::thread t2(count_primes_in_range, mid + 1, limit, std::ref(count2));
    
    t1.join();
    t2.join();
    
    auto end = std::chrono::steady_clock::now();
    
    unsigned long long total = count1 + count2;
    
    
    auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    
    std::cout << "Limit: " << limit << "\n";
    std::cout << "Prime count: " << total << "\n";
    std::cout << "Time (ms): " << result << "\n";*/
    
    // two loop result:
    // Limit: 100000
    // Prime count: 9592
    // Time (ms): 15
    
    // Limit: 100000
    // Prime count: 9592
    // Time (ms): 9
    
    std::cout << n << " concurrent threads are supported.\n";
    
    return 0;
}

