#include "LabelingWidget.h"
#include <iostream>
#include <cmath>
#include "RCNaoObjectColor.h"
#include <vector>

LabelingWidget::LabelingWidget(const QRect &rect, QWidget *iParent, Qt::WindowFlags iFlags) : QWidget(iParent, iFlags){
    setGeometry(rect);
    QRect rimgRect(0, 80, 320, 240);
    rawImageWidget = new RawImageWidget(rimgRect, this);
    QRect lbimgRect(0, 330, 320, 240);
    labeledImageWidget = new LabeledImageWidget(lbimgRect, this);
    std::cout << "init Labeling widget" << std::endl;
    QRect csRect(0, 0, 360, 70);
    classSelectorBox = new ClassSelectorBox(csRect, "Class Selector", this);
    initHSVThControlBox();
    this->image = new QImage();
    std::cout << "new" << std::endl;
    bool isLoaded = this->image->load("/Users/hiramotoys/Documents/workspace/Imazer/test/00000018.png");
    std::cout << "loaded " << isLoaded << std::endl;
    std::cout << "limage init" << std::endl;
    rawImageWidget->update(image);
}

LabelingWidget::~LabelingWidget(){
}

void LabelingWidget::initRGBThControlBox(){
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
}

void LabelingWidget::initHSVThControlBox(){
    sliderGroupBox = new QGroupBox("Threshold Slider", this);
    sliderGroupBox->setGeometry(340, 70, 700, 400);
    sliderLayout = new QHBoxLayout();
    hsvThBall = new HSVThresholdControlBox("ball");
    sliderLayout->addWidget(hsvThBall);
    hsvThGreen = new HSVThresholdControlBox("green");
    sliderLayout->addWidget(hsvThGreen);
    hsvThLines = new HSVThresholdControlBox("lines");
    sliderLayout->addWidget(hsvThLines);
    hsvThGoalYellow = new HSVThresholdControlBox("goal yellow");
    sliderLayout->addWidget(hsvThGoalYellow);
    hsvThGoalBlue = new HSVThresholdControlBox("goal blue");
    sliderLayout->addWidget(hsvThGoalBlue);
    sliderGroupBox->setLayout(sliderLayout);
}

void LabelingWidget::updateRawImage(QImage *image){
    rawImageWidget->update(image);
}

void LabelingWidget::clickedRawImage(const QPoint &point){
    std::cout << "a " << a << std::endl;
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
    if(!isValueInClass(red, green, blue, rgbThLines)){
	std::cout << "Line" << std::endl;
	updateThresholdToIncludeTheParam(red, green, blue, rgbThLines);
	// TODO if conflicted, change other threshold
    }
    if(!isValueInClass(red, green, blue, rgbThGreen)){
	std::cout << "Green" << std::endl;
	updateThresholdToIncludeTheParam(red, green, blue, rgbThGreen);
	// TODO if conflicted, change other threshold
    }
}

void LabelingWidget::updateThresholdToIncludeTheParam(int red, int green, int blue, RGBThresholdControlBox *rgbTh){
    int distfr;
    int distTor;
    if( !(red < rgbTh->r.fr && red > rgbTh->r.to)){
	// update th and slider
	int distfr = (int)fabs(red - rgbTh->r.fr);
	int distTo = (int)fabs(red - rgbTh->r.to);
	if(distfr < distTo){
	    rgbTh->setThValue(ColorAttributeID::R, red, rgbTh->r.to);
	}
	else{
	    rgbTh->setThValue(ColorAttributeID::R, rgbTh->r.fr, red);
	}
	std::cout << "update red th " << rgbTh->r.fr << " " << rgbTh->r.to << std::endl;
    }
    if( !(green < rgbTh->g.fr && green > rgbTh->g.to)){
	// update th and slider
	int distfr = (int)fabs(green - rgbTh->g.fr);
	int distTo = (int)fabs(green - rgbTh->g.to);
	if(distfr < distTo){
	    rgbTh->setThValue(ColorAttributeID::G, green, rgbTh->g.to);
	}
	else{
	    rgbTh->setThValue(ColorAttributeID::G, rgbTh->g.fr, green);
	}
	std::cout << "update green th " << rgbTh->g.fr << " " << rgbTh->g.to << std::endl;
    }
    if( !(blue < rgbTh->b.fr && blue > rgbTh->b.to)){
	// update th and slider
	int distfr = (int)fabs(blue - rgbTh->b.fr);
	int distTo = (int)fabs(blue - rgbTh->b.to);
	if(distfr < distTo){
	    rgbTh->setThValue(ColorAttributeID::B, blue, rgbTh->b.to);
	}
	else{
	    rgbTh->setThValue(ColorAttributeID::B, rgbTh->b.fr, blue);
	}
	std::cout << "update green th " << rgbTh->b.fr << " " << rgbTh->b.to << std::endl;
    }
}

bool LabelingWidget::isValueInClass(int red, int green, int blue, RGBThresholdControlBox *rgbTh){
    if(red >= rgbTh->r.fr && red <= rgbTh->r.to && blue >= rgbTh->b.fr && blue <= rgbTh->b.to && green >= rgbTh->g.fr && green <= rgbTh->g.to){
	return true;
    }
    return false;
}

void LabelingWidget::updateLabeledImage(){
    std::cout << "updateLabeledImage" << std::endl;
    //std::cout << "a "<< a << std::endl;
    QImage *limage = labeledImageWidget->image;
    //std::cout << "rgb " << image->pixel(0, 1) << std::endl;
    QColor *color;
    int c = 0;
    int pindex;
    int width = 320;
    int height = 240;
    int h, s, v;
    int i = 0;
    int j = 0;
    for(int j = 0 ; j < height ; j++){
	for(int i = 0 ; i < width ; i++){
	    color = new QColor(image->pixel(i, j));
	    color->getHsv(&h, &s, &v);
	    if(hsvThLines->isIncluded(h, s, v)){
		limage->setPixel(i, j, RCNaoObjectColor::LINES.rgb());
		c++;
	    }
	    if(hsvThGreen->isIncluded(h, s, v)){
		limage->setPixel(i, j, RCNaoObjectColor::GREEN.rgb());
		c++;
	    }
	    if(hsvThBall->isIncluded(h, s, v)){
		limage->setPixel(i, j, RCNaoObjectColor::BALL.rgb());
		c++;
	    }
	    if(hsvThGoalYellow->isIncluded(h, s, v)){
		limage->setPixel(i, j, RCNaoObjectColor::GOAL_YELLOW.rgb());
		c++;
	    }
	    if(hsvThGoalBlue->isIncluded(h, s, v)){
		limage->setPixel(i, j, RCNaoObjectColor::GOAL_BLUE.rgb());
		c++;
	    }
	    
	    if(c > 1){
		limage->setPixel(i, j, QColor(247, 171, 166).rgb());
	    }
	    c = 0;
	}
    }
    labeledImageWidget->update();
    delete color;
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
