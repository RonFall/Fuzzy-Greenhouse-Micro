#include "DeviceSensors.h"
#include <DHT.h>
#include <BH1750.h>
#include "Wire.h"

// Датчик освещенности
BH1750 lightMeter;

/* Номер пина датчика температуры и влажности */
uint8_t DHTPin = 4;

#define DHTTYPE DHT11
DHT dht(DHTPin, DHTTYPE);

void setupSensors()
{
    Wire.begin();
    lightMeter.begin();
}

void loopSendSensorsData()
{
    int temp = dht.readTemperature();
    int hum = dht.readHumidity();
    int illum = lightMeter.readLightLevel();
    loopSendDataToRTDB(temp, hum, illum);
}
