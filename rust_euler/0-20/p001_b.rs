/* Project Euler - Problem 1 - Improved
  Find the sum of all the multiples of 3 or 5 below 1000
  
  p001_b.rs
  rustc p001_b.rs
  ./p001_b
  
  references: 
    [ https://github.com/gifnksm/ProjectEulerRust/blob/master/src/bin/p001.rs ]
    [ https://docs.rs/filters/latest/filters/ ]
*/

fn main() {
    let num = 1000;
    let mult = vec![3, 5];
    println!("num: {}", num);
    println!("mult: {:?}", mult);
    
    let result = p001(num);
    println!("result: {}", result)
}

fn p001(num: u32) -> u32 {
    (1..num).filter(|&n| n % 3 == 0 || n % 5 == 0).sum()
}
