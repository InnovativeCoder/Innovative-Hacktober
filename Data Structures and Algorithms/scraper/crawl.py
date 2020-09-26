from bs4 import BeautifulSoup 
from urllib.request import urlopen
import ssl
import url

def data(string):
	# Ignore SSL certificate errors
	ctx = ssl.create_default_context()
	ctx.check_hostname = False
	ctx.verify_mode = ssl.CERT_NONE
	links = list()
	text =''	
	#string = 'https://python.org'

	try:
		html = urlopen(string, context=ctx).read()
		print('works')

	except:
		html = urlopen('http://detectportal.firefox.com', context=ctx).read()
		print('link')

	soup = BeautifulSoup(html, "html.parser")
	a = 0
		
	tag_a = soup('a')
	for tag in tag_a:
		# print('TAG:', tag)
		# print('URL:', tag.get('href', None))
		# print('Contents:', tag.contents[0])
		# print('Attrs:', tag.attrs)
		# print('')
		href = tag.get('href',None)
		print(href)
		if href is not None:
			if 'http' in href :
				links.append(href)
			elif href is '':
				a
			elif href[0] == '#':
				a
			elif href == '/':
				a
			elif url.isHog(href):
				a		
			elif href[0] == '/' and href[1] == '/':
				links.append(href[2:])	
			elif href[0] == '/' and string[-1] != '/':
				links.append(string + href)
			elif string[-1] == '/' and href[0] != '/':
				links.append(string + href)
			else:
				links.append(string + '/' + href)
				links.append(href)

		
	text = " ".join(soup.get_text().split())
	#text = text.prettify()
	# print (links)
	# print('done')
	return links,text
	