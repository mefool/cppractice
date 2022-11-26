### Problem 24 - https://projecteuler.net/problem=24
# What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?"
# reference: https://juliamath.github.io/Combinatorics.jl/dev/api/#Permutations
# todo: check nthperm(a, n) function compared to permutations (time and allocations)

using Combinatorics

println("example: ", collect(permutations(0:2)))
println("answer: ", nthperm(0:9,10^6))

if false
    print("@time collect(permutations(0:9))[10^6]:")
    an_perm = @time collect(permutations(0:9))[10^6] # ~1.2s 1.1Gb
    print("@time nthperm(0:9,10^6):               ") # ~3ns 144B
    an_nperm = @time nthperm(0:9,10^6)
    println("collect(permutations(0:9))[10^6]: ", an_perm)
    println("nthperm(0:9,10^6):                ", an_perm)
end
