.PHONY: all clean

all:
	cmake -S . -B build/ -G Ninja

install:
	ninja -C build/

clean:
	ninja -C build -t clean
	rm -f admin.txt student.txt tutor.txt center.txt subject.txt
