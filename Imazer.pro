TEMPLATE = app
TARGET = 
DEPENDPATH += . src 
INCLUDEPATH += . src
INCLUDEPATH += $(AL_DIR)/include
LIBS += -L$(AL_DIR)/lib -lalcore -lalcommon -lnaoqiclient

# Input
HEADERS += src/CentralWidget.h \
           src/ImageWidget.h \
           src/MainWindow.h \
           src/MotionControlerBox.h \
           src/ClusteringWidget.h \
           src/ThresholdControlBox.h \
           src/ClusteredImageWidget.h \
           src/RawImageWidget.h
SOURCES += src/CentralWidget.cpp \
           src/ImageWidget.cpp \
           src/Main.cpp \
           src/MainWindow.cpp \
           src/MotionControlerBox.cpp \
           src/ClusteringWidget.cpp \
           src/ThresholdControlBox.cpp \
           src/ClusteredImageWidget.cpp \
           src/RawImageWidget.cpp
