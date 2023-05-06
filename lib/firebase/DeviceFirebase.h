#include <WString.h>
#include <FirebaseESP32.h>

/*!
Инициализация сервиса Firebase
\param[in] deviceApiKey Уникальный ключ устройства (настриавается в Google Cloud)
\param[in] deviceDatabaseUrl Ссылка на Firebase Realtime Database для записи данных
\param[in] deviceEmail Email для авторизации устройства
\param[in] devicePass Пароль
*/
void initFirebaseService(String deviceApiKey, String deviceDatabaseUrl, String deviceEmail, String devicePass);

/*!
Отправка данных с сформированными путями в Realtime Database
\param[in] temp Температура
\param[in] hum Влажность
\param[in] illum Освещенность
*/
void loopSendDataToRTDB(int temp, int hum, int illum);