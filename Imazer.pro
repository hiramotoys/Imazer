######################################################################
# Automatically generated by qmake (2.01a) ? 2? 27 21:26:17 2011
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += . src 
INCLUDEPATH += . src
INCLUDEPATH += $(AL_DIR)/include
LIBS += -L$(AL_DIR)/lib -lalcore -lalcommon -lnaoqiclient

# Input
HEADERS += src/CentralWidget.h \
           src/ClassSelectorBox.h \
           src/ColorAttributeID.h \
           src/HSVThresholdControlBox.h \
           src/ImageWidget.h \
           src/LabeledImageWidget.h \
           src/LabelingWidget.h \
           src/MainWindow.h \
           src/MotionControlerBox.h \
           src/NaoWorldObjectID.h \
           src/RawImageWidget.h \
           src/RCNaoObjectColor.h \
           src/RGBParameterManager.h \
           src/RGBThresholdControlBox.h \
           src/Threshold.h \
           src/ThresholdControlBox.h \
           src/ThresholdSliderBox.h
SOURCES += src/CentralWidget.cpp \
           src/ClassSelectorBox.cpp \
           src/HSVThresholdControlBox.cpp \
           src/ImageWidget.cpp \
           src/LabeledImageWidget.cpp \
           src/LabelingWidget.cpp \
           src/Main.cpp \
           src/MainWindow.cpp \
           src/MotionControlerBox.cpp \
           src/RawImageWidget.cpp \
           src/RGBParameterManager.cpp \
           src/RGBThresholdControlBox.cpp \
           src/Threshold.cpp \
           src/ThresholdControlBox.cpp \
           src/ThresholdSliderBox.cpp
