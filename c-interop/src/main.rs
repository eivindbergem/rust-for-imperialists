unsafe extern "C" {
    unsafe fn c_main() -> i32;
}

fn main() {
    unsafe { c_main(); }
}

#[unsafe(no_mangle)]
pub extern "C" fn add_one(value: u32) -> u32 {
    value + 1
}

// #[panic_handler]™
// fn panic(_info: &core::panic::PanicInfo) -> ! {
//     loop {}
// }
