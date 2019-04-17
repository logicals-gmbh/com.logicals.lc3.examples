This sample can be used to explain and/or understand the usage of MQTT functions in logi.CAD 3.

Key facts of the application:
* There is only one application task running exactly one program (MQTT_Sample) with a cycle time of 500ms
* The broker address and the MQTT client ID can be set by adjusting the global variable init values in the file "globals.global".
* The application publishes data (JSON format) to the topic "/building1/floor1/room1/actor1" every 5 seconds.
* The application subscribes to the topic "/building1/floor1/room1/sensor1" and stores the latest received data in the variable "sLastMessage".
* Conversion from the receive buffer (byte array) to the string "sLastMessage" is done with the C-function "StringFromByteArray".
