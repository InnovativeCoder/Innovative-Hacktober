from db import *
def search(key):
	#key = input("Keyword : ")
	cmd = "SELECT url from links where txt like '%" + key + "%';"
	print (cmd)
	rows = db(cmd)
	for row in rows:
		print(row[0])
	return rows

