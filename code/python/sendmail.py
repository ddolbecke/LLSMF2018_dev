import time
import smtplib
from email.mime.text import MIMEText
import sys

def sendTxt(txt):  
    msg = MIMEText(txt)
    msg['Subject'] = 'computation' 
    msg['To'] = 'base.station'
    msg['From'] = 'security.alarm'
    
    
    
    server = smtplib.SMTP('smtp.uclouvain.be', 587)
    server.starttls()
    server.login("id", "password")
    server.sendmail("sender", "receiver",msg.as_string())
    server.quit()



