# Task 1 – Hello, World!

In this directory you will find a hello world application written in C
with a simple makefile. The task here is to create a Rust equivalent.

## 1. Hello, Rust!
Start by creating a file called `src/main.rs`. Create a main function
with the signature `fn main()`. Use the `println!()` macro to print
"Hello, Rust!".

The rust compiler is called `rustc` and takes similar arguments to
`gcc`. Add a target called `hello-rust` in the makefile, using `rustc`
to compile the program.

## 2. Cargo

We usually don't use `rustc` or write makefiles for Rust
projects. Rust comes with it's own build tool called `cargo`, which is
configured using a file named `Cargo.toml`.

Create a minimal `Cargo.toml`:

```
[package]
name = "hello-rust"
version = "0.1.0"
edition = "2024"
```

Run `cargo run` to see that it works.

You can also use `cargo new` or `cargo init` to create a new cargo
project. `cargo-new` will create a directory for you, while `cargo
init` will create a `Cargo.toml` file for you. Try deleting
`Cargo.toml` and run `cargo init --name hello-rust`. Look at
`Cargo.toml` and try running `cargo run` again.
