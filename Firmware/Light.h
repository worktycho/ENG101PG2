
#ifndef LIGHT_H
#define LIGHT_H

#define BIT_LIGHT BIT5

int readLight();
float calibrateLight(int voltage);
void outputLight(float light);

#endif
