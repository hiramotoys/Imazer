#include "RGBThresholdControlBox.h"

RGBThresholdControlBox::RGBThresholdControlBox(const QString &title, QWidget *iParent) : QGroupBox(title, iParent){
    layout = new QVBoxLayout();
    QRect rectRedSlider(0, 0, 100, 50);
    redSlider = new ThresholdSliderBox(0, 255, ColorAttributeID::R, rectRedSlider, "red threshold");
    layout->addWidget(redSlider);
    QRect rectGreenSlider(0, 50, 100, 50);
    greenSlider = new ThresholdSliderBox(0, 255, ColorAttributeID::G, rectGreenSlider, "green threshold");
    layout->addWidget(greenSlider);
    QRect rectBlueSlider(0, 100, 100, 50);
    blueSlider = new ThresholdSliderBox(0, 255, ColorAttributeID::B, rectBlueSlider, "blue threshold");
    layout->addWidget(blueSlider);
    r.fr = 0;
    r.to = 0;
    g.fr = 0;
    g.to = 0;
    b.fr = 0;
    b.to = 0;
    setLayout(layout);
}

RGBThresholdControlBox::RGBThresholdControlBox(const QRect &rect, const QString &title, QWidget *iParent) : QGroupBox(title, iParent){
    setGeometry(rect);
    layout = new QVBoxLayout();
    QRect rectRedSlider(0, 0, 100, 50);
    redSlider = new ThresholdSliderBox(0, 255, ColorAttributeID::R, rectRedSlider, "red threshold");
    layout->addWidget(redSlider);
    QRect rectGreenSlider(0, 50, 100, 50);
    greenSlider = new ThresholdSliderBox(0, 255, ColorAttributeID::G, rectGreenSlider, "green threshold");
    layout->addWidget(greenSlider);
    QRect rectBlueSlider(0, 100, 100, 50);
    blueSlider = new ThresholdSliderBox(0, 255, ColorAttributeID::B, rectBlueSlider, "blue threshold");
    layout->addWidget(blueSlider);
    r.fr = 0;
    r.to = 0;
    g.fr = 0;
    g.to = 0;
    b.fr = 0;
    b.to = 0;
    setLayout(layout);
}

RGBThresholdControlBox::~RGBThresholdControlBox(){
}

/**
 * update slider value and threshold
 */
void RGBThresholdControlBox::setThValue(const int cattribute, int fr, int to){
    switch(cattribute){
    case ColorAttributeID::R:
	r.fr = fr;
	r.to = to;
	redSlider->setValue(fr, to);
	break;
    case ColorAttributeID::G:
	g.fr = fr;
	g.to = to;
	greenSlider->setValue(fr, to);
	break;
    case ColorAttributeID::B:
	b.fr = fr;
	b.to = to;
	blueSlider->setValue(fr, to);
	break;
    }
}

/**
 * moved slider, update threshold
 */
void RGBThresholdControlBox::updateThFrBySlider(const int cattribute, int fr){
    switch(cattribute){
    case ColorAttributeID::R:
	r.fr = fr;
	break;
    case ColorAttributeID::G:
	g.fr = fr;
	break;
    case ColorAttributeID::B:
	b.fr = fr;
	break;
    }
}

/**
 * moved slider, update threshold
 */
void RGBThresholdControlBox::updateThToBySlider(const int cattribute, int to){
    switch(cattribute){
    case ColorAttributeID::R:
	r.to = to;
	break;
    case ColorAttributeID::G:
	g.to = to;
	break;
    case ColorAttributeID::B:
	b.to = to;
	break;
    }
}
