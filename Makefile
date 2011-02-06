#############################################################################
# Makefile for building: Imazer.app/Contents/MacOS/Imazer
# Generated by qmake (2.01a) (Qt 4.7.1) on: ? 2? 6 23:01:22 2011
# Project:  Imazer.pro
# Template: app
# Command: /opt/local/bin/qmake -o Makefile Imazer.pro
#############################################################################

####### Compiler, tools and options

CC            = $(CCACHE) /usr/bin/gcc-4.0
CXX           = $(CCACHE) /usr/bin/g++-4.0
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W $(DEFINES)
INCPATH       = -I/opt/local/share/qt4/mkspecs/macx-g++ -I. -I. -I. -Isrc -I/opt/local/include/QtGui -I/opt/local/include/QtCore -I/opt/local/include -I$(AL_DIR)/include
LINK          = $(CCACHE) /usr/bin/g++-4.0
LFLAGS        = -headerpad_max_install_names
LIBS          = $(SUBLIBS) -L/opt/local/lib -lQtGui -lQtCore -L$(AL_DIR)/lib -lalcore -lalcommon -lnaoqiclient
AR            = ar cq
RANLIB        = ranlib -s
QMAKE         = /opt/local/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = 
INSTALL_FILE  = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = $(COPY_FILE)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
export MACOSX_DEPLOYMENT_TARGET = 10.6

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = src/CentralWidget.cpp \
		src/ImageWidget.cpp \
		src/Main.cpp \
		src/MainWindow.cpp moc_CentralWidget.cpp \
		moc_ImageWidget.cpp \
		moc_MainWindow.cpp
OBJECTS       = CentralWidget.o \
		ImageWidget.o \
		Main.o \
		MainWindow.o \
		moc_CentralWidget.o \
		moc_ImageWidget.o \
		moc_MainWindow.o
DIST          = /opt/local/share/qt4/mkspecs/common/unix.conf \
		/opt/local/share/qt4/mkspecs/common/mac.conf \
		/opt/local/share/qt4/mkspecs/common/mac-g++.conf \
		/opt/local/share/qt4/mkspecs/qconfig.pri \
		/opt/local/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/opt/local/share/qt4/mkspecs/features/qt_functions.prf \
		/opt/local/share/qt4/mkspecs/features/qt_config.prf \
		/opt/local/share/qt4/mkspecs/features/exclusive_builds.prf \
		/opt/local/share/qt4/mkspecs/features/default_pre.prf \
		/opt/local/share/qt4/mkspecs/features/mac/default_pre.prf \
		/opt/local/share/qt4/mkspecs/features/release.prf \
		/opt/local/share/qt4/mkspecs/features/default_post.prf \
		/opt/local/share/qt4/mkspecs/features/mac/default_post.prf \
		/opt/local/share/qt4/mkspecs/features/mac/objective_c.prf \
		/opt/local/share/qt4/mkspecs/features/warn_on.prf \
		/opt/local/share/qt4/mkspecs/features/qt.prf \
		/opt/local/share/qt4/mkspecs/features/unix/thread.prf \
		/opt/local/share/qt4/mkspecs/features/moc.prf \
		/opt/local/share/qt4/mkspecs/features/mac/rez.prf \
		/opt/local/share/qt4/mkspecs/features/mac/sdk.prf \
		/opt/local/share/qt4/mkspecs/features/resources.prf \
		/opt/local/share/qt4/mkspecs/features/uic.prf \
		/opt/local/share/qt4/mkspecs/features/yacc.prf \
		/opt/local/share/qt4/mkspecs/features/lex.prf \
		/opt/local/share/qt4/mkspecs/features/include_source_dir.prf \
		Imazer.pro
QMAKE_TARGET  = Imazer
DESTDIR       = 
TARGET        = Imazer.app/Contents/MacOS/Imazer

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-O2 \
		-Wall \
		-W


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile Imazer.app/Contents/PkgInfo Imazer.app/Contents/Resources/empty.lproj Imazer.app/Contents/Info.plist $(TARGET)

