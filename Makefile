# Set the compiler, if it's not set by the environment.
ifndef GXX
	GXX = g++-6
endif

ifndef CC
	CC = gcc-6
endif

all: sha256hasher

clean:
	rm -rf sha256hasher

sha256hasher: sha256hasher.cpp
	$(GXX) -g -std=gnu++14 sha256hasher.cpp -O2 -o sha256hasher -lcrypto -lpthread
