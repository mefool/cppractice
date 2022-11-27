/* Project Euler - Quadratic Primes - Problem 27

  rustc p027.rs
  ./p027

  notes: redo using primes package and compare performance
  references: https://docs.rs/primes/latest/primes/index.html
              https://docs.rs/primes/latest/src/primes/lib.rs.html#448-453
*/


fn main() {
    if true {
        println!("is_prime(7): {}", is_prime(7));
        println!("consecutive_primes_quadratic(1, 41): {}",
                 consecutive_primes_quadratic(1, 41));
        println!("consecutive_primes_quadratic(-79, 1601): {}",
                 consecutive_primes_quadratic(-79, 1601));
    }

    let result = p027_unop(1000);
    println!("result: {}", result);
}

fn p027_unop(lmt: i32) -> i32 {
    let mut nc_max = 0;
    let (mut a_max, mut b_max) = (0, 0);

    for a in -lmt..lmt {
        for b in 0..lmt {
            if !is_prime_unop(b) {
                continue;
            }
            let nc = consecutive_primes_quadratic(a,b);
            if nc > nc_max {
                nc_max = nc;
                a_max = a;
                b_max = b;
            }
        }
    }
    //println!("(a,b,nc): ({},{},{})", a_max, b_max, nc_max);
    a_max * b_max
}

fn is_prime_unop(n: i32) -> bool {
    if n <= 1 {
        return false;
    }
    for i in 2..n{
        if n % i == 0 {
            return false;
        }
    }
    true
}

fn consecutive_primes_quadratic(a: i32, b: i32) -> i32 {
    let mut i = 0;
    while is_prime_unop(i*i + a*i + b) {i += 1};
    i
}

// primes.jl src (lines 424-453) - not used yet
// later experiment
/// Find the first factor (other than 1) of a number
fn firstfac(x: u64) -> u64 {
    if x % 2 == 0 {
        return 2;
    };
    // TODO: return to step_by
    // for n in (3..).step_by(2).take_while(|m| m*m <= x) {
    for n in (1..).map(|m| 2 * m + 1).take_while(|m| m * m <= x) {
        if x % n == 0 {
            return n;
        };
    }
    // No factor found. It must be prime.
    x
}

fn is_prime(n: u64) -> bool {
    if n <= 1 {
        return false;
    }
    firstfac(n) == n
}
