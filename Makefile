CXX = g++

CXXFLAGS =  -Iinclude -Iinclude/input -Iinclude/output -Iinclude/parse \
			-Iinclude/process -Iinclude/sort -Iinclude/parse \
			-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef \
			-Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations \
			-Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ \
			-Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion \
			-Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers \
			-Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual \
			-Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing \
			-Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG \
			-D_EJUDGE_CLIENT_SIDE

SOURCES = source/main.cpp \
		  source/sort/strcmp.cpp \
		  source/parse/buffer.cpp \
		  source/input/input.cpp \
		  source/parse/ptrdata.cpp \
		  source/sort/sort.cpp \
		  source/output/output.cpp \
		  source/process/process.cpp

EXECUTABLE = run.exe

OUTPUTS = output.txt

all:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE)

release:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE)

debug:
	$(CXX) -DDEBUG_MODE $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE)

clean:
	rm $(EXECUTABLE) $(OUTPUTS)
