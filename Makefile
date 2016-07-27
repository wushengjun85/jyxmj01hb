#############################################################################
# Makefile for building: jyxmj01hb
# Generated by qmake (2.01a) (Qt 4.8.6) on: ?? 7? 27 10:24:06 2016
# Project:  jyxmj01hb.pro
# Template: app
# Command: /home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/bin/qmake -o Makefile jyxmj01hb.pro
#############################################################################

####### Compiler, tools and options

CC            = arm-linux-gnueabihf-gcc -lts -L. -lcapture
CXX           = arm-linux-gnueabihf-g++ -lts -L. -lcapture
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/qws/linux-arm-gnueabi-g++ -I. -I../../WorkDir/HW_Src/libs/qt-4.8.6/include/QtCore -I../../WorkDir/HW_Src/libs/qt-4.8.6/include/QtNetwork -I../../WorkDir/HW_Src/libs/qt-4.8.6/include/QtGui -I../../WorkDir/HW_Src/libs/qt-4.8.6/include -I. -I. -I. -I../../WorkDir/HW_Src/libs/tslib-master/include
LINK          = arm-linux-gnueabihf-g++ -lts -L. -lcapture
LFLAGS        = -Wl,-O1 -Wl,-rpath,/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/lib
LIBS          = $(SUBLIBS)  -L/home/vmuser/WorkDir/HW_Src/libs/tslib-master/lib -L/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/lib -lQtGui -L/home/vmuser/WorkDir/HW_Src/libs/tslib-master/lib -L/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/lib -lQtNetwork -lQtCore -lrt -lpthread 
AR            = arm-linux-gnueabihf-ar cqs
RANLIB        = 
QMAKE         = /home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = arm-linux-gnueabihf-strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = camera.cpp \
		camera_thread.cpp \
		canread.cpp \
		dialog.cpp \
		main.cpp \
		signalcan.cpp \
		timesetup.cpp \
		v4l2.cpp \
		widget.cpp moc_camera.cpp \
		moc_camera_thread.cpp \
		moc_dialog.cpp \
		moc_signalcan.cpp \
		moc_timesetup.cpp \
		moc_widget.cpp \
		qrc_myicon.cpp
OBJECTS       = camera.o \
		camera_thread.o \
		canread.o \
		dialog.o \
		main.o \
		signalcan.o \
		timesetup.o \
		v4l2.o \
		widget.o \
		moc_camera.o \
		moc_camera_thread.o \
		moc_dialog.o \
		moc_signalcan.o \
		moc_timesetup.o \
		moc_widget.o \
		qrc_myicon.o
DIST          = ../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/unix.conf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/linux.conf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/gcc-base.conf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/gcc-base-unix.conf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/g++-base.conf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/g++-unix.conf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/qws.conf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/qconfig.pri \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/qt_functions.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/qt_config.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/exclusive_builds.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/default_pre.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/release.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/default_post.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/shared.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/warn_on.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/qt.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/unix/thread.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/moc.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/resources.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/uic.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/yacc.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/lex.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/include_source_dir.prf \
		jyxmj01hb.pro
QMAKE_TARGET  = jyxmj01hb
DESTDIR       = 
TARGET        = jyxmj01hb

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

all: Makefile $(TARGET)

$(TARGET): ui_camera.h ui_dialog.h ui_timesetup.h ui_widget.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: jyxmj01hb.pro  ../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/qws/linux-arm-gnueabi-g++/qmake.conf ../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/unix.conf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/linux.conf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/gcc-base.conf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/gcc-base-unix.conf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/g++-base.conf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/g++-unix.conf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/qws.conf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/qconfig.pri \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/qt_functions.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/qt_config.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/exclusive_builds.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/default_pre.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/release.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/default_post.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/shared.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/warn_on.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/qt.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/unix/thread.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/moc.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/resources.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/uic.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/yacc.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/lex.prf \
		../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/include_source_dir.prf \
		/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/lib/libQtGui.prl \
		/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/lib/libQtNetwork.prl \
		/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/lib/libQtCore.prl
	$(QMAKE) -o Makefile jyxmj01hb.pro
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/unix.conf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/linux.conf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/gcc-base.conf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/gcc-base-unix.conf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/g++-base.conf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/g++-unix.conf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/common/qws.conf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/qconfig.pri:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/qt_functions.prf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/qt_config.prf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/exclusive_builds.prf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/default_pre.prf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/release.prf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/default_post.prf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/shared.prf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/warn_on.prf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/qt.prf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/unix/thread.prf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/moc.prf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/resources.prf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/uic.prf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/yacc.prf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/lex.prf:
../../WorkDir/HW_Src/libs/qt-4.8.6/mkspecs/features/include_source_dir.prf:
/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/lib/libQtGui.prl:
/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/lib/libQtNetwork.prl:
/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile jyxmj01hb.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/jyxmj01hb1.0.0 || $(MKDIR) .tmp/jyxmj01hb1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/jyxmj01hb1.0.0/ && $(COPY_FILE) --parents camera.h camera_thread.h canread.h dialog.h mx6s_v4l2_capture.h signalcan.h timesetup.h v4l2.h widget.h .tmp/jyxmj01hb1.0.0/ && $(COPY_FILE) --parents myicon.qrc .tmp/jyxmj01hb1.0.0/ && $(COPY_FILE) --parents camera.cpp camera_thread.cpp canread.cpp dialog.cpp main.cpp signalcan.cpp timesetup.cpp v4l2.cpp widget.cpp .tmp/jyxmj01hb1.0.0/ && $(COPY_FILE) --parents camera.ui dialog.ui timesetup.ui widget.ui .tmp/jyxmj01hb1.0.0/ && (cd `dirname .tmp/jyxmj01hb1.0.0` && $(TAR) jyxmj01hb1.0.0.tar jyxmj01hb1.0.0 && $(COMPRESS) jyxmj01hb1.0.0.tar) && $(MOVE) `dirname .tmp/jyxmj01hb1.0.0`/jyxmj01hb1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/jyxmj01hb1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_camera.cpp moc_camera_thread.cpp moc_dialog.cpp moc_signalcan.cpp moc_timesetup.cpp moc_widget.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_camera.cpp moc_camera_thread.cpp moc_dialog.cpp moc_signalcan.cpp moc_timesetup.cpp moc_widget.cpp
moc_camera.cpp: camera_thread.h \
		v4l2.h \
		dialog.h \
		timesetup.h \
		camera.h
	/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/bin/moc $(DEFINES) $(INCPATH) camera.h -o moc_camera.cpp

