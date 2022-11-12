/* Project Euler - Problem 3
  What is the largest prime factor of the number 600851475143?
  
  p003.rs
  rustc p003.rs
  ./p003

*/

fn main() {
    let num = 600851475143;
    println!("num: {}", num);
    println!("prime_factors(39): {:?}", prime_factors(39));
    println!("prime_factors_old(39): {:?}", prime_factors_old(39));
    //println!("prime_factors(num): {:?}", prime_factors(num));
    let result = p003(num);
    println!("result: {}", result)
}

fn p003(num: u64) -> u64{
    *prime_factors(num).iter().max().unwrap()
}

fn prime_factors(mut n: u64) -> Vec<u64> {
    let mut out = vec![];
    let mut d = 2;
    
    while n > 1 {
        while n % d == 0 {
            out.push(d);
            n /= d;
        }
        d = d + 1;
        if d*d > n {
            if n > 1 {
                out.push(n);
                break;
            }
        }
    }
    out
}

fn prime_factors_old(mut n: u64) -> Vec<u64> {
    let mut out = vec![];
    for i in 2..(n+1) {
        while n % i == 0 {
            out.push(i);
            n /= i;
        }
        if n == 1 { break; }
    }
    out // return out (implicit return)
}
