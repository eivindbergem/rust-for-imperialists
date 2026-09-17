use core::f32;

trait Shape {
    fn area(&self) -> f32;
    fn name() -> &'static str;
}

struct Circle {
    radius: f32,
}

impl Shape for Circle {
    fn area(&self) -> f32 {
        f32::consts::PI * self.radius * self.radius
    }

    fn name() -> &'static str {
        "circle"
    }
}

struct Rectangle {
    width: f32,
    height: f32,
}

impl Shape for Rectangle {
    fn area(&self) -> f32 {
        self.width * self.height
    }

    fn name() -> &'static str {
        "rectangle"
    }
}

struct Triangle {
    base: f32,
    height: f32,
}

impl Shape for Triangle {
    fn area(&self) -> f32 {
        (self.base * self.height) / 2.0
    }

    fn name() -> &'static str {
        "triangle"
    }
}

fn print_shape<T: Shape>(shape: &T) {
    println!("Shape is a {} with an area of {}",
	     T::name(), shape.area());
}

fn main() {
    let circle = Circle {
        radius: 4.5,
    };
    let rectangle = Rectangle {
	width: 3.6,
	height: 6.8,
    };
    let triangle = Triangle {
	base: 5.3,
	height: 2.3,
    };

    print_shape(&circle);
    print_shape(&rectangle);
    print_shape(&triangle);
}
