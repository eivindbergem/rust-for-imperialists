# Function pointers

Function pointers are used in C as a form of generic
programming. However, C lacks support for anonyomous functions and
closures.

## Anonymous functions

An anonymous function is a function that is not named. In Rust, we can
create an anonymous function like this:

```Rust
let fn = |arg| { println!("Arg is: {}") };

fn(42);
```

Anonymous functions are callable objects, and can be used like any
other variable.

## Closures

A _closoure_ is an anonymous function that captures data from the
environment in which is it is defined:

```Rust
let value = 42;

let fn = |arg| {
    let result = arg * value;
    println!("Result is: {}", result);
};

fn(3);
```

By default, values are captured _by reference_, so `value` is borrowed
by fn. If we instead want move semantics, we can use ´move`:

```Rust
let value = 42;

let fn = move |arg| {
    let result = arg * value;
    println!("Result is: {}", result);
};

fn(3);
```

## `Fn`, `FnMut` and `FnOnce`

When we create a closure, the closure has a type. But, this type is
not nameable because it is a product of the function body and the
values it captures. To work with closures, there are three traits:

- `Fn`: Closures capturing shared references `&T`
- `FnMut`: Closures capturing mutable references `&mut T`
- `FnOnce`: Closures taking ownership and consuming values. Can only
   be called once.

We can use these traits to take a closure as an argument:

```Rust
fn perform_op<F>(f: F)
where
    F: Fn(u32) -> u32 
{
    println!("f(42): {}", f(42));
}
```

## Rewrite in Rust

Instead of passing `args_t`, use a closure that captures `factor` from
it's environment.
