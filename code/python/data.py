import time
import serial

port = '/dev/tty.usbserial-AJV9IK97' 


ser = serial.Serial(
	port=port,
	baudrate=56818.2,
	bytesize=8,
	parity='N',
	timeout=0.1,
	stopbits= 1,
)

if (not ser.isOpen()):
    ser.open()
    
              
r=''
with open('records.txt','w') as ff:
    ff.write('var1,var2,var3\n')
    while 1:
        r=ser.readline()
        if r == 'fini\n':
            break;
        if r:
            print r[:-1]
        ff.write(r)
        time.sleep(0.001)   
        
ser.close()