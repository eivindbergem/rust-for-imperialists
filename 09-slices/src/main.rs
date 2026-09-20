fn print_slice(slice: &[u8]) {
    print!("Slice: ");

    for b in slice {
	print!("{:02X} ", b);
    }

    println!("");
}

fn main() {
    let mut array = [0; 16];

    for (i, b) in array.iter_mut().enumerate() {
	*b = i as u8;
    }

    print_slice(&array);
}
