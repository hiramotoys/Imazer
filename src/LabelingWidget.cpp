#include "LabelingWidget.h"
#include <iostream>
#include <QRgb>

LabelingWidget::LabelingWidget(const QRect &rect, QWidget *iParent, Qt::WindowFlags iFlags) : QWidget(iParent, iFlags){
    setGeometry(rect);
    QRect rimgRect(0, 80, 320, 240);
    rawImageWidget = new RawImageWidget(rimgRect, this);
    QRect lbimgRect(0, 330, 320, 240);
    labeledImageWidget = new LabeledImageWidget(lbimgRect, this);
    std::cout << "init Labeling widget" << std::endl;
    QRect csRect(0, 0, 360, 70);
    classSelectorBox = new ClassSelectorBox(csRect, "Class Selector", this);
    sliderGroupBox = new QGroupBox("Threshold Slider", this);
    sliderGroupBox->setGeometry(340, 70, 700, 400);
    sliderLayout = new QHBoxLayout();
    rgbThBall = new RGBThresholdControlBox("ball");
    sliderLayout->addWidget(rgbThBall);
    rgbThGreen = new RGBThresholdControlBox("green");
    sliderLayout->addWidget(rgbThGreen);
    rgbThLines = new RGBThresholdControlBox("lines");
    sliderLayout->addWidget(rgbThLines);
    rgbThGoalYellow = new RGBThresholdControlBox("goal yellow");
    sliderLayout->addWidget(rgbThGoalYellow);
    rgbThGoalBlue = new RGBThresholdControlBox("goal blue");
    sliderLayout->addWidget(rgbThGoalBlue);
    sliderGroupBox->setLayout(sliderLayout);
    this->image = new QImage();
    std::cout << "new" << std::endl;
    bool isLoaded = this->image->load("/Users/hiramoto/Documents/workspace/Imazer/test/00000018.png");
    std::cout << "loaded " << isLoaded << std::endl;
    rawImageWidget->update(image);
}

LabelingWidget::~LabelingWidget(){
}

void LabelingWidget::updateRawImage(QImage *image){
    rawImageWidget->update(image);
}

void LabelingWidget::clickedRawImage(const QPoint &point){
    int objid = classSelectorBox->getSelectedObjectID();
    std::cout << objid << std::endl;
    switch(objid){
    case NaoWorldObjectID::LINES:
	clickedLinesPixel(point);
	break;
    }
}

void LabelingWidget::clickedLinesPixel(const QPoint &point){
    std::cout << "clickedLinesPixel" << std::endl;
    QRgb rgb = image->pixel(point);
    std::cout << "QRgb" << std::endl;
    QColor color(rgb);
    int red = color.red();
    int green = color.green();
    int blue = color.blue();
    std::cout << red << " " << green << " " << blue << std::endl;
    if(!isLinesClass(red, green, blue)){
	if(red < rgbThLines->r.fr){
	    // update th and slider
	}
	if(red > rgbThLines->r.to){
	    // update th and slider
	}
	if(green < rgbThLines->g.fr){
	    // update th and slider
	}
	if(green > rgbThLines->g.to){
	    // update th and slider
	}
	if(blue < rgbThLines->b.fr){
	    // update th and slider
	}
	if(blue > rgbThLines->b.to){
	    // update th and slider
	}
	// TODO if conflicted, change other threshold
    }
}

bool LabelingWidget::isLinesClass(int red, int green, int blue){
    if(red >= rgbThLines->r.fr && red <= rgbThLines->r.to && blue >= rgbThLines->b.fr && blue <= rgbThLines->b.to && green >= rgbThLines->g.fr && green <= rgbThLines->g.to){
	return true;
    }
    return false;
}

bool LabelingWidget::isGreenClass(int red, int green, int blue){
    if(red >= rgbThGreen->r.fr && red <= rgbThGreen->r.to && blue >= rgbThGreen->b.fr && blue <= rgbThGreen->b.to && green >= rgbThGreen->g.fr && green <= rgbThGreen->g.to){
	return true;
    }
    return false;
}

void LabelingWidget::movedrgbThBallSlider(){
}

void LabelingWidget::movedrgbThGreenSlider(){
}

void LabelingWidget::movedrgbThLinesSlider(){
}

void LabelingWidget::movedrgbThGoalYellowSlider(){
}

void LabelingWidget::movedrgbThGoalBlueSlider(){
}
