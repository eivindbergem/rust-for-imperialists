#[derive(Clone, Copy)]
struct Item {
    value1: i32,
    value2: i32,
}

fn print_item(item: &Item) {
    println!("value1: {}, value2: {}",
	     item.value1, item.value2);
}

fn add_one(item: &mut Item) {
    item.value1 += 1;
    item.value2 += 1;
}

fn add_one_copy(mut item: Item) -> Item {
    item.value1 += 1;
    item.value2 += 1;

    item
}

fn main() {
    let mut item = Item {
        value1: 42,
        value2: 43,
    };

    print_item(&item);
    add_one(&mut item);
    print_item(&item);

    let item_copy = add_one_copy(item);
    print_item(&item);
    print_item(&item_copy);
}
