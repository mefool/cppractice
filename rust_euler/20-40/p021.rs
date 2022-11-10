/* Project Euler - Problem 21
  Evaluate the sum of all the amicable numbers under 10000.
  
  p021.rs
  rustc p021.rs
  ./p021
  
  notes:
    amicable: d(a) = b && d(b) = a, a!=b; 
              where d(n) is the sum of proper divisors (n%m = 0, m < n)
              
*/

fn main() {
    let num = 10000;
    println!("num: {}", num);
    
    if true {
        println!("sum_prop_div(284): {}", sum_prop_div(284))
    }
    
    let result = p021(num);
    println!("result: {}", result)
}

fn p021(num: u32) -> u32 {
    let mut sum_am = 0;
    for n in 2..num {
        let n_am = sum_prop_div(n);
        if n == sum_prop_div(n_am) && n != n_am {
            sum_am += n;
        }
    }
    return sum_am;
}

fn sum_prop_div (num: u32) -> u32 {
    let mut sum = 1;
    let sqrt_num = (num as f64).sqrt() as u32 + 1;
    for i in 2..sqrt_num {
        if num%i == 0 {
            if i == num/i {
                sum += i;
            } else {
                sum += i + num/i;
            }
        }
    }
    return sum;
}