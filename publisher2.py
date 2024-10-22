import paho.mqtt.publish as publish
publish.single("ifn649","Assessment_2c", hostname="3.106.232.128")
#!/usr/bin/env python3
import serial

import time
import string

if __name__ == '__main__':
 ser=serial.Serial("/dev/rfcomm0",9600)
 ser1=serial.Serial("/dev/rfcomm1",9600)
 ser2=serial.Serial("/dev/rfcomm2",9600)
while True:
	rawserial=ser.readline()
	cookedserial=rawserial.decode('utf-8').strip('\r\n')
	print(cookedserial)
	rawserial=ser1.readline()
	cookedserial=rawserial.decode('utf-8').strip('\r\n')
	print(cookedserial)
	rawserial=ser2.readline()
	cookedserial=rawserial.decode('utf-8').strip('\r\n')
	print(cookedserial)
	
		

	

	
	
print("Done")
