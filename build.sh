#!/bin/bash

IS_ARM=""

read -p "Build for ARM? (Y/N) " IS_ARM

if [[ $IS_ARM =~ [yYSs] ]]; then
	sudo docker compose build --build-arg BUILD_ARCH=ARM
	sudo docker compose up -d
	sudo docker cp main-aztroz-game-container:/usr/src/aztroz-game/aztroz.arm .
else
	sudo docker compose build --build-arg BUILD_ARCH=X86_64
	sudo docker compose up -d
	sudo docker cp main-aztroz-game-container:/usr/src/aztroz-game/aztroz.x86_64 .
fi

sudo docker compose down

#./aztroz.game