$(TARGET):  $(OBJECTS)  
	@$(CHK_DIR_EXISTS) Imazer.app/Contents/MacOS/ || $(MKDIR) Imazer.app/Contents/MacOS/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Imazer.pro  /opt/local/share/qt4/mkspecs/macx-g++/qmake.conf /opt/local/share/qt4/mkspecs/common/unix.conf \
		/opt/local/share/qt4/mkspecs/common/mac.conf \
		/opt/local/share/qt4/mkspecs/common/mac-g++.conf \
		/opt/local/share/qt4/mkspecs/qconfig.pri \
		/opt/local/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/opt/local/share/qt4/mkspecs/features/qt_functions.prf \
		/opt/local/share/qt4/mkspecs/features/qt_config.prf \
		/opt/local/share/qt4/mkspecs/features/exclusive_builds.prf \
		/opt/local/share/qt4/mkspecs/features/default_pre.prf \
		/opt/local/share/qt4/mkspecs/features/mac/default_pre.prf \
		/opt/local/share/qt4/mkspecs/features/release.prf \
		/opt/local/share/qt4/mkspecs/features/default_post.prf \
		/opt/local/share/qt4/mkspecs/features/mac/default_post.prf \
		/opt/local/share/qt4/mkspecs/features/mac/objective_c.prf \
		/opt/local/share/qt4/mkspecs/features/warn_on.prf \
		/opt/local/share/qt4/mkspecs/features/qt.prf \
		/opt/local/share/qt4/mkspecs/features/unix/thread.prf \
		/opt/local/share/qt4/mkspecs/features/moc.prf \
		/opt/local/share/qt4/mkspecs/features/mac/rez.prf \
		/opt/local/share/qt4/mkspecs/features/mac/sdk.prf \
		/opt/local/share/qt4/mkspecs/features/resources.prf \
		/opt/local/share/qt4/mkspecs/features/uic.prf \
		/opt/local/share/qt4/mkspecs/features/yacc.prf \
		/opt/local/share/qt4/mkspecs/features/lex.prf \
		/opt/local/share/qt4/mkspecs/features/include_source_dir.prf \
		/opt/local/lib/libQtGui.prl \
		/opt/local/lib/libQtCore.prl
	$(QMAKE) -o Makefile Imazer.pro
/opt/local/share/qt4/mkspecs/common/unix.conf:
/opt/local/share/qt4/mkspecs/common/mac.conf:
/opt/local/share/qt4/mkspecs/common/mac-g++.conf:
/opt/local/share/qt4/mkspecs/qconfig.pri:
/opt/local/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/opt/local/share/qt4/mkspecs/features/qt_functions.prf:
/opt/local/share/qt4/mkspecs/features/qt_config.prf:
/opt/local/share/qt4/mkspecs/features/exclusive_builds.prf:
/opt/local/share/qt4/mkspecs/features/default_pre.prf:
/opt/local/share/qt4/mkspecs/features/mac/default_pre.prf:
/opt/local/share/qt4/mkspecs/features/release.prf:
/opt/local/share/qt4/mkspecs/features/default_post.prf:
/opt/local/share/qt4/mkspecs/features/mac/default_post.prf:
/opt/local/share/qt4/mkspecs/features/mac/objective_c.prf:
/opt/local/share/qt4/mkspecs/features/warn_on.prf:
/opt/local/share/qt4/mkspecs/features/qt.prf:
/opt/local/share/qt4/mkspecs/features/unix/thread.prf:
/opt/local/share/qt4/mkspecs/features/moc.prf:
/opt/local/share/qt4/mkspecs/features/mac/rez.prf:
/opt/local/share/qt4/mkspecs/features/mac/sdk.prf:
/opt/local/share/qt4/mkspecs/features/resources.prf:
/opt/local/share/qt4/mkspecs/features/uic.prf:
/opt/local/share/qt4/mkspecs/features/yacc.prf:
/opt/local/share/qt4/mkspecs/features/lex.prf:
/opt/local/share/qt4/mkspecs/features/include_source_dir.prf:
/opt/local/lib/libQtGui.prl:
/opt/local/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile Imazer.pro

