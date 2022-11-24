### 1. ¿Que es MqTT?

Es un protocolo de conectividad máquina a máquina (M2M)/ "Internet de las cosas". Fue diseñado como un transporte de mensajes de publicación/sucripción extremadamente 
ligero (Comparado a los metodos GET y POST). Es util para conexiones con ubicaciones remotas donde se requiere una pequenahuella de codigo y/o el ancho de banda de la 
red es muy importante.

Para tener un sistema y una comunicacion a traves de MqTT necesitamos un elemento importante: El Broker. El broker es el dispositivo que va a gestionar la recepcion y
transmicion de datos hacia dispositivos y desde dispositivos de IOT. Dispositivos que pueden tener en su configuracion sensores ( Que pueden estar conectados a 
dispositivos electronicos) y estos sensores pueden enviar la data hacia un broker. Por ejemplo, si queremos un ejemplo practico un dispositivo podia ser unos ESP32, 
una tarjeta arduino, una raspberry. Un broker podia ser un dispositivo como un rasberry pi, una pc que esta instalado en el broker de mqtt o puede ser un cloud en la nube.

Cuales son las instrucciones que se utilizan para transmitir los datos?

La primera de ellas es suscribe o suscripcion
la segunda es publish o publicacion
y hay una tercera que se llama topic.

<img src= https://mqtt.org/assets/img/mqtt-publish-subscribe.png width='50%'/>

>https://mqtt.org/

