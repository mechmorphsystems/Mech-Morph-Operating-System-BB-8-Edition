#pragma once

#include <Arduino.h>
#include "Constant.h"
#include "src/DomeLogic.h"

DomeLogic domeLogic;


void setup() {
	domeLogic.init(remoteAddress);
}

void loop() {
	domeLogic.run();
}