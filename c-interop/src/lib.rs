use std::ffi::{CString, c_char};


#[unsafe(no_mangle)]
#[repr(C)]
pub struct Test {
    byte: u8,
    word: u32,
    another_u8: u8,
    s: *const c_char,
}

#[unsafe(no_mangle)]
pub extern "C" fn add_one(value: u32) -> u32 {
    value + 1
}

#[unsafe(no_mangle)]
pub extern "C" fn get_test() -> Test {
    Test {
        byte: 42,
        word: 4242424242,
        another_u8: 43,
        s: c"all you base are belong to us".as_ptr(),
    }
}

