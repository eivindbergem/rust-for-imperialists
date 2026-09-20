fn transform<F>(value: u32, f: F) -> u32
where
    F: Fn(u32) -> u32,
{
    f(value)
}

fn main() {
    let factor = 3;

    let value = transform(5, |value| value * factor);
    println!("Value: {}", value);
}
