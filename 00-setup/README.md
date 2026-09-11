# Setting up the development environment

## Operating system

The example C programs requires a Unix-like environment with `gcc` in
`$PATH´. This can be:

- Linux
- MacOS
- Windows with WSL: https://learn.microsoft.com/en-us/windows/wsl/install

To verify your setup, run `make && ./setup`. It should print:
```
gcc -o setup src/main.c
It works!
```


## Rust

Install Rust by running this in your terminal:

```
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

When you have installed Rust, run `cargo run` in this directory. You
should see something like this:

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


### WSL

If you are on Windows, see instructions here on using WSL with VSCode:
https://learn.microsoft.com/en-us/windows/wsl/tutorials/wsl-vscode
