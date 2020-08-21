all: bulk test

bulk:
	rm -rf build/ || continue
	mkdir build/
	cd build && g++ -c ../source/*.cpp -o BitUtil.o -I../include
	cd build && ar rcs ../lib/BitUtil.a BitUtil.o

test:
	cd build && g++ -c ../test.cpp -o test.o -I../include
	cd build && g++ -o test test.o ../lib/BitUtil.a
	./build/test

clean:
	rm -rf build/ || continue
