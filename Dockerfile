# Use GCC official image
FROM gcc:11

COPY . ./usr/src/aztroz-game

WORKDIR ./usr/src/aztroz-game

RUN apt-get update

# Installs the SDL2 library
RUN apt-get install -y libsdl2-dev

# Installs the SDL2 Image library, for some reason they are separated
RUN apt-get install -y libsdl2-image-dev

# Create the "objects" folder required by the makefile
RUN mkdir objects

RUN make

EXPOSE 8080

CMD ["sleep", "infinity"]