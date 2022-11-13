/* Project Euler - Problem 4
  Find the largest palindrome made from the product of two 3-digit numbers.
  
  p004.rs
  rustc p004.rs
  ./p004

  note: this general version is too limited, but it gets the expected result
*/

fn main() {
    let num = 190091;
    println!("num: {}", num);
    println!("is_palindrome(num): {}", is_palindrome(num));

    let result = p004(6);
    println!("result: {}", result);
}

fn p004(n: u32) -> u32{
    let mut num = 0;
    let (min, max) = (u32::pow(10, n/2-1), u32::pow(10, (n-1)/2+1));
    //println!("({}, {})", min, max);
    for i in (min..max).rev() {
        for j in (min..i).rev() {
            if i*j < num {
                break;
                
            }
            if is_palindrome(i*j) {num = i*j;}
        }
        if i*i < num {break;}
    }
    return num;
}

fn is_palindrome(n: u32) -> bool {
    let (mut rev, mut org) = (0,n);
        
    while org > 0 {
        rev = (rev*10) + org%10;
        org/=10;
    }
    rev == n
}
