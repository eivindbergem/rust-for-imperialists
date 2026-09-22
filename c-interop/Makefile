RUSTLIB=../target/debug/libc_interop.a

main.o: src/main.c
	gcc -c $<

main: src/main.o $(RUSTLIB)
	gcc -o main $^

