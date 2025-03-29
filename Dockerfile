# Use GCC official image
FROM gcc:11

COPY . ./usr/src/aztroz-game

WORKDIR ./usr/src/aztroz-game

ARG BUILD_ARCH=""

RUN dpkg --add-architecture armhf
RUN apt-get update

# Install x86_64 packages
RUN if [ "$BUILD_ARCH" = "X86_64" ]; then \
		echo "Adding packages for X86_64"; \
		apt-get install -y libsdl2-dev; \
		apt-get install -y libsdl2-image-dev; \
		apt-get install -y libsdl2-ttf-dev; \
	fi

# Install packages for ARM
RUN if [ "$BUILD_ARCH" = "ARM" ]; then \
		echo "Adding packages for ARM"; \
		apt-get install -y gcc-arm-linux-gnueabihf; \
		apt-get install -y libsdl2-dev:armhf; \
		apt-get install -y libsdl2-image-dev:armhf; \
		apt-get install -y libsdl2-ttf-dev:armhf; \
	fi

# Create the "objects" folder required by the makefile
RUN mkdir objects

# Builds the game based on the selected architecture
RUN if [ "$BUILD_ARCH" = "ARM" ]; then \
		make ARCH=arm; \
	else \
		make; \
	fi

EXPOSE 8080

CMD ["sleep", "infinity"]