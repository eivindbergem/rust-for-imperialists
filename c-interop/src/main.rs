mod external;

use external::c_main;
use c_interop::add_one;

fn main() {
    unsafe { c_main(); }

    let value = add_one(45);
    println!("{}", value);
}


// #[panic_handler]™
// fn panic(_info: &core::panic::PanicInfo) -> ! {
//     loop {}
// }
