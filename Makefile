all: bulk

bulk:
	rm -rf build/ || continue
	mkdir build/
	cd build && g++ -c ../source/*.cpp -o BitUtil.o -I../include
	mkdir lib || continue
	cd build && ar rcs ../lib/libbit.a BitUtil.o

test:
	cd build && g++ ../test.cpp -o test -I../include -L../lib -lbit
	./build/test

clean:
	rm -rf build/ || continue
	rm -rf lib || continue