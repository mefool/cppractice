# Problem 10 - Summation of Primes
# Find the sum of all primes bellow 2*10^6.
using Primes

@time println("sum(primes(2*10^6)): ", sum(primes(2*10^6)))
