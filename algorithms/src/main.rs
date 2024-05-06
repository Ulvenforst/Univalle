mod algorithms;
use crate::algorithms::*;

fn main() {
    let mut array = [5,2,4,6,1,3];
    let high_bound = array.len() as i32 -1;
    // Make sure array is ordered before using binary_search
    // insertion_sort(&mut array);
    // println!("{:?}",array);
    // println!("{}", binary_search(&mut array, 2));

    quick_sort(&mut array, 0, high_bound);
    println!("{:?}",array);
}
