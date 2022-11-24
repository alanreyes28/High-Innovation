### 1. ¿Que es MqTT?

Es un protocolo de conectividad máquina a máquina (M2M)/ "Internet de las cosas". Fue diseñado como un transporte de mensajes de publicación/sucripción extremadamente 
ligero (Comparado a los metodos GET y POST). Es util para conexiones con ubicaciones remotas donde se requiere una pequenahuella de codigo y/o el ancho de banda de la 
red es muy importante.

Para tener un sistema y una comunicacion a traves de MqTT necesitamos un elemento importante: El Broker. El broker es el dispositivo que va a gestionar la recepcion y
transmicion de datos hacia dispositivos y desde dispositivos de IOT. Dispositivos que pueden tener en su configuracion sensores ( Que pueden estar conectados a 
dispositivos electronicos) y estos sensores pueden enviar la data hacia un broker. Por ejemplo, si queremos un ejemplo practico un dispositivo podia ser unos ESP32, 
una tarjeta arduino, una raspberry. Un broker podia ser un dispositivo como un rasberry pi, una pc que esta instalado en el broker de mqtt o puede ser un cloud en la nube.

Cuales son las instrucciones que se utilizan para transmitir los datos?

1) suscripcion - Sirve para que un cliente pueda recibr un mensaje mediante un topic
2) publicacion - Sirve para enviar mensajes a un cliente o un broker
3) que se llama topic - La ruta necesaria para poder direccionar una suscripcion o publicacion

### MqTT Publish/ Subscribe Architecture
<img src= https://mqtt.org/assets/img/mqtt-publish-subscribe.png width='50%'/>

>https://mqtt.org/

### 2. Modos de conexiones

Eclipse Mosquitto es un agente de mensajes de codigo abierto, liviano y adecuado para trabajr con el protocolo MqTT mediante mensajes usando publish y subscribe.

<img src= http://mosquitto.org/images/mosquitto-text-side-28.png width='50%'/>

Lista de puertos que trabaja mosquitto:
    -1883: MQTT, unencrypted 
    -8883: MQTT, encrypted
    -8884: MQTT, encrypted, client certificate required
    -8887: MQTT, encrypted, server certificate deliberately expired
    -8880: MQTT over Websockets, unencrypted
    -8081: MQTT over WebSockets, encrypted

>http://mosquitto.org/


### 3. NODE-RED

Node-RED es una herramienta de programacion para conectar dispositivos de hardware, API y servicios en linea de varias formas interesantes.

Proporciona un editoir basado en navegador que facilita la conexion de flujos entre si utilizando la amplia gama de nodos de la paleta que se pueden implementar en su 
tiempo de ejecucion con un solo clic.
<img src= https://upload.wikimedia.org/wikipedia/commons/2/2b/Node-red-icon.png width='50%'/>
<img src= https://infosys.beckhoff.com/content/1033/tf6720_tc3_iot_data_agent/Images/png/3295782027__en-US__Web.png width='50%'/>