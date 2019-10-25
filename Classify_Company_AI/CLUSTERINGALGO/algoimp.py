from googlesearch import search
query = 'geeks'
for i in search(query,tld = "com",num=10,stop=1,pause=2):
    print (i)
