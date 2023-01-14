CFLAGS = -lglfw3 -ldl -lm -lGL -lGLU -lX11
GFLAGS = -pthread
output: hello.o

hello.o: hello.cpp 
	g++ ${GFLAGS} -o hello.o hello.cpp ${CFLAGS}

clean: 
	rm *.o