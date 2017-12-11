all: build doczip

build: collegemain.o college.o course.o 
	g++ collegemain.o college.o course.o -o build

collegemain.o: collegemain.cc college.h course.h node.h
	g++ -c collegemain.cc college.h course.h node.h

college.o: college.h college.cc course.h node.h
	g++ -c college.h college.cc course.h node.h

course.o: course.h course.cc
	g++ -c course.h course.cc

doczip: 
	tar cvzf archive_file.tar.gz collegemain.o college.o course.o collegemain.cc college.h college.cc course.h course.cc node.h tarray.h makefile

myexe:
	./build

doc:
	doxygen -g index.html
	doxygen index.html

clean:
	rm -rf *.o a.out archive_file.tar.gz html latex build college.h.gch course.h.gch node.h.gch

#node.h.gch tarray.h.gch