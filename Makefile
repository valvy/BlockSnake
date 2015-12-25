CC=c++
NAME=BlockSnake
CFLAGS=-Wall -g -O3 -std=c++11 -pthread
LFLAGS=-framework cocoa -framework Appkit -framework GLKit  -framework OpenGl -o $(NAME)
OBJECTS=MacApp.o Application.o SnakeScene.o SnakeBody.o Scene.o GameObject.o PrimitiveCube.o ShaderAsset.o AssetNotFoundException.o ProgramAsset.o AssetManager.o TextureAsset.o MainMenu.o PrimitiveForm.o PrimitiveQuad.o Background.o SnakeHead.o GameOverScene.o Fruit.o

%.o : %.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

%.o : %.mm
	$(CC) $(CFLAGS)  -c -o $@ $^

all: $(OBJECTS)
	$(CC) $(OBJECTS) $(LFLAGS)

clean:
	-rm $(OBJECTS) $(NAME)