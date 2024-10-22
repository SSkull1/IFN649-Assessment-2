import paho.mqtt.client as mqtt
import serial
import time
import string

 
def on_connect(client, userdata, flags, rc): # func for making connection
	print("Connected to MQTT")
	print("Connection returned result: " + str(rc) )
	
	client.subscribe("ifn649")
def on_message(client, userdata, msg):       # Func for Sending msg
	print(msg.topic+" "+str(msg.payload))	
	ser = serial.Serial("/dev/rfcomm0",9600)
	ser1 = serial.Serial("/dev/rfcomm1",9600)
	ser2 = serial.Serial("/dev/rfcomm2",9600)
	ser.write(str.encode(str(msg.payload)))
	ser1.write(str.encode(str(msg.payload)))
	ser2.write(str.encode(str(msg.payload)))
	
	
	
	
	
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
 
client.connect("3.106.232.128", 1883, 60)
 
client.loop_forever()
