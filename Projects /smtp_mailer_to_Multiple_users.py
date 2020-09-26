#Python code to send emails to multiple users

import smtplib

#List of email_ids to send the mail
#receiver1@example.com can be any email id to which you want the email to be sent

mail_list=["receiver1@example.com","receiver2@example.com","receiver3@example.com"]
for i in mail_list:
    server=smtplib.SMTP('smtp.gmail.com',587)
    server.starttls()
    server.login('sender@example.com','senders_password')
    msg='Hello!'
    server.sendmail('sender@example.com',i ,msg)
    server.quit()


#sender@example.com can be any email id from which you want to send the email
