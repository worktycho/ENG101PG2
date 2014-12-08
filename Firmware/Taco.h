
#ifndef TACO_H
#define TACO_H

#define BIT_ROTATION BIT0
#define ROTATION_SCALE 1
#define ROTATION_OFFSET 0

void setupRotation();

int readRotation();

int calibrateRPM(int RawRotationCount);

void outputRPM(int RPM);

#endif
