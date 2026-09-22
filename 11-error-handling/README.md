# Error handling

In C, error handling is done with error codes. In C it's no uncommon
to return errors in band with a value. For instance, if a function
returns a positive integer, it returns a negative error code on
failure.

## `Result`

In Rust we use [`Result`](https://doc.rust-lang.org/std/result/) for
functions that might fail:

```Rust
enum Result<T, E> {
    Ok(T),
	Err(E),
}
```

If we just want the value, we can use `unwrap()`:

```Rust
let result = function_returing_result();
let value = result.unwrap();
```

If the `Result` is `Err`, the program will print the error and
panic. It should be used with care, but is very useful during
prototyping.

## Errors

Rust errors are just regular types. The standard library comes with
lots of error types, such as
[`std::io::Error`](https://doc.rust-lang.org/std/io/struct.Error.html)
for all IO errors from the OS. You can make your own error types. It
is typical to use enums for errors:

```Rust
enum MyErrorType {
    InvalidArgument,
	IntTooBig(usize),
```

## The `?` operator

Early returns because of errors is a common pattern. In Rust there is
a special operator that we can use:

```Rust
fn this_could_fail() -> Result<u32, SomeError> {
	other_function_that_could_fail()?;
	
	Ok(42)
}
```

which desugars to:

```Rust
fn this_could_fail() -> Result<u32, SomeError> {
	match other_function_that_could_fail() {
	    Ok(ret) => ret,
		Err(err) => return SomeError::from(err),
	}
	
	Ok(42)
}
```

## Error propagation

In C error propagation is easy. Errors are just an int, so you can
just pass it on as is. In Rust errors are types, and a function might
call functions return different error types:

```Rust
fn some_function() -> Result<u32, SomeError>;
fn some_other_function() -> Result<u32, SomeOtherError>;

fn my_function() -> Result<u32, [...]> {
    let value = some_function()?;
	let other_value = some_other_function()?;
	
	Ok(value + other_value)
}
```

So what error should `my_function()` return? One common strategy is to
create an enum that wraps the other errors:

```Rust
enum MyError {
    Some(SomeError),
	SomeOther(SomeOtherError),
}
```

Then we can use the `From` trait to get conversion:

```Rust
impl From<SomeError> for MyError {
    fn from(value: SomeError) -> Self {
	    MyError::Some(SomeError)
	}
}
```

Now, this will work:

```Rust
fn some_function() -> Result<u32, SomeError>;
fn some_other_function() -> Result<u32, SomeOtherError>;

fn my_function() -> Result<u32, MyError> {
    let value = some_function()?;
	let other_value = some_other_function()?;
	
	Ok(value + other_value)
}
```

## Reading from stdin

```Rust
let stdin = std::io::stdin();
let mut s = String::new();
stdin.read_line(&mut s)?;
```
