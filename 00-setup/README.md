# Setting up the development environment

## Rust

Follow the instructions here: https://rust-lang.org/tools/install/

The site should show instructions appropriate for your operating
system. When you have installed Rust, run `cargo run` in this
directory. You should see something like this:

```
   Compiling setup v0.1.0 (/Users/Eivind.Bergem/projects/c-for-imperialists/00-setup)
    Finished `dev` profile [unoptimized + debuginfo] target(s) in 0.80s
     Running `target/debug/setup`
It works!
```

## VSCode

It's recommended that you use VSCode for this workshop. If you want to
use a different editor, that is fine, but then you'll have to figure
out how to get rust-analyzer working on your own.

### Rust analyzer

Rust analyzer is an implementation of LSP for Rust. It will give you a
better experience when programming. Follow instructions here for how
to install for VSCode: https://code.visualstudio.com/docs/languages/rust
