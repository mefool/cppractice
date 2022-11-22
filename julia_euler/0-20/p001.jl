lim = 999;
println(sum([n%3 == 0 || n%5 == 0 ? n : 0 for n in 1:lim]))
