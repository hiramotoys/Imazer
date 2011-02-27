#include "HSVThresholdControlBox.h"

HSVThresholdControlBox::HSVThresholdControlBox(const QString &title, QWidget *iParent) : QGroupBox(title, iParent){
    layout = new QVBoxLayout();
    QRect rectHSlider(0, 0, 100, 50);
    hSlider = new ThresholdSliderBox(ColorAttributeID::H, rectHSlider, "hue");
    layout->addWidget(hSlider);
    QRect rectSSlider(0, 50, 100, 50);
    sSlider = new ThresholdSliderBox(ColorAttributeID::S, rectSSlider, "saturation");
    layout->addWidget(sSlider);
    QRect rectVSlider(0, 100, 100, 50);
    vSlider = new ThresholdSliderBox(ColorAttributeID::V, rectVSlider, "brightness");
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
    hSlider = new ThresholdSliderBox(ColorAttributeID::H, rectHSlider, "hue");
    layout->addWidget(hSlider);
    QRect rectSSlider(0, 50, 100, 50);
    sSlider = new ThresholdSliderBox(ColorAttributeID::S, rectSSlider, "saturation");
    layout->addWidget(sSlider);
    QRect rectVSlider(0, 100, 100, 50);
    vSlider = new ThresholdSliderBox(ColorAttributeID::V, rectVSlider, "brightness");
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
}

bool HSVThresholdControlBox::isIncluded(int h, int s, int v){
    int count = 0;
    if(h.fr < h.to){
	if(h.fr <= h && h <= h.to){
	    count++;
	}
    }
    else{
	if(h.fr <= h || h <= h.to){
	    count++;
	}
    }
    if(s.fr < s.to){
	if(s.fr <= s && s <= s.to){
	    count++;
	}
    }
    else{
	if(s.fr <= s || s <= s.to){
	    count++;
	}
    }
    if(v.fr < v.to){
	if(v.fr <= v && v <= v.to){
	    count++;
	}
    }
    else{
	if(v.fr <= v || v <= v.to){
	    count++;
	}
    }
    if(count == 3){
	return true;
    }
    else{
	return false;
    }
}
