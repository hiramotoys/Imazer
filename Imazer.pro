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
           src/LabelingWidget.h \
           src/ThresholdControlBox.h \
           src/LabeledImageWidget.h \
           src/RawImageWidget.h \ 
           src/ClassSelectorBox.h \
           src/RGBThresholdControlBox.h \
           src/ThresholdSliderBox.h \
           src/Threshold.h \
           src/NaoWorldObjectID.h \
           src/ColorAttributeID.h
SOURCES += src/CentralWidget.cpp \
           src/ImageWidget.cpp \
           src/Main.cpp \
           src/MainWindow.cpp \
           src/MotionControlerBox.cpp \
           src/LabelingWidget.cpp \
           src/ThresholdControlBox.cpp \
           src/LabeledImageWidget.cpp \
           src/RawImageWidget.cpp \
           src/ClassSelectorBox.cpp \
           src/RGBThresholdControlBox.cpp \
           src/ThresholdSliderBox.cpp \
           src/Threshold.cpp
