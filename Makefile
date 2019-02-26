HDFEOS_PATH=/usr/local
INC=-I$(HDFEOS_PATH)/include
LIB=-L$(HDFEOS_PATH)/lib -lhdfeos -lGctp -lmfhdf -ldf -ljpeg -lz -lm
sLIB=-L$(HDFEOS_PATH)/lib -lhdfeos -lGctp -lmfhdf -ldf -ljpeg -lz -lm -shared -fPIC

build:
	docker build -t geonex/pyhdfeos .
push:
	docker push geonex/pyhdfeos
pull:
	docker pull geonex/pyhdfeos
run:
	docker run --rm -it \
		-v ${PWD}:/ext \
	geonex/pyhdfeos /bin/bash
test:
	# swig -python example.i
	# gcc -fPIC -c example.c example_wrap.c \
    #     -I/usr/include/python2.7
	# ld -shared example.o example_wrap.o -o _example.so 
	rm -fr build
	python setup.py build
	cp build/lib.linux-x86_64-2.7/_pyhdfeos.so .
	python test.py
clean:
	rm -fr build
	rm -f *.o *.so *.pyc
	rm -f pyhdfeos.py pyhdfeos_wrap.c