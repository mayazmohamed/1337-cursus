NAME = inception

all:
	@printf "Starting ${NAME} ...\n"
	@docker-compose -f ./srcs/docker-compose.yml up -d

build:
	@printf "Building ${NAME} ...\n"
	@sh ./srcs/requirements/tools/script.sh
	@docker-compose -f ./srcs/docker-compose.yml up -d --build

start:
	@printf "Starting ${NAME} ...\n"
	@docker-compose -f ./srcs/docker-compose.yml start

stop:
	@printf "Stopping ${NAME} ...\n"
	@docker-compose -f ./srcs/docker-compose.yml stop

down:
	@printf "Shuting Down ${NAME} ...\n"
	@docker-compose -f ./srcs/docker-compose.yml down

re: down
	printf "ReBuilding ${NAME} ...\n"
	@docker-compose -f ./srcs/docker-compose.yml up -d --build

clean: down
	@printf "Cleaning ${name} ...\n"
	@docker system prune -a

fclean:
	@printf "Total Cleaning ...\n"
	@docker stop $$(docker ps -aq)
	@docker system prune --all --force --volumes
	@docker network prune --force
	@docker volume prune --force