Imazer.app/Contents/PkgInfo: 
	@$(CHK_DIR_EXISTS) Imazer.app/Contents || $(MKDIR) Imazer.app/Contents 
	@$(DEL_FILE) Imazer.app/Contents/PkgInfo
	@echo "APPL????" >Imazer.app/Contents/PkgInfo
Imazer.app/Contents/Resources/empty.lproj: 
	@$(CHK_DIR_EXISTS) Imazer.app/Contents/Resources || $(MKDIR) Imazer.app/Contents/Resources 
	@touch Imazer.app/Contents/Resources/empty.lproj

Imazer.app/Contents/Info.plist: 
	@$(CHK_DIR_EXISTS) Imazer.app/Contents || $(MKDIR) Imazer.app/Contents 
	@$(DEL_FILE) Imazer.app/Contents/Info.plist
	@sed -e "s,@ICON@,,g" -e "s,@EXECUTABLE@,Imazer,g" -e "s,@TYPEINFO@,????,g" /opt/local/share/qt4/mkspecs/macx-g++/Info.plist.app >Imazer.app/Contents/Info.plist
dist: 
	@$(CHK_DIR_EXISTS) .tmp/Imazer1.0.0 || $(MKDIR) .tmp/Imazer1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Imazer1.0.0/ && $(COPY_FILE) --parents src/CentralWidget.h src/ImageWidget.h src/MainWindow.h .tmp/Imazer1.0.0/ && $(COPY_FILE) --parents src/CentralWidget.cpp src/ImageWidget.cpp src/Main.cpp src/MainWindow.cpp .tmp/Imazer1.0.0/ && (cd `dirname .tmp/Imazer1.0.0` && $(TAR) Imazer1.0.0.tar Imazer1.0.0 && $(COMPRESS) Imazer1.0.0.tar) && $(MOVE) `dirname .tmp/Imazer1.0.0`/Imazer1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Imazer1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) -r Imazer.app
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_CentralWidget.cpp moc_ImageWidget.cpp moc_MainWindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_CentralWidget.cpp moc_ImageWidget.cpp moc_MainWindow.cpp
moc_CentralWidget.cpp: src/ImageWidget.h \
		src/CentralWidget.h
	/opt/local/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/CentralWidget.h -o moc_CentralWidget.cpp

moc_ImageWidget.cpp: src/ImageWidget.h
	/opt/local/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/ImageWidget.h -o moc_ImageWidget.cpp

moc_MainWindow.cpp: src/CentralWidget.h \
		src/ImageWidget.h \
		src/MainWindow.h
	/opt/local/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/MainWindow.h -o moc_MainWindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

CentralWidget.o: src/CentralWidget.cpp src/CentralWidget.h \
		src/ImageWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CentralWidget.o src/CentralWidget.cpp

ImageWidget.o: src/ImageWidget.cpp src/ImageWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ImageWidget.o src/ImageWidget.cpp

Main.o: src/Main.cpp src/MainWindow.h \
		src/CentralWidget.h \
		src/ImageWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Main.o src/Main.cpp

MainWindow.o: src/MainWindow.cpp src/MainWindow.h \
		src/CentralWidget.h \
		src/ImageWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MainWindow.o src/MainWindow.cpp

moc_CentralWidget.o: moc_CentralWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_CentralWidget.o moc_CentralWidget.cpp

moc_ImageWidget.o: moc_ImageWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ImageWidget.o moc_ImageWidget.cpp

moc_MainWindow.o: moc_MainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_MainWindow.o moc_MainWindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

