# Use GCC official image
FROM gcc:11

COPY . ./usr/src/aztroz-game

WORKDIR ./usr/src/aztroz-game

ARG BUILD_ARCH=""

# Install x86_64 packages
RUN if [ "$BUILD_ARCH" = "X86_64" ]; then \
		apt-get update; \
		apt-get install -y libsdl2-dev; \
		apt-get install -y libsdl2-image-dev; \
		apt-get install -y libsdl2-ttf-dev; \
	fi

# Install packages for ARM
RUN if [ "$BUILD_ARCH" = "ARM" ]; then \
		dpkg --add-architecture armhf; \
		apt-get update; \
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