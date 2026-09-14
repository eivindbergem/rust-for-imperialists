fn get_string(flag: bool) -> Option<&'static str> {
    if flag {
	Some("All your base are belong to us")
    } else {
	None
    }
}

fn print_string(s: Option<&str>) {
    match s {
        Some(s) => println!("{}", s),
        None => println!("Error: string is None!"),
    }
}

fn main() {
    print_string(get_string(false));
    print_string(get_string(true));
}
