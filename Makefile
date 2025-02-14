NAME		=	jam.exe

RELEASE_FLAGS = -O3 -DNDEBUG -s
INCLUDEFLAGS = -Ilib -Iinclude 
INCLUDEFLAGS +=	-Iinclude/Animation
INCLUDEFLAGS += -Iinclude/Enemies
INCLUDEFLAGS += -Iinclude/Game
INCLUDEFLAGS += -Iinclude/Objects


LDFLAGS = -lglfw3 -lgdi32 -lopengl32 -lmingw32

INC_FLAGS	=	-Ilib -Iinclude

CXX			=	c++
CXXFLAGS	=	-static $(RELEASE_FLAGS) $(INCLUDEFLAGS)
#-Wall -Wextra -Werror
GRAPHIC		=	lib/graphic.a

SRCDIR		=	./src
ANIMDIR		=	$(SRCDIR)/Animation
ENEMDIR		=	$(SRCDIR)/Enemies
OBJDIR		=	$(SRCDIR)/Objects

#Animation
SRC			=	

#Enemies
SRC			+=	$(ENEMDIR)/Enemy.cpp \
				$(ENEMDIR)/Wowo.cpp \

#Objects
SRC			+=	$(OBJDIR)/Player.cpp \
				$(OBJDIR)/Wall.cpp

SRC			+=	$(SRCDIR)/Camera.cpp \
				$(SRCDIR)/Collision.cpp \
				$(SRCDIR)/CollisionManager.cpp \
				$(SRCDIR)/Game.cpp \
				$(SRCDIR)/GameMap.cpp \
				$(SRCDIR)/GameObject.cpp \
				$(SRCDIR)/InputCallbacks.cpp \
				$(SRCDIR)/main.cpp \
				$(SRCDIR)/ResourceManager.cpp \
				$(SRCDIR)/Shader.cpp \
				$(SRCDIR)/SpriteRenderer.cpp \
				$(SRCDIR)/TagManager.cpp \
				$(SRCDIR)/Texture2D.cpp \

OBJ			=	$(SRC:.cpp=.o)

all: graphall $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS)  $(OBJ) $(GRAPHIC) $(INC_FLAGS) $(LDFLAGS) -o $(NAME)

rrun: re
	@./$(NAME) || true

run: all
	@./$(NAME) || true

c: clean
clean:
	$(RM) $(OBJ)

f: fclean
fclean: clean
	$(RM) $(NAME)

re: fclean all


%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) -c $< -o $@

graphall:
	@make -C lib

.PHONY: all clean fclean re c f

