HDFEOS_PATH=/usr/local
INC=-I$(HDFEOS_PATH)/include
LIB=-L$(HDFEOS_PATH)/lib -lhdfeos -lGctp -lmfhdf -ldf -ljpeg -lz -lm

build:
	docker build -t geonex/hdfeos .
push:
	docker push geonex/hdfeos
pull:
	docker pull geonex/hdfeos
run:
	docker run --rm -it \
		-v ${PWD}:/ext \
	geonex/hdfeos /bin/bash
test:
	gcc read_datafield_grid_AE_RnGd.c $(INC) $(LIB)
	./a.out