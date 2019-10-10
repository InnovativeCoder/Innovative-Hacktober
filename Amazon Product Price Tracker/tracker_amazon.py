import requests
import re
import smtplib
import time
from bs4 import BeautifulSoup

#url is taken from user as input in command line
#URL = 'https://www.amazon.in/JBL-Stealth-Waterproof-Portable-Bluetooth/dp/B07HHHMWQG/ref=br_msw_pdt-9?_encoding=UTF8&smid=A14CZOWI0VEHLG&pf_rd_m=A1VBAL9TL5WCBF&pf_rd_s=&pf_rd_r=43MCCDEX3SYEMNHPXKHF&pf_rd_t=36701&pf_rd_p=9806b2c4-09c8-4373-b954-bae25b7ea046&pf_rd_i=desktop'

#will have to get user agent automatically in future
headers = {"User-Agent": 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.142 Safari/537.36' }

#Function to extract numbers from a string
def extractNumFromStr(productPrice):
	numbers = re.findall('\d+',productPrice)
	numbers = list(map(int, numbers))
	return numbers
#Convert list into a single number
def cvtList2num(productPrice):
	#convert int to str
	numbers = [str(i) for i in productPrice]
	val = int("".join(numbers))
	return(val)

def checkPrice():
	page = requests.get(URL, headers=headers)
	soup = BeautifulSoup(page.content, 'html.parser')

	#print(soup.prettify())

	pageTitle = soup.find(id='productTitle').get_text() #Find and get the Title
	pageTitle = pageTitle.strip() #Remove extra white space above and below Title
	#print(pageTitle)

	productPrice = soup.find(id="priceblock_ourprice").get_text().strip()
	#print(productPrice)
	productPrice = extractNumFromStr(productPrice)
	productPrice = cvtList2num(productPrice)
	productPrice /= 10
	productPrice = int(productPrice)
	print("\n\tCurrent price of the product is:\t₹ ",productPrice,"\n\tCurrent Time: ",time.ctime())
	if (productPrice < expectedPrice):
		send_mail(pageTitle) #initiate email process
	else:
		print("\n\tSorry price is still higher than expected.\n\n**PRESS Ctrl+C to exit this program**\n") #Email was not sent. Price is still higher
def send_mail(pageTitle):
	server = smtplib.SMTP('smtp.gmail.com',587)
	server.ehlo()
	server.starttls()
	server.ehlo()
	server.login('example@noreply.com', 'rgnskdlerpritwnq')
	subject = "Product Price fell!"+pageTitle
	#link = "https://www.amazon.in/JBL-Stealth-Waterproof-Portable-Bluetooth/dp/B07HHHMWQG/ref=br_msw_pdt-9?_encoding=UTF8&smid=A14CZOWI0VEHLG&pf_rd_m=A1VBAL9TL5WCBF&pf_rd_s=&pf_rd_r=43MCCDEX3SYEMNHPXKHF&pf_rd_t=36701&pf_rd_p=9806b2c4-09c8-4373-b954-bae25b7ea046&pf_rd_i=desktop"
	link = URL
	msg = f"Subject:{subject}\n\nHey Price of {pageTitle} fell!!! Click the link blow and purchase it now!!!\n\n{link}\n\n"
	server.sendmail(
		'example@noreply.com',
		'alert@gotyourproduct.com',
		msg
		)
	print("Email has been sent!!!\n\n**PRESS Ctrl+C to exit this program**\n")
	server.quit()

#Driver Program
if __name__ == "__main__":
	while(True):
		expectedPrice = int(input("\n\tWhat price are you expecting or looking for:\t₹ "))
		URL = input('\n\tInput the Amazon link here:\n\n')
		checkPrice()
		time.sleep(1*24*60*60) #Check once per day