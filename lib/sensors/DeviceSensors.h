#include "DeviceFirebase.h"

/* Настройка датчиков, инициализация компонентов */
void setupSensors();

/* Отправляет данные с датчиков в DeviceFirebase#loopSendDataToRTDB */
void loopSendSensorsData();