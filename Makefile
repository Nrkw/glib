CXX = g++
AR  = ar
CXXFLAGS = -std=c++17 -Wall -I./ -I./shader -I./buffer -I./renderer -I./window -I./image -I./load

# OpenCV optional
USE_OPENCV ?= 0
OPENCV_INC    ?= -IC:\OpenCV\opencv\sources\build\install\include
OPENCV_LIBDIR ?= -LC:\OpenCV\opencv\sources\build\install\x64\mingw\lib
# 環境のバージョンに合わせて変更してください
#OpenCV 4.12.0なら-lopencv_core4120等と末尾にバージョンを加える。
OPENCV_LIBS   ?= -lopencv_core4120 -lopencv_imgproc4120 -lopencv_imgcodecs4120 -lopencv_highgui4120

# Win/OpenGL
LDFLAGS_BASE  = -lopengl32 -lgdi32 -luser32

# sources
ALL_SRC   := $(wildcard ./*.cpp ./renderer/*.cpp ./window/*.cpp ./image/*.cpp ./shader/*.cpp ./buffer/*.cpp ./load/*.cpp)
IMAGE_SRC := $(wildcard ./image/*.cpp)

# lib sources (exclude main.cpp, optionally exclude image)
ifeq ($(USE_OPENCV),1)
  LIB_SRC := $(filter-out ./main.cpp,$(ALL_SRC))
  CXXFLAGS += $(OPENCV_INC) -DGLWRAP_USE_OPENCV=1
  LDFLAGS  := $(OPENCV_LIBDIR) $(LDFLAGS_BASE) $(OPENCV_LIBS)
else
  LIB_SRC := $(filter-out ./main.cpp $(IMAGE_SRC),$(ALL_SRC))
  LDFLAGS  := $(LDFLAGS_BASE)
endif

LIB_OBJ := $(LIB_SRC:.cpp=.o)

LIB := libglwrap.a
APP := app.exe

# install dirs
PREFIX ?= dist
INCDIR := $(PREFIX)\include\OpenGLWrapper
LIBDIR := $(PREFIX)\lib

.PHONY: all lib app clean install uninstall run

# default goal by MODE
ifeq ($(MODE), lib)
.DEFAULT_GOAL := lib
else ifeq ($(MODE), app)
.DEFAULT_GOAL := app
else
.DEFAULT_GOAL := all
endif

all: lib app

lib: $(LIB)
$(LIB): $(LIB_OBJ)
	$(AR) rcs $@ $^

app: lib ./main.o
	$(CXX) $(CXXFLAGS) -o $(APP) ./main.o $(LIB) $(LDFLAGS)

run: app
	./$(APP)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(LIB_OBJ) ./main.o $(LIB) $(APP)

install: lib
	if not exist "$(INCDIR)" mkdir "$(INCDIR)"
	if not exist "$(LIBDIR)" mkdir "$(LIBDIR)"
	rem 集約ヘッダー（あれば）
	robocopy . "$(INCDIR)" OpenGLWrapper.hpp /NFL /NDL /NJH /NJS >NUL || cmd /c exit 0
ifeq ($(USE_OPENCV),1)
	rem OpenCV有効: 全ての .hpp を再帰コピー
	robocopy . "$(INCDIR)" *.hpp /S /NFL /NDL /NJH /NJS >NUL || cmd /c exit 0
else
	rem OpenCV無効: image フォルダを除外
	robocopy . "$(INCDIR)" *.hpp /S /XD image /NFL /NDL /NJH /NJS >NUL || cmd /c exit 0
endif
	copy /Y "$(LIB)" "$(LIBDIR)\"

uninstall:
	if exist "$(INCDIR)" rmdir /S /Q "$(INCDIR)"
	if exist "$(LIBDIR)\$(LIB)" del /Q "$(LIBDIR)\$(LIB)"