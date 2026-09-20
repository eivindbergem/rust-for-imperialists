fn main() {
    let array: [u16; _] = [5, 2, 3, 6, 7, 2, 3, 4, 1, 5, 3, 5, 2, 4, 2, 7];

    let sum: u16 = array
        .into_iter()
        .enumerate()
        .map(|(i, item)| {
            let value = item.pow(2);
            println!("{}: {}", i, value);
            value
        })
        .sum();

    println!("Sum is {}", sum);
}
