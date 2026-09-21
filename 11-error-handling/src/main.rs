use std::{io::Write, num::ParseIntError};

#[derive(Debug)]
enum Error {
    Io(std::io::Error),
    Parse(ParseIntError),
}

impl From<std::io::Error> for Error {
    fn from(value: std::io::Error) -> Self {
	Self::Io(value)
    }
}

impl From<ParseIntError> for Error {
    fn from(value: ParseIntError) -> Self {
	Self::Parse(value)
    }
}

fn read_positive_integer() -> Result<u32, Error> {
    let stdin = std::io::stdin();
    let mut buf = String::new();

    print!("Enter a number: ");
    std::io::stdout().flush()?;

    stdin.read_line(&mut buf)?;

    let number: u32 = buf.trim().parse()?;

    Ok(number)
}

fn main() {
    match read_positive_integer() {
        Ok(number) => println!("Read: {}", number),
        Err(err) => println!("Error: {:?}", err),
    }
}