moc_camera_thread.cpp: v4l2.h \
		camera_thread.h
	/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/bin/moc $(DEFINES) $(INCPATH) camera_thread.h -o moc_camera_thread.cpp

moc_dialog.cpp: timesetup.h \
		dialog.h
	/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/bin/moc $(DEFINES) $(INCPATH) dialog.h -o moc_dialog.cpp

moc_signalcan.cpp: canread.h \
		signalcan.h
	/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/bin/moc $(DEFINES) $(INCPATH) signalcan.h -o moc_signalcan.cpp

moc_timesetup.cpp: timesetup.h
	/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/bin/moc $(DEFINES) $(INCPATH) timesetup.h -o moc_timesetup.cpp

moc_widget.cpp: dialog.h \
		timesetup.h \
		signalcan.h \
		canread.h \
		camera.h \
		camera_thread.h \
		v4l2.h \
		widget.h
	/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/bin/moc $(DEFINES) $(INCPATH) widget.h -o moc_widget.cpp

compiler_rcc_make_all: qrc_myicon.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_myicon.cpp
qrc_myicon.cpp: myicon.qrc \
		img2/back.png \
		img2/laba.bmp \
		img2/mysetup_icon.png \
		img2/timeset.png \
		img2/myicon_setup.png
	/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/bin/rcc -name myicon myicon.qrc -o qrc_myicon.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_camera.h ui_dialog.h ui_timesetup.h ui_widget.h
compiler_uic_clean:
	-$(DEL_FILE) ui_camera.h ui_dialog.h ui_timesetup.h ui_widget.h
ui_camera.h: camera.ui
	/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/bin/uic camera.ui -o ui_camera.h

ui_dialog.h: dialog.ui
	/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/bin/uic dialog.ui -o ui_dialog.h

ui_timesetup.h: timesetup.ui
	/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/bin/uic timesetup.ui -o ui_timesetup.h

ui_widget.h: widget.ui
	/home/vmuser/WorkDir/HW_Src/libs/qt-4.8.6/bin/uic widget.ui -o ui_widget.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

camera.o: camera.cpp camera.h \
		camera_thread.h \
		v4l2.h \
		dialog.h \
		timesetup.h \
		ui_camera.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o camera.o camera.cpp

camera_thread.o: camera_thread.cpp camera_thread.h \
		v4l2.h \
		mx6s_v4l2_capture.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o camera_thread.o camera_thread.cpp

canread.o: canread.cpp canread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o canread.o canread.cpp

dialog.o: dialog.cpp dialog.h \
		timesetup.h \
		ui_dialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dialog.o dialog.cpp

main.o: main.cpp widget.h \
		dialog.h \
		timesetup.h \
		signalcan.h \
		canread.h \
		camera.h \
		camera_thread.h \
		v4l2.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

signalcan.o: signalcan.cpp signalcan.h \
		canread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o signalcan.o signalcan.cpp

timesetup.o: timesetup.cpp timesetup.h \
		ui_timesetup.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o timesetup.o timesetup.cpp

v4l2.o: v4l2.cpp v4l2.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o v4l2.o v4l2.cpp

widget.o: widget.cpp widget.h \
		dialog.h \
		timesetup.h \
		signalcan.h \
		canread.h \
		camera.h \
		camera_thread.h \
		v4l2.h \
		ui_widget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o widget.o widget.cpp

moc_camera.o: moc_camera.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_camera.o moc_camera.cpp

moc_camera_thread.o: moc_camera_thread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_camera_thread.o moc_camera_thread.cpp

moc_dialog.o: moc_dialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_dialog.o moc_dialog.cpp

moc_signalcan.o: moc_signalcan.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_signalcan.o moc_signalcan.cpp

moc_timesetup.o: moc_timesetup.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_timesetup.o moc_timesetup.cpp

moc_widget.o: moc_widget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_widget.o moc_widget.cpp

qrc_myicon.o: qrc_myicon.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_myicon.o qrc_myicon.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

