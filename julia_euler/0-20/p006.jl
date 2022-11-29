# Problem 6 - Sum square diference
# Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
#
# notes:
#   sum of natural numbers: https://en.wikipedia.org/wiki/1_%2B_2_%2B_3_%2B_4_%2B_%E2%8B%AF
#   sum of squares:         https://en.wikipedia.org/wiki/Square_pyramidal_number

using Printf

sum_squares(n) = (n * (n + 1) * (2n + 1)) / 6
sum_naturals(n) = (n * (n + 1)) / 2

N = 10^2
sum_n = sum(i for i in 1:N)
sum_s = sum(i^2 for i in 1:N)

result = sum_naturals(N)^2 - sum_squares(N)


@printf("sum(N)^2 - sum(N^2): %.0f\n", result)
@printf("sum_n^2 - sum_s:     %.0f\n", sum_n^2 - sum_s)
