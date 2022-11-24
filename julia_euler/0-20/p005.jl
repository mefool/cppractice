# Problem 5 - Smallest Multiple
# What is the smallest positive number divisible by by 1 to 20?
#
# reference: https://docs.julialang.org/en/v1/base/math/#Base.lcm

@time result = lcm(1:20)
println("lcm(1:20): ", result)
