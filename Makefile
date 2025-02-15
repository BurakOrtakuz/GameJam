CXX			=	c++

INCLUDEFLAGS =	-Ilib -Iinclude \
				-Iinclude/Animation \
				-Iinclude/Enemies \
				-Iinclude/Game \
				-Iinclude/Objects

RM	=	rm -rf

ifeq ($(OS),Windows_NT)
	NAME			= jam.exe
	RELEASE_FLAGS	= -O3 -DNDEBUG -s
	LDFLAGS			= -lglfw3 -lgdi32 -lopengl32 -lmingw32
else
	NAME			= jam
	RELEASE_FLAGS	=
	LDFLAGS			=	-lglfw -ldl -lGL -lz
#	LDFLAGS			=	-lglfw -lGL -lGLEW -lm
endif

CXXFLAGS	=	#-Wextra -Wall #-Werror
CXXFLAGS	+= $(RELEASE_FLAGS) $(INCLUDEFLAGS)


GRAPHIC		=	lib/graphic.a

SRCDIR			=	./src
ANIMDIR			=	$(SRCDIR)/Animation
ENEMDIR			=	$(SRCDIR)/Enemies
OBJECTSDIR		=	$(SRCDIR)/Objects

#Animation
SRC			=	$(ANIMDIR)/Animation.cpp \
				$(ANIMDIR)/Animationable.cpp \

#Enemies
SRC			+=	$(ENEMDIR)/Enemy.cpp \
				$(ENEMDIR)/Wowo.cpp \

#Objects
SRC			+=	$(OBJECTSDIR)/Player.cpp \
				$(OBJECTSDIR)/Wall.cpp

SRC			+=	$(SRCDIR)/Camera.cpp \
				$(SRCDIR)/Collision.cpp \
				$(SRCDIR)/CollisionManager.cpp \
				$(SRCDIR)/Game.cpp \
				$(SRCDIR)/GameMap.cpp \
				$(SRCDIR)/GameObject.cpp \
				$(SRCDIR)/GameUploads.cpp \
				$(SRCDIR)/InputCallbacks.cpp \
				$(SRCDIR)/main.cpp \
				$(SRCDIR)/ResourceManager.cpp \
				$(SRCDIR)/Shader.cpp \
				$(SRCDIR)/SpriteRenderer.cpp \
				$(SRCDIR)/TagManager.cpp \
				$(SRCDIR)/Texture2D.cpp

OBJDIR		=	./obj
OBJ			=	$(SRC:%.cpp=$(OBJDIR)/%.o)

all: graphall $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(GRAPHIC) $(LDFLAGS) -o $(NAME)

rrun: re
	@./$(NAME) || true

run: all
	@./$(NAME) || true

c: clean
clean:
	@make -C lib clean
	$(RM) $(OBJDIR)

f: fc
fclean: fc
fc: clean
	@make -C lib fclean
	$(RM) $(NAME)

re: fclean all

rr: rerun

rerun: re
	./$(NAME)

run : all
	./$(NAME)
.PHONY: all c clean fc fclean re run

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

graphall:
	@make -C lib

.PHONY: all clean fclean re c f
