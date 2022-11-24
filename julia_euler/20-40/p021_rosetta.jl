# Project Euler - Problem 021
# note: based on https://rosettacode.org/wiki/Amicable_pairs#Julia
 
using Primes, Printf

function pcontrib(p::Int64, a::Int64)
    n = one(p)
    pcon = one(p)
    for i in 1:a
        n *= p
        pcon += n
    end
    return pcon
end

function divisorsum(n::Int64)
    dsum = one(n)
    for (p, a) in factor(n)
        dsum *= pcontrib(p, a)
    end
    dsum -= n
end

function amicables_sum(L = 10^4)
    acnt = 0
    sum = 0
    for i in 2:L
        !isprime(i) || continue
        j = divisorsum(i)
        j != i && divisorsum(j) == i || continue
        divisorsum(j) == i || continue
        acnt += 1
        sum += i
        # println(@sprintf("%4d", acnt), " => ", j, ", ", i)
    end
    return sum
end

println("ammicable_sum(L=10^4): ", amicables_sum())