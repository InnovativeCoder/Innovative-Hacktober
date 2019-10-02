SMTPserver = 'mail.example.com'
sender = 'contact@example.com'

USERNAME = "example"
PASSWORD = "example@1234"

# typical values for text_subtype are plain, html, xml

subject="Further Selection : EDC BVUCOEP"

import sys
import os
import re
import csv
import time
import email.utils
import smtplib

from smtplib import SMTP_SSL as SMTP
# this invokes the secure SMTP protocol (port 465, uses SSL)
# from smtplib import SMTP                  # use this for standard SMTP protocol   (port 25, no encryption)

# old version
# from email.MIMEText import MIMEText
from email.mime.text import MIMEText
conn = SMTP(SMTPserver)
conn.set_debuglevel(False)
conn.login(USERNAME, PASSWORD)
with open('smc.csv') as data:
    row = csv.DictReader(data)
    for line in row:
        name = line['fullname']
        add = line['email']
        text_subtype = 'html'
        content="""<p>Email in html template</p>"""
        msg = MIMEText(content, text_subtype)
        try:
            msg['Subject'] = subject
            msg['From'] = sender # some SMTP servers will do this automatically, not all
            # try:
            conn.sendmail(sender, add, msg.as_string())
            print('Mail sent to '+add)
        except:
            time.sleep(2)
            print('Terminating SMTP connection!')
            exit()
conn.quit()
