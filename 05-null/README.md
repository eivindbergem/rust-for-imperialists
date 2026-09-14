# Task 5 – `NULL` pointers

Rust does not have `NULL`. Or, that's not entirely correct. In Rust,
references cannot be `NULL`. Raw pointers can be `NULL`, but they require
unsafe. So, in safe Rust, we don't have `NULL`.

## `Option`

So, if we don't have `NULL`, how do we return nothing? We use
`Option`. `Option` is an enum that is a part of the standard
library. It's definition looks like this:

```Rust
enum Option<T> {
    Some(T),
	None,
}
```

It has two variants, `Some` and `None`. It has a generic parameter
`T`, meaning that it can wrap any type. We can use it like this:

```Rust
let value: Option<usize> = Some(42);
```

As with all enums, we can use `match` to access the variants.

## Lifetimes

The `get_string()` function returns a pointer. In Rust, we'd return a
reference. But if you do this:

```Rust
fn some_function() -> &str {
    [...]
}
```

we'll get a compile error:

```
  |
1 | fn some_function() -> &str {
  |                       ^ expected named lifetime parameter
  |
```

References have lifetimes. Lifetimes make sure that what the reference
is pointing to lives at least as long as the reference, ensuring that
there are no danling pointers. Lifetime annotations are elided when
the compiler can infer them, but in this case we need to specify a
lifetime. Since the function returns a string literal, we can use the
`static` lifetime:

```Rust
fn some_function() -> &'static str {
    [...]
}
```

The `static` lifetime is a built-in lifetime that lives for the
duration of the program.
