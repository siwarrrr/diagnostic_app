# Compilateur
CXX = g++
# Options de compilation avec chemin d'inclusion
CXXFLAGS = -std=c++11 $(INC_DIR)


# Listes des fichiers source et des exécutables
#SRCS= $(wildcard src/*.cpp)
#$(info $$Sources is [${SRCS}])
RCS = Parser.cpp JsonSequencer.cpp UdsCodec.cpp UdsTransceiver.cpp PresenceTester.cpp ErrorHandlerRasp.cpp main.cpp
OBJS = $(RCS:.cpp=.o)
EXEC = diagnostic_app
INC_DIR = -Iinc
LIBS=-lPocoJSON -lPocoFoundation -lPocoUtil

INCLUDES=-I/home/siwar/classes

# Règles de compilation
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIBS)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# Nettoyage
clean:
	rm -f $(OBJS) $(EXEC)


install:
	cp $(EXEC) $(INC_DIR)







