/*
 * Multi-motor control
 *
 * Move two or three motors at the same time.
 *
 * Copyright (C)2017 Laurentiu Badea
 *
 * This file may be redistributed under the terms of the MIT license.
 * A copy of this license has been included with this distribution in the file LICENSE.
 */
#include <Arduino.h>
#include "BasicStepperDriver.h"
#include "SyncDriver.h"

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200

// X motor
#define DIR_X 5
#define STEP_X 9

// Y motor
#define DIR_Y 8
#define STEP_Y 6

// If microstepping is set externally, make sure this matches the selected mode
// 1=full step, 2=half step etc.
#define MICROSTEPS 32

// 2-wire basic config, microstepping is hardwired on the driver
// Other drivers can be mixed and matched but must be configured individually
BasicStepperDriver stepperX(MOTOR_STEPS, DIR_X, STEP_X);
BasicStepperDriver stepperY(MOTOR_STEPS, DIR_Y, STEP_Y);

SyncDriver controller(stepperX, stepperY);

void setup() {
    /*
     * Set target motors RPM.
     */
    stepperX.begin(30, MICROSTEPS);
    stepperY.begin(90, MICROSTEPS);
}

void loop() {

    controller.rotate(90*5, 60*15);
    delay(1000);
    controller.rotate(-90*5, -30*15);
    delay(1000);
    controller.rotate(0, -30*15);
    delay(30000);
}
