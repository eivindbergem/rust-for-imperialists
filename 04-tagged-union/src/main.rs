use std::f32::consts::PI;

enum Shape {
    Circle { radius: f32 },
    Rectangle { width: f32, height: f32 },
    Triangle { base: f32, height: f32 },
}

impl Shape {
    fn area(&self) -> f32 {
        match self {
            Shape::Circle { radius } => PI * radius * radius,
            Shape::Rectangle { width, height } => width * height,
            Shape::Triangle { base, height } => (base * height) / 2.0,
        }
    }

    fn name(&self) -> &'static str {
        match self {
            Shape::Circle { radius: _ } => "circle",
            Shape::Rectangle { width: _, height: _ } => "rectangle",
            Shape::Triangle { base: _, height: _ } => "triangle",
        }
    }
}

fn print_shape(shape: &Shape) {
    println!("Shape is a {} with an area of {}",
	     shape.name(), shape.area());
}

fn main() {
    let circle = Shape::Circle { radius: 4.5 };
    let rectangle = Shape::Rectangle { width: 3.6, height: 6.8 };
    let triangle = Shape::Triangle { base: 5.3, height: 2.3 };

    print_shape(&circle);
    print_shape(&rectangle);
    print_shape(&triangle);
}
