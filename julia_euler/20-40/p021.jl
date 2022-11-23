# Project Euler - Problem 021
# Evaluate the sum of all the amicable numbers under 10000.
#
# julia p021.jl
#
# notes:
#   amicable: d(a) = b && d(b) = a, a!=b; 
#             where d(n) is the sum of proper divisors (n%m = 0, m < n)

function sum_prop_div(num)
    sum = 1
    for i = 1:floor(sqrt(num))
        if num%i == 0
            if i == num/i
                sum += i
            else
                sum += i + num/i
            end
        end
    end
    return sum
end

function ammicable(n)
    n_am = sum_prop_div(n)
    return n == sum_prop_div(n_am) && n != n_am ? n : 0
end

lim = 9999
println("ammicable(240): ", ammicable(240))
println(sum([ammicable(n) for n in 2:lim]))
