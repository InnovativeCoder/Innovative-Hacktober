"""I have not made any functions because apparently selenium has some issues with function, the windows close when a function is executed, and I have no idea why tell me if you find something"""
from selenium import webdriver ##download selenium driver, using pip install selenium or choose any method. Download chromedriver and keep in the same folder with this .py file. Note before downloading check for the chrome version
from selenium.webdriver.common.keys import Keys #for clicking in elements
import time 
from selenium.webdriver.common.action_chains import ActionChains
import pyautogui #for hitting regresh 
number = []
intro = """The following script is done by github.com/samarth2207........................................................................................."""
print(intro)
intro_2 = """Please Enter the phone number in this format YYXXXXXXXXXX where YY are country code for example 918989734123 AND Enter the message after scanning the QRcode in whatsapp """
print(intro_2)
start = time.time()
time.sleep(3)
qubits = webdriver.Chrome('/home/rohitb1023/Desktop/whatsapp/chromedriver')
qubits.get("https://web.whatsapp.com")
print("Enter the WhatsApp message you want to Broadcast") #enter the message after scanning the QRCODE of whatsapp web.
message = str(input())
try:              #This block will look for 'number.txt' file in the same folder. provide it and enter the respective phone number, yyxxxxxxxxxx (enter new phone number in new line) where yy is country code and xxxxxxxxxx is phone number 
	f = open('number.txt','r')
	for line in f:
		number.append(line)
	print("message will be send to:")
	print (number)
	j = 0
except:    #If 'number.txt file is absent this block will execute, Enter the number in following format yyxxxxxxxxxx where yy is country code and xxxxxxxxxx is phone number. 
	while True:
		print ("Enter the number")
		data = int(input())
		number.append(data)
		print("Are you done with numbers? y/n")
		done1 = str(input())
	
		if done1== "y":
			print("Numbers you have entered are:")
			print (number)
			break


for i in number:
	z=1
	while True:
		
		try:
			if str(number[j]) == 'END':
				break
			qubits.get("https://api.WhatsApp.com/send?phone={}&text={}".format(number[j],message)) #this will open the API link
			j = j +1
			time.sleep(0.25)
			e = qubits.find_element_by_xpath('//*[@title="Share on WhatsApp"]') #[@title="Share on WhatsApp"] may change with time, inspect element to update
			e.click()
			break
		except: #sometimes webpage will load but whahtsapp will still render its webpage, so this block will keep trying to fing the element.
			print("Problem opening API link.Please wait or hit refresh in browser.Number of Retry performed: "+str([z]))
			z = z+1
			time.sleep(3)
			pyautogui.press('esc')
			
			
		

	k = 0 #deals with long waiting

	while True:

		if str(number[j-1]) == 'END':
			break
		try:
			element = qubits.find_element_by_class_name('_3M-N-') # ('_3M-N-') may change with time, inspect element send buttoon on whatsapp web to update this class name
			element.click()
			time.sleep(2)
			print("/n")
			print("Going for Next one: "+str(number[j]))
			break
		except:
			print(str(k)+" Retrying:")
			time.sleep(3)
			k = k+1
			if k>8: #if exception is raised for more than 24 seconds the Api link will launch once again
				qubits.get("https://api.WhatsApp.com/send?phone={}&text={}".format(number[j-1],message))  
				print('refreshed')
				time.sleep(0.25)
				e = qubits.find_element_by_xpath('//*[@title="Share on WhatsApp"]')
				e.click()
				k = 0
print(start)				

			
		
	
