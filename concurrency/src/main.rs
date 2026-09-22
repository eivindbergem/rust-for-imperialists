use std::{ops::DerefMut, sync::{Mutex, atomic::AtomicUsize}};

fn main() {
    let mut value = AtomicUsize::new(0);

    std::thread::scope(|s| {
        // let handle = s.spawn(|| {
        //     println!("Hello from thread!");
        //     println!("Value: {}", value);
        // });

	for _ in 0..10 {
	    s.spawn(|| {
		// let mut value = value.lock().unwrap();
		// *value.deref_mut() += 1;
		value.fetch_add(1, std::sync::atomic::Ordering::Relaxed);
	    });
	}
        // handle.join().unwrap();
    });

    println!("Hello from main!");
    println!("Value: {}", value.load(std::sync::atomic::Ordering::Relaxed));
}

