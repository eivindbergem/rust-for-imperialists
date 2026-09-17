# Generic types

While C lacks support for generic types, it has support for generic
programming using void pointers. Using this pattern, you get a manual
form of dynamic dispatch. Rust has support for generic types,
including both static and dynamic dispatch. In this task we will
convert the C dynamic dispatch into static dispatch in Rust. The
resulting programs will not be identical, but works in a similar way.

## Generic arguments

A function can take generic arguments:

```Rust
fn identity<T>(item: T) -> T {
    item
}
``` 

Generic parameters are declared between the the angled brackets, and
can then be used like any type. Since we don't know anything about the
underlying type, it is a bit limited what we can do with generics
alone, except to write an identity function. To do anything useful
with generics, we need _traits_.

## Traits

A _trait_ is a way to define shared behaviour between different
types. It is similar to what is called _interfaces_ in many other
languages. As an example, let's make a trait for `Pet`:

```Rust
trait Pet {
    fn name(&self) -> &str;
	fn sound() -> &'static str;
}
```

We can then define a pet:

```Rust
struct Cat {
    name: String,
}

impl Cat {
    fn new(name: &str) -> Self {
	    Self {
		    name: name.to_owned(),
		}
	}
}

impl Pet for Cat {
    fn name(&self) -> &str {
	    &self.name
	}
	
	fn sound() {
	    "meow"
	}
}
```

and then use it:

```Rust
let felicette = Cat::new("Félicette");

println!("My pet is named {} and says {}", felicette.name(), felicette.sound());
```

This is neat, but where traits are really useful is when combined with
generics. We can add a _trait bound_ on a generic parameter:

```Rust
fn introduce_pet<P: Pet>(pet: P) {
    println!("My pet is named {} and says {}", pet.name(), pet.sound());
}
```

Since we know that `P` implements `Pet`, we know that it has the
methods `name()` and `sound()`. This method will work for any `P` that
implements `Pet`, not just `Cat` but also `Dog` and `Tiger`.

Trait bounds can also be defined in a where clause, which aids in
readability for more complex generic types:

```Rust
fn introduce_pet<P>(pet: P)
where
    P: Pet
{
    println!("My pet is named {} and says {}", pet.name(), pet.sound());
}
```


Rust uses static dispatch for generics. This means that for each type,
a separate function is being generated and compiled into the
binary. So if we use `introduce_pet()` with `Cat` and `Dog`, we get
two functions generated under the hood:

```Rust
fn introduce_pet_cat(pet: Cat) {
    println!("My pet is named {} and says {}", pet.name(), pet.sound());
}

fn introduce_pet_dog(pet: Dog) {
    println!("My pet is named {} and says {}", pet.name(), pet.sound());
}
```

The real names are mangled, so they will look more like
`introduce_pet39ouuf3fio3()`. Rust also supports dynamic dispatch
using the `dyn` keyword, but that is not covered by this workshop.

## Traits vs enums

This task is a bit similar to the earlier tagged union task. We have a
set of different shapes and define some shared functionality. The
difference is enums are a closed set – a user of the shape library
cannot add a shape to the enum – while traits are an open set. You can
implement traits defined in a different library for your own types.

## Re-write in Rust

Define a trait ´Shape`:

```Rust
trait Shape {
    fn area(&self) -> f32;
    fn name() -> &'static str;
}
```

Add structs for `Circle`, `Rectangle` and `Triangle`. Implement
`Shape` for the shapes.

Create a function to print shapes:

```Rust
fn print_shape<T: Shape>(shape: &T);
```
