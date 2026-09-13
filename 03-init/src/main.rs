struct User {
    uid: i32,
    gid: i32,
}

impl User {
    fn new(uid: i32) -> Self {
        let gid = if uid % 2 == 0 { uid } else { 1 };
        Self { uid, gid }
    }
}

fn print_user(user: &User) {
    println!("User, id: {}, gid: {}", user.uid, user.gid);
}

fn main() {
    let user = User::new(42);

    print_user(&user);
}
