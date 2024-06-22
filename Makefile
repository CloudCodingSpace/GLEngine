srcs = $(shell find . -type f -name "*.cpp")
includep = -Iinclude
libp = -Llib
linkerflags = -lglfw3dll -lassimp.dll -limgui -lglad -lstbi -lstbp
defines = -D GE_DEBUG -D _DEBUG

.PHONY: build

build:
	@echo "Building..."
	@g++ $(defines) $(includep) $(libp) $(srcs) $(linkerflags) -o ./bin/engine
	@echo "Done Building!"

run:
	@./bin/engine