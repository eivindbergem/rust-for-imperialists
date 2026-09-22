# Task 6 – Memory allocation

In C we have to manage memory allocations manually, carefully making
sure that memory is freed and avoiding to use after free. Rust manages
this for us, at compile time, without the use of a garbage
collector. In this task we will use `malloc()` and `free()` from Rust
to show how Rust's memory management works under the hood.

## `libc`

In order to use `malloc()` and `free()` we need to access `libc`. Rust
is already linked against `libc`, so we just have to provide the
function signatures to able to call the functions. Add this to your
`main.rs`:

```Rust
unsafe extern "C" {
    unsafe fn malloc(len: usize) -> *mut c_void;
    unsafe fn free(ptr: *mut c_void);
}
```

## `unsafe`

You might notice that both `malloc()` and `free()` are marked as
unsafe. All foreign functions in Rust are considered unsafe, because
the Rust compiler cannot analyze the contents of them. In order to
call an unsafe function, we need to put it in an `unsafe` block:

```Rust
let ptr = unsafe { malloc(128) };
```

In safe Rust, the compiler makes sure that there is no undefined
behaviour – such as use after free, dereferencing NULL pointers, or an
enum with an invalid tag – but when we us unsafe, it's on us to ensure
that there is no undefined behaviour.

## Raw pointers

When we call `malloc()`, we get a raw pointer, `*mut c_void`, which
corresponds to `void*` in C. Since Rust lacks a native void type,
`c_void` is provided by the standard library for C interop. In order
to do anything with a raw pointer, we need to dereference it:

```Rust
fn deref_ptr(ptr: *mut usize) -> usize {
	unsafe {
	    *ptr
	}
}
```

Dereferencing a raw pointer requires `unsafe` because the pointer
might be invalid and cause undefined behaviour.

## Slices

A slice – `&[T]` – is Rust type that gives a view into a contigous
collection of element. A slice is a wide pointer containing both a
pointer and a size, just like our `buffer_t` in the C program. To
create a slice we use [`std::slice::from_raw_parts()`](https://doc.rust-lang.org/std/slice/fn.from_raw_parts.html):

```Rust
let slice = unsafe { from_raw_parts(ptr, len) };
```

To get a mutable slice – `&mut [T]` – we use
[`std::slice::from_raw_parts_mut()`](https://doc.rust-lang.org/std/slice/fn.from_raw_parts_mut.html):

## Drop

Rust has a concept called _traits_. Traits are similar to what is
called _interfaces_ in many other languages. A trait is a way to
define shared behaviour between different types. `Drop` is a trait
that is built in to the language. The definition of `Drop` looks like
this:

```Rust
trait Drop {
    fn drop(&mut self);
}
```

This means that any type that implements `Drop` has the `drop()`
method. When a value goes out of scope, `drop()` is called
implicitly. We can implement `Drop` on our own types:

```Rust
impl Drop for MyType {
    fn drop(&mut self) {
	    // Do some clean up here
	}
}
```

## Putting it all together

Create `Buffer`, a struct corresponding to `buffer_t`. Add these
methods on `Buffer`:

```Rust
impl Buffer {
    // Constructor. Call malloc in here.
    fn new(len: usize) -> Self;
    
	// Return buffer as a slice
	fn as_slice(&self) -> &[u8];
	
	// Return buffer as a mutable slice
	fn as_slice_mut(&mut self) -> &mut [u8];
}
```

Implement `Drop` for `Buffer` calling `free()` in `drop()`.
