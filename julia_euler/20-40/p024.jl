### Problem 24 - https://projecteuler.net/problem=24
# What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?"

using Combinatorics

println("example: ", collect(permutations(0:2)))
println("answer: ", collect(permutations(0:9))[10^6])
