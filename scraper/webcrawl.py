import crawl
from db import *
from chew import *


def webcrawl(link):
	i = 0
	level = 1
	newerlinks = list()
	(links,text) = crawl.data(link)

	if text == 'success':
		link = 'test'

	cmd = "INSERT OR REPLACE INTO links (url,txt) values ('%s', '%s');" %(link,chew(text))
	# print(cmd)
	db(cmd)

	for l in range(level):
		for link in links:
			# thislink = link
			(templinks,text) = crawl.data(link)
			cmd = "INSERT OR REPLACE INTO links (url,txt) values ('%s', '%s');" %(link,chew(text))
			db(cmd)
			i = i + 1
			newerlinks = newerlinks + templinks

		links = newerlinks	

	print(i)
	cmd = "delete from links where txt = 'success' or txt = '';"
	db(cmd)
	print("\n\n\n\n\n\nSUCCESS\n\n")
	return	

