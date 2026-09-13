# Task 2 – Pointers, references, ownership and borrowing

C uses pointers extensively. The example program shows some ways of
using pointers to access and modify fields. It also shows the copy
semantics when passing by value.

## 1. Re-write in Rust

Use cargo to create a cargo crate: `cargo init --name
pointers`.

Variables in Rust are declared using `let`:
```Rust
let x = 42;
```

The type is usually inferred, but can also be specified:

```Rust
let x: i32 = 42;
```

In rust we usually work with references, not pointers. A reference is
like a pointer, but with additional safety and limitation. In Rust,
working directly with pointers requires using unsafe. For this task,
we'll use references. References are created using `&`:

```Rust
let x = 42;
let y = &x;
```

Try to do a one-to-one mapping of the program into Rust. Your program
will likely not compile du to the Rust borrow checker.

## 2. Mutability

Rust variables are immutable by default. To declare a mutable
variable:
```Rust
let mut x = 42;
```

Now you can get a mutable reference:

```Rust
let mut x = 42;
let y = &mut x;
```

Use a mutable reference for the `add_one()` function.

## 3. Ownership

When passing `item` to `print_item()` after calling `add_one_copy()`,
you'll get an error. Rust, in contrast with C, has move semantics by
default. In C, values are copied. In Rust, we transfer
ownership. Using the old binding after a move is not allowed, and
results in a compiler error.

Primitive types, however, behave differently, and have copy
semantics. We can make our struct `Copy` as well by using a derive
macro:

```Rust
#[derive(Clone, Copy)]
struct Item {
[...]
}
```

`Copy` is a trait – we'll get back to traits later – that tells the
compiler that the struct will be copied, and not moved. When our
struct is `Copy`, we get rid of the error. `Copy` requires `Clone`, so
we have to add that as well.
