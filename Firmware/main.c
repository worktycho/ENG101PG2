
void setupADCs() {}

int readTemp() {}
float calibrateTemp(int voltage) {}
void outputTemp(float temp) {}

void setHeater(float temp) {}

int readLight() {}
float calibrateLight(int voltage) {}
void outputLight(float light) {}

int readpH() {}
float calibratepH(int voltage) {}
void outputpH(float pH) {}

int readRotation();
int calibrateRPM(int RawRotationCount);
void outputRPM(int RPM);
    
void setMotor(int RPM);

void inputLoop() {
    int tempVoltage = readTemp();
    float tempValue = calrbrateTemp(tempVoltage);
    outputTemp(tempValue);
    
    int lightVoltage = readLight();
    float lightValue = calbrateLight(lightVoltage);
    outputLight(lightValue);
    
    int pHVoltage = readpH();
    float pHValue = calbratepH(pHVoltage);
    outputpH(pHValue);
    
    int RawRotationCount = readRotation();
    int RPM = calibrateRPM(RawRotationCount);
    outputRPM(RPM);
    
    setMotor(RPM);
    setHeater(tempValue);
}

int main() {
    setupADCs();
    inputLoop();
}
