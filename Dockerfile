# Use GCC official image
FROM gcc:11

COPY . ./usr/src/aztroz-game

WORKDIR ./usr/src/aztroz-game

ARG BUILD_ARCH=x86

RUN dpkg --add-architecture armhf
RUN apt-get update

# Install x86_64 packages
RUN echo "Adding packages for X86_64"
RUN apt-get install -y libsdl2-dev
RUN apt-get install -y libsdl2-image-dev

# Install packages for ARM
RUN echo "Adding packages for ARM"
RUN apt-get install -y gcc-arm-linux-gnueabihf
RUN apt-get install -y libsdl2-dev:armhf
RUN apt-get install -y libsdl2-image-dev:armhf

# Create the "objects" folder required by the makefile
RUN mkdir objects

RUN make ARCH=arm

EXPOSE 8080

CMD ["sleep", "infinity"]