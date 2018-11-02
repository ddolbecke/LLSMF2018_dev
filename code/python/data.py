
import time
import serial
import smtplib  
#import sendmail

port = 3#'COM3'#here you have to put the location of serial connection (this was for ubuntu).



# ser = serial.Serial(
    # port=port,
    # baudrate=56818.2,
    # bytesize=8,
    # parity='N',
    # timeout=0.1,
    # stopbits= 1,
#)

ser=serial.Serial('COM3',57600)
if (not ser.isOpen()):
    ser.open()
ser.flushInput()
once=True             
r=''


line = []

# while True:
	# c=ser.read()
	# print c#,c.decode("hex")
    # #for c in ser.read():
		
		# # line.append(c.decode())
		# # #print c
		# # if (line.find('\r\n')>0):
			# # print("Line: " + ''.join(line))
            # # line = []
            # # break
while 1:
    r=ser.readline() #it receives the message line by line. That's why each message should finish by \n\r, to introduce this newline.
    if r:
    	#your code here
    	#for example here it prints true if "1" is in r.
		#print r.decode("utf-8")
		#print r,len(r),r[0]
		print r
		#print r.find('3') 
		#print type(r)
		#print int(r)
		#sendTxt('alert alert !!')
	
    time.sleep(0.001)  
print 'FIN'      
ser.close()