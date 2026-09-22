# Strings

Strings are handled very differently in Rust compared to C. In C, a
string is just a pointer to a NULL-terminated sequence of bytes. There
is no metadata holding the length of the string, to calculate the
string length you need to iterate over the bytes until you reach the
NUL byte. C has no real concept of UTF-8, but treating strings as
bytes works most of the time.

## `&str` and `String`

Rust has two string types. `&str` is a borrowed string, while `String`
is a heap-allocated owned string. String literals have the type
`&'static str`, that is, a borrwed string with a `static` lifetime. We
can create a `String` from a `&str` using `String::from()`. Borrowing
a `String` will get you a `&str`, so functions taking strings should
take `&str` unless ownership is required:

```Rust
fn print_string(s: &str) {
	println!("String: '{}'", s);
}

fn main() {
    let s = String::from("some string");
	
	print_string(&s);
}
```

Both `String` and `&str` are always valid UTF-8.

To access to bytes of
a string, use
[`str::as_bytes()`](https://doc.rust-lang.org/std/primitive.str.html#method.as_bytes).

## `char`

A rust `char` is not a byte, but a Unicode scalar value. You can get
an iterator over `char`'s in a string using
[`str::chars()`](https://doc.rust-lang.org/std/primitive.str.html#method.chars).

## Rewrite in Rust

Allocating a string on the stack in Rust is a bit more involved since
string must be valid UTF-8. Use this function:

```Rust
fn write_to_static<'a>(buffer: &'a mut [u8], s: &str) -> &'a str {
    let buffer = &mut buffer[..s.len()];
    buffer.copy_from_slice(s.as_bytes());
    std::str::from_utf8(buffer).unwrap()
}
```

It takes a mutable reference to an array and a string literal. It
copies the bytes of the string literal over to the array. Then, we
create a string from the array. This method is fallible, in case the
the sequence of bytes is not valid UTF-8. We use `unwrap()` to panic
in case of an error.
