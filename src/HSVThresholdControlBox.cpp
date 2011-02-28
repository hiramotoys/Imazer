#include "HSVThresholdControlBox.h"
#include "LabelingWidget.h"
#include <iostream>
#include<typeinfo>

HSVThresholdControlBox::HSVThresholdControlBox(const QString &title, QWidget *iParent) : QGroupBox(title, iParent){
    layout = new QVBoxLayout();
    QRect rectHSlider(0, 0, 100, 50);
    hSlider = new ThresholdSliderBox(0, 359, ColorAttributeID::H, rectHSlider, "hue");
    layout->addWidget(hSlider);
    QRect rectSSlider(0, 50, 100, 50);
    sSlider = new ThresholdSliderBox(0, 255, ColorAttributeID::S, rectSSlider, "saturation");
    layout->addWidget(sSlider);
    QRect rectVSlider(0, 100, 100, 50);
    vSlider = new ThresholdSliderBox(0, 255, ColorAttributeID::V, rectVSlider, "brightness");
    layout->addWidget(vSlider);
    h.fr = 0;
    h.to = 0;
    s.fr = 0;
    s.to = 0;
    v.fr = 0;
    v.to = 0;
    setLayout(layout);
}

HSVThresholdControlBox::HSVThresholdControlBox(const QRect &rect, const QString &title, QWidget *iParent) : QGroupBox(title, iParent){
    setGeometry(rect);
    layout = new QVBoxLayout();
    QRect rectHSlider(0, 0, 100, 50);
    hSlider = new ThresholdSliderBox(0, 359, ColorAttributeID::H, rectHSlider, "hue");
    layout->addWidget(hSlider);
    QRect rectSSlider(0, 50, 100, 50);
    sSlider = new ThresholdSliderBox(0, 255, ColorAttributeID::S, rectSSlider, "saturation");
    layout->addWidget(sSlider);
    QRect rectVSlider(0, 100, 100, 50);
    vSlider = new ThresholdSliderBox(0, 255, ColorAttributeID::V, rectVSlider, "brightness");
    layout->addWidget(vSlider);
    h.fr = 0;
    h.to = 0;
    s.fr = 0;
    s.to = 0;
    v.fr = 0;
    v.to = 0;
    setLayout(layout);
}

HSVThresholdControlBox::~HSVThresholdControlBox(){
}

void HSVThresholdControlBox::updateThFrBySlider(const int cattribute, int fr){
    std::cout << "updateThFrBySlider" << std::endl;
    switch(cattribute){
    case ColorAttributeID::H:
	h.fr = fr;
	break;
    case ColorAttributeID::S:
	s.fr = fr;
	break;
    case ColorAttributeID::V:
	v.fr = fr;
	break;
    }
    ((LabelingWidget*)(parentWidget()->parentWidget()))->updateLabeledImage();
}

void HSVThresholdControlBox::updateThToBySlider(const int cattribute, int to){
    switch(cattribute){
    case ColorAttributeID::H:
	h.to = to;
	break;
    case ColorAttributeID::S:
	s.to = to;
	break;
    case ColorAttributeID::V:
	v.to = to;
	break;
    }
    ((LabelingWidget*)(parentWidget()->parentWidget()))->updateLabeledImage();
}

bool HSVThresholdControlBox::isIncluded(int h, int s, int v){
    int count = 0;
    //    std::cout << "h " << this->h.fr << " " << this->h.to << std::endl;
    //std::cout << "s " << this->s.fr << " " << this->s.to << std::endl;
    //std::cout << "v " << this->v.fr << " " << this->v.to << std::endl;
    if(this->h.fr != this->h.to){
	if(this->h.fr < this->h.to){
	    if(this->h.fr <= h && h <= this->h.to){
		count++;
		//std::cout << "h true" << std::endl;
	    }
	}
	else{
	    if(this->h.fr <= h || h <= this->h.to){
		count++;
	    }
	}
    }
    if(this->s.fr != this->s.to){
	if(this->s.fr < this->s.to){
	    if(this->s.fr <= s && s <= this->s.to){
		count++;
		//std::cout << "s true" << std::endl;
	    }
	}
	else{
	    if(this->s.fr <= s || s <= this->s.to){
		count++;
	    }
	}
    }
    if(this->v.fr != this->v.to){
	if(this->v.fr < this->v.to){
	    if(this->v.fr <= v && v <= this->v.to){
		count++;
		//std::cout << "v true" << std::endl;
	    }
	}
	else{
	    if(this->v.fr <= v || v <= this->v.to){
		count++;
	    }
	}
    }
    
    if(count == 3){
	return true;
    }
    else{
	return false;
    }
}
