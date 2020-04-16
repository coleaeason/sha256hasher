# Set the compiler, if it's not set by the environment.
ifndef GXX
	GXX = g++-9
endif

ifndef CC
	CC = gcc-9
endif

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
PATHS=-I/usr/local/opt/openssl/include -L/usr/local/opt/openssl/lib
endif

all: sha256hasher

clean:
	rm -f sha256hasher
	rm -rf sha256hasher.dSYM

sha256hasher: sha256hasher.cpp
	$(GXX) -g -std=c++14 sha256hasher.cpp -O2 -o sha256hasher $(PATHS) -lcrypto -lpthread
