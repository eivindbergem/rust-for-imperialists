# Task 3 – Struct initialization

A typical pattern in C is to declare a struct and then send a pointer
to a function to initialize it.

## 1. Re-write in Rust

Try to re-write the C program into Rust. You will encounter compiler
errors.

## 2. Uninitialized value

In Rust, we cannot use an uninitialized value, and that is enforced at
compile time. We can defer initialization locally within a function:

```Rust
let id;

if is_sudo() {
    id = 0;
} else {
    id = get_uid();
}
```

However, a more idiomatic approach is:

```Rust
let id = if is_sudo() {
    0
} else {
    get_uid()
};
```

In Rust, everything is an expression, even an if-statement.

We cannot pass an uninitialized value or reference to an
uninitialized value to another function.

## 3. Consructors

Rust doesn't have constructors in the way C++ has. However, there is
an idiomatic way to create a new object:

```Rust 
struct Wrapper {
    inner: usize
}

impl Wrapper {
    fn new(inner: usize) -> Self {
	    Self {
		    inner,
		}
	}
}
```

Now we can create a new `Wrapper` using `Wrapper::new()`. `Self` is a
just an alias for the type of the `impl` block, in this case
`Wrapper`. When the name of a field has the same name as a variable,
we can omit the mapping between field and variable. If their names
differ, the syntax is:

```Rust
Self {
    inner: some_value,
}
```

Replace `init_handle()` with a `new()` method.
