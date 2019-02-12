FROM debian:jessie

MAINTAINER NASA NEX Team<junxiong360@gmail.com>

ENV HOME /root

RUN apt-get update
RUN apt-get -yq install gcc \
                        build-essential \
                        wget \
                        bzip2 \
                        tar \
                        libghc-zlib-dev \
                        libjpeg-dev \
                        gfortran \
                        bison \
                        flex \
                        file

#Build HDF4
RUN wget https://observer.gsfc.nasa.gov/ftp/edhs/hdfeos/latest_release/hdf-4.2.13.tar.gz; \
    tar zxvf hdf-4.2.13.tar.gz; \
    cd hdf-4.2.13; \
    ./configure --prefix=/usr/local/; \
    make && make install; \
    cd ..; \
    rm -rf /hdf-4.2.13 /hdf-4.2.13.tar.gz 

#Build HDF-EOS2
RUN wget https://observer.gsfc.nasa.gov/ftp/edhs/hdfeos/latest_release/HDF-EOS2.20v1.00.tar.Z; \
    tar zxvf HDF-EOS2.20v1.00.tar.Z; \
    cd hdfeos; \
    ./configure --prefix=/usr/local/ --enable-install-include --with-hdf4=/usr/local; \
    make && make install; \
    cd ..; \
    rm -rf /hdfeos /HDF-EOS2.20v1.00.tar.Z