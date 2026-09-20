# Slices

In C the distinction between arrays and pointers are blurred. Indexing
an array is just syntactic sugar for pointer arithmetic. In Rust we
have both _arrays_ – similar to C arrays – and _slices_ – a pointer
with a length.

## Arrays

Rust has arrays – `[N; T]` where `N` is the length of the array and `T`
is the item type. We can declare an array:

```Rust
let array = [0; 16];
```

to get an array of 16 items, each item initialized to 0.

## Slices

A slice – `&[T]` – is Rust type that gives a view into a contiguous
collection of element. A slice is a wide pointer containing both a
pointer and a size, just like `slice_t` in the C program.

We can pass a reference to an array to a function taking a slice:

```Rust
fn takes_slice(slice: &[u8]) {
    println!("The slice has {} items", slice.len());
}

fn main() {
    let array = [0; 42];
	
	takes_slice(&array);
}
```
