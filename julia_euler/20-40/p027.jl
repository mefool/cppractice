### Problem 27 - Quadratic primes - https://projecteuler.net/problem=27
# Find a quadratic formula with terms below 1000 that produces the maximum
# number of primes for consecutive values of n.
#
# references: https://juliacollections.github.io/IterTools.jl/latest/#takewhile(cond,-xs)-1
#
# notes: experiment with some way to display a and b with the cpq number

using Primes, IterTools

function consecutive_primes_quadratic(a, b)
    length(collect(takewhile(n -> isprime(n^2 + a*n + b), 0:120)))
end

println("1st example - consecutive_primes_quadratic(1, 41):     ",
        consecutive_primes_quadratic(1, 41))
println("2nd example - consecutive_primes_quadratic(-79, 1601): ",
        consecutive_primes_quadratic(-79, 1601))

L = 10^3
result = maximum((consecutive_primes_quadratic(a, b), a*b)
                 for a in -L:L, b in primes(L))[2]
println("answer: ", result)
