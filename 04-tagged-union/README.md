# Task 4 – Tagged union

A tagged union is a data structure that can hold several different
types, but only one variant at a time. In C we use an `enum` for the
tag, and a `union` for the associated data.

The starting point for this task is a tagged union used to encode
different shapes: circles, rectangles and triangles.

## 1. Re-write in Rust

While Rust has support for C-style unions, they require `unsafe`. We
will instead use rust enums, as they provide a safe tagged
union. Under the hood, Rust enums are implement in the same way as the
tagged union we implemented in C. Rust enum variants can also hold data:

```Rust
enum Example {
    UnitVariant,
	TupleVariant(usize),
	StructVariant { field: u32 },
}
```

As we can see from the example, enum variants can be one of three
different types. Re-write the tagged union `shape_t` as a Rust-style
enum. `area()` and `shape()` should be implemented as methods on
`Shape`:

```Rust
enum Shape {
[...]
}

impl Shape {
    fn area(&self) -> float;
	fn name(&self) -> &'static str;
}
```

To unpack an enum, use `match`:

```Rust
match value {
    UnitVariant => println!("Unit variant"),
	Tuplevariant(arg) => println!("Tuple variant, arg: {}),
	StructVariant { field } => println!("Struct variant: field: {}"),
}
```

Remember that in Rust, everything is an expression, so a `match` will
evaluate to final expression in each arm, requiring that the are of
the same type.
