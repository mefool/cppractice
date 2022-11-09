/* Project Euler - Problem 1
  Find the sum of all the multiples of 3 or 5 below 1000
  
  p001.rs
  rustc p001.rs
  ./p001
*/

fn main() {
    let num = 1000;
    let mult = vec![3, 5];
    println!("num: {}", num);
    println!("mult: {:?}", mult);
    
    let result = p001(num, &mult);
    println!("result: {}", result)
}

fn p001(num: u32, mult: &[u32]) -> u32{
    let mut sum = 0;
    //let mut nmult_fl;
    for n in 0..num {
        for m in mult {
            if n%m == 0 {
                sum += n;
                break; /* if no break is used a number which shares multiples 
                          will be counted multiple times */
            }
        }  
    }
    return sum;
}
