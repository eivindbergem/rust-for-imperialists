use std::ffi::c_void;

unsafe extern "C" {
    unsafe fn malloc(len: usize) -> *mut c_void;
    unsafe fn free(ptr: *mut c_void);
}


struct Buffer {
    ptr: *mut u8,
    len: usize,
}

impl Buffer {
    fn new(len: usize) -> Self {
	let ptr = unsafe {
	    malloc(len)
	};

	assert!(!ptr.is_null());

	let ptr = ptr as *mut u8;

        Self { ptr, len }
    }

    fn as_slice(&self) -> &[u8] {
	unsafe {
	    std::slice::from_raw_parts(self.ptr, self.len)
	}
    }

    fn as_slice_mut(&mut self) -> &mut [u8] {
	unsafe {
	    std::slice::from_raw_parts_mut(self.ptr, self.len)
	}
    }
}

impl Drop for Buffer {
    fn drop(&mut self) {
        unsafe { free(self.ptr as *mut c_void) }
    }
}

fn free_buffer(_buffer: Buffer) {}

fn print_buffer(buffer: &Buffer) {
    print!("Buffer: ");
    for b in buffer.as_slice() {
	print!("{:02X?} ", b);
    }

    println!("");
}

fn main() {
    let mut buffer = Buffer::new(16);

    let slice_mut = buffer.as_slice_mut();

    for (i, b) in slice_mut.iter_mut().enumerate() {
	*b = i as u8;
    }

    print_buffer(&buffer);

    free_buffer(buffer);

    // // Use after free, not allowed by compiler
    // print_buffer(&buffer);
}
