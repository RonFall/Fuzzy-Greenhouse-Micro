#include "DeviceFirebase.h"
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

FirebaseData fireData;
FirebaseConfig fireConfig;
FirebaseAuth fireAuth;

void initFirebaseService(String deviceApiKey, String deviceDatabaseUrl, String deviceEmail, String devicePass)
{
  /* Уникальный индентификатор микроконтроллера (присваивается всем пользователям Firebase Auth) */
  String deviceUid;

  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

  // Определение уникального ключа устройства и ссылки на Firebase Realtime Database
  fireConfig.api_key = deviceApiKey;
  fireConfig.database_url = deviceDatabaseUrl;

  // Определение учетных данных для микроконтроллера
  fireAuth.user.email = deviceEmail;
  fireAuth.user.password = devicePass;

  // Получение уникального токена микроконтроллера
  fireConfig.token_status_callback = tokenStatusCallback;

  // Регистрация работы сервиса
  Firebase.begin(&fireConfig, &fireAuth);

  // Получение UID и его отображение
  Serial.println("Получение UID микроконтроллера");
  while ((fireAuth.token.uid) == "")
  {
    Serial.print('.');
    delay(1000);
  }

  deviceUid = fireAuth.token.uid.c_str();
  Serial.print("UID микроконтроллера: ");
  Serial.println(deviceUid);
  Serial.print("Адрес обращения к Realtime Database: ");
  Serial.println("");
}

void loopSendDataToRTDB(int temp, int hum, int illum)
{
  String deviceUid = fireAuth.token.uid.c_str();

  String basePath = "/devices/" + deviceUid;
  String tempPath = basePath + "/temperature";
  String humpPath = basePath + "/humidity";
  String illumPath = basePath + "/illumination";

  if (Firebase.ready())
  {
    Firebase.setInt(fireData, tempPath, temp);
    Firebase.setInt(fireData, humpPath, hum);
    Firebase.setInt(fireData, illumPath, illum);
    delay(100);
  }
}
