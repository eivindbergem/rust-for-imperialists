fn print_string(s: &str) {
    println!("String: '{}'", s);
}

fn write_to_static<'a>(buffer: &'a mut [u8], s: &str) -> &'a str {
    let buffer = &mut buffer[..s.len()];
    buffer.copy_from_slice(s.as_bytes());
    std::str::from_utf8(buffer).unwrap()
}

fn count_bytes(s: &str) -> usize {
    s.len()
}

fn count_chars(s: &str) -> usize {
    s.chars().count()
}

fn main() {
    let literal = "string literal";
    let mut stack_array = [0; 32];
    let stack = write_to_static(&mut stack_array, "static allocation");

    let heap = String::from("heap allocation");

    print_string(literal);
    print_string(stack);
    print_string(&heap);

    let s = "æøå";

    println!("Bytes in '{}': {}", s, count_bytes(s));
    println!("Chars in '{}': {}", s, count_chars(s));

}
