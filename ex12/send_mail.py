#!/usr/bin/python3

# import smtplib
# from os.path import basename
# from email.mime.text import MIMEText
# from email.mime.multipart import MIMEMultipart
# from email.mime.application import MIMEApplication

# from_addr = 'adantas.dev.teste@gmail.com'
# to_addr = 'adantas.dev.teste@gmail.com'
# subject = 'ex12'
# content = 'You got mail'

# msg = MIMEMultipart()
# msg['From'] = from_addr
# msg['To'] = to_addr
# msg['Subject'] = subject
# body = MIMEText(content, 'plain')
# msg.attach(body)

# filename = 'incredible.txt'
# with open(filename, 'r') as f:
# 	attachment = MIMEApplication(f.read(), Name=basename(filename))
# 	attachment['Content-Disposition'] = 'attachment; filename="{}"'.format(basename(filename))

# msg.attach(attachment)

# server = smtplib.SMTP('smtp.dreamhost.com', 587)
# server.login(from_addr, 'Senhab0b4123')
# server.send_message(msg, from_addr=from_addr, toaddrs=[to_addr])

import smtplib
from email import message

from_addr = 'adantas.dev.teste@gmail.com'
to_addr = 'adantas.dev.teste@gmail.com'
subject = 'I just sent this email from Python!'
body = 'How neat is that?'

msg = message.Message()
msg.add_header('from', from_addr)
msg.add_header('to', to_addr)
msg.add_header('subject', subject)
msg.set_payload(body)

msg

server = smtplib.SMTP('smtp.gmail.com', 465)
server.login(from_addr, 'Senhab0b4123')
server.send_message(msg, from_addr=from_addr, to_addrs=[to_addr])
