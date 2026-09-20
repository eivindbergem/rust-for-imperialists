# Iterators

Iterating over values in C is done using `for` or `while` loops. A
common pattern is to increase a counter and use this value to index an
array. In Rust, iteration is a bit different.

## The `Iterator` trait

The main building block for iteration is done using the
[`Iterator`](https://doc.rust-lang.org/std/iter/trait.Iterator.html)
trait. The `Iterator` trait has one required method, as well as a lot
of provided methods:

```
trait Iterator {
    type Item;
	
	fn next(&mut self) -> Option<Self::Item>;
}
```

Calling `next()` yields the next item. The iterator is exhausted when
`next()` returns `None`.

When we are using `for` in Rust, we are calling into
`Iterator::next()` under the hood. The for loop actually uses the
trait
[`IntoIterator`](https://doc.rust-lang.org/std/iter/trait.IntoIterator.html),
calling `into_iter()` to get an `Iterator` for the type, then calls `next()`
repeatedly on the iterator.

```Rust
let values = &[42, 43, 44];

for value in values {
    println!("value: {}", value);
}
```

is syntactic sugar for

```Rust
let values = &[42, 43, 44];
let mut iter = values.into_iter();

loop {
    match iter.next() {
	    Some(value) => println!("value: {}", value),
		None => break,
	}
}
```

Using `..` we create a `Range` that we can iterate over:

```Rust
for i in 0..16 {
    println!("i: {}", i);
}

```

The `Iterator` trait also comes with a lot of provided methods, such
as `map()` and `filter()`, which originate from functional
programming. The function signature of `map()` looks like this:

```Rust
fn map<B, F>(self, f: F) -> Map<Self, F> ⓘ
where
    F: FnMut(Self::Item) -> B;
```

It takes a closure that transforms the item into `B`. For instance, we
could transform `u32`'s to `float`'s:

```Rust
for i in (0..16).map(|i| i as f32) {
    println!("i: {}", i);
}
```

Most of these functions return another iterator, so we can chain
multiple steps together. The operations are lazy evaluated, so no
action is performed before you iterate over the values:

```Rust
let iter = (0..16).filter(|i| (i % 2) == 0).map(|i| i**2);

// Nothing happened yet

for i in iter {
    println!("i: {}", i);
}
```

## Rewrite in Rust

In the C code we have implemented a simple iterator that demonstrates
how Rust iterators work. The iterator is an object that keeps track
how many elements are left and what is the next item. In the C version
we use an error code to signal iterator exhaustion, while in Rust we
use `None`.

We'll do this rewrite step by step, starting at something more C like
and ending up with a more idiomatic Rust solution.

### 1. `for i in 0..n`

Use a for loop to iterate over a range of indices and index each item
like in C.

### 2. `for value in array`

Use a for loop to iterator over each item. To get the indices as well,
use `enumerate()`:

```Rust
for (i, value) in array.into_iter().enumerate() {
    [...]
}
```

### 3. Chaining iterators

Calculate the sum in a single chained iterator expression using
`enumerate()`, `map()` and `sum()`.
