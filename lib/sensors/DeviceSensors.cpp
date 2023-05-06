#include "DeviceSensors.h"
#include <DHT.h>

/* Номер пина датчика температуры и влажности */
uint8_t DHTPin = 4;

/* Номер пина датчика освещенности */
uint8_t IllumPin = 34;

#define DHTTYPE DHT11
DHT dht(DHTPin, DHTTYPE);

void loopSendSensorsData()
{
    int temp = dht.readTemperature();
    int hum = dht.readHumidity();
    int illum = analogRead(IllumPin);
    loopSendDataToRTDB(temp, hum, illum);
}
