/* Project Euler - Problem 2
  Find the sum of the even-valued Fibonacci sequence terms not exceeding 4(10^6)
  
  p002.rs
  rustc p002.rs
  ./p002
  
  references:
    https://bheisler.github.io/criterion.rs/book/getting_started.html
*/

fn main() {
    let num = 4000000;
    println!("num: {}", num);
    println!("fibonacci_r(10): {}", fibonacci_r(10));
    println!("fibonacci(10): {}", fibonacci(10));
    let result = p002(num);
    println!("result: {}", result)
}

fn p002(num: u32) -> u32{
    let mut sum = 0;
    let mut a = 1;
    let mut b = 1;
    let mut c = a+b;
    while c < num {
        c = a + b;
        a = b;
        b = c;
        if c%2 == 0 {
            sum += c;
        }
    }
    
    return sum;
}

fn fibonacci_r(n: u32) -> u32 {
    match n { // pattern matching (similar c++ switch, where _ is default)
        0 => 1,
        1 => 1,
        _ => fibonacci_r(n - 1) + fibonacci_r(n - 2),
    }
}

fn fibonacci(n: u64) -> u64 {
    let mut a = 0;
    let mut b = 1;

    match n {
        0 => b,
        _ => {
            for _ in 0..n {
                let c = a + b;
                a = b;
                b = c;
            }
            b
        }
    }
}
