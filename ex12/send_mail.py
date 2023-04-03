#!/usr/bin/python3

import smtplib
from os.path import basename
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.application import MIMEApplication

from_addr = 'adantas.dev.test@hotmail.com'
to_addr = 'adantas.dev.test@hotmail.com'
subject = 'ex12'
content = 'You got mail'

msg = MIMEMultipart()
msg['From'] = from_addr
msg['To'] = to_addr
msg['Subject'] = subject
body = MIMEText(content, 'plain')
msg.attach(body)

filename = 'incredible.txt'
with open(filename, 'r') as f:
	attachment = MIMEApplication(f.read(), Name=basename(filename))
	attachment['Content-Disposition'] = 'attachment; filename="{}"'.format(basename(filename))

msg.attach(attachment)

server = smtplib.SMTP('smtp.office365.com', 587)
server.ehlo('smtp.office365.com')
server.starttls()
server.login(from_addr, 'Senhab0b4123')
server.ehlo('smtp.office365.com')
server.send_message(msg, from_addr=from_addr, to_addrs=[to_addr])
