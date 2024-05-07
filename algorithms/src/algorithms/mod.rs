/// Orders the given array with $\theta(n^2)$ time complexity.
pub fn insertion_sort(array: &mut [i32]) {
    for i in 1..array.len() {
        let compared_key = array[i];
        for j in (0..i).rev() {
            if array[j] > compared_key { 
                array[j+1] = array[j];
                array[j] = compared_key;
            }
        }
    }
}

/// Finds a `num` value in a given array with $\theta(\lg{n})$ time complexity.
/// Returns the index of the value, returns 0 if not found (this may be changed to -1);
pub fn binary_search(array: &mut [i32], num: i32) -> u32 {
    let mut left: u32 = 0;
    let mut right = array.len() as u32 -1;

    while left != right {
        let middle = (left + right)/2;
        if array[middle as usize] == num {
            return middle;
        } else if num > array[middle as usize] {
            left = middle;
        } else { right = middle; }
    }
    0
}

/// Orders the given array with $\theta(n\lg{n}))$ time complexity.
fn merge_sort(array: &mut [i32]) -> i32{
    todo!()
}

/// Orders the given array, promedy time complexity is $\theta(n\lg{n}))$
/// but worst case, depending on the pivot, is $\theta{n^2}$.
pub fn quick_sort(array: &mut [i32], low: i32, high: i32){
    if low >= high { return }
    let pivot_index = partition(array, low, high);
    quick_sort(array, low, pivot_index-1);
    quick_sort(array, pivot_index+1, high);
}

/// Takes last element of the given array as the pivot and place the lower elements
/// to the left and grater elements to the right; returns the index of the final
/// position of the pivot. Time complexity is $\theta(n)$.
fn partition(array: &mut [i32], low: i32, high: i32) -> i32 {
    let pivot = array[high as usize];
    let mut index = low-1;
    for i in low..high {
        if array[i as usize] <= pivot {
            index += 1;
            let temp = array[i as usize];
            array[i as usize] = array[index as usize];
            array[index as usize] = temp;
        }
    }
    index += 1;
    array[high as usize] = array[index as usize];
    array[index as usize] = pivot;
    index
}

/// Orders the given array with $\theta(n\lg{n}))$ time complexity.
fn heap_sort(array: &mut [i32]) {
    todo!()
}

/// Orders the given array with $\theta(n)$ time complexity.
pub fn counting_sort(array: &mut [i32], max: usize) -> Vec<i32> {
    let mut counts = vec![0; max + 1];
    // Count the number of times each element appears in the array
    array.iter().for_each(|&x| counts[x as usize] += 1);
    // Calculate the number of elements less than or equal to each element
    counts.iter_mut().fold(0, |acc, x| { *x += acc; *x });
    // Sort the array based on the counts
    array.iter().fold(vec![0; array.len()], |mut sorted, &x| {
        counts[x as usize] -= 1;
        sorted[counts[x as usize]] = x;
        sorted
    })
}

/// Orders the given array with $\theta(n)$ time complexity.
fn radix_sort(array: &mut [i32]) {
    // counting_sort may be used as a subroutine.
    todo!()
}

/// Orders the given array with $\theta(n)$ time complexity.
pub fn bucket_sort(array: &mut [i32]) {
    if array.is_empty() { return }
    
    let min = *array.iter().min().unwrap();
    let max = *array.iter().max().unwrap();
    let bucket_size = (max - min) / array.len() as i32 + 1;
    let bucket_count = ((max - min) / bucket_size + 1) as usize;
    let mut buckets: Vec<Vec<i32>> = vec![vec![]; bucket_count];
    
    // Push each element into its corresponding bucket
    array.iter().for_each(|&item| {
        let index = ((item - min) / bucket_size) as usize;
        buckets[index].push(item);
    });
    
    // Orders each bucket and reconstructs the original array
    let mut idx = 0;
    buckets.iter_mut().for_each(|bucket| {
        insertion_sort(bucket);
        bucket.iter().for_each(|&item| {
            array[idx] = item;
            idx += 1;
        });
    });
}

