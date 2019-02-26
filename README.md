# About geonex/pyhdfeos

The [HDF-EOS data format](https://hdfeos.org/help/faq/whatis_eos.php) is standard HDF with ECS conventions, data types, and metadata added. HDF-EOS adds three geolocation data types (point, grid, and swath) which allow the file contents to be queried by earth coordinates and time. HDF-EOS is implemented as a C library extension of the standard HDF library. However, it is very frustrated to get the HDF-EOS C library installed with dependency issue.

In the sense, geonex/pyhdfeos is an easy way to manipulate HDFEOS format, and wrapper their functionalities as python functions using SWIG.

Please go check pyhdfeos.c, pyhdfeos.h, pyhdfeos.i for details.

More !NumPy and SWIG examples can be found [here](https://scipy-cookbook.readthedocs.io/items/SWIG_NumPy_examples.html).

# Get Started

## Prerequisites
Install Docker following the installation guide for your platform: [https://docs.docker.com/engine/installation/](https://docs.docker.com/engine/installation/)

You can use a series of docker commands to get hdfeos working:

1. clone this repo
```
git clone https://github.com/suredream/geonex-hdfeos-docker.git
```

2. build/pull the geonex/pyhdfeos image

```
make pull
```

or 

```
docker pull geonex/pyhdfeos
```

3. make sure you have geonex/hdfeos image on your system
```
docker images
```

4. quick test
```
$ make run                           # enter docker container 
$ root@d8a1d4eb64af:/# cd ext
$ root@d8a1d4eb64af:/# make test     # test gcc compiler under pyhdfeos building environment and run test.py example.
```


# Contact
- Jun Xiong, NASA Ames Research Center / BAERI
- [Email to me:](mailto:xiong@baeri.org)
