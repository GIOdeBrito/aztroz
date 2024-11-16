!#/bin/bash

docker-compose build

docker-compose up -d

#if [ ! -d "out" ]; then
	#mkdir out
#fi

docker cp main-aztroz-game-container:/usr/src/aztroz-game/aztroz.game .

docker-compose down