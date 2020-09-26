def isHog(url):
	ext = ['.pdf','.img','.jpg','.jpeg','.png','.doc','.gif','.rar','.zip','.txt','.mp3','.png','.tiff','.js','.css','.exe','.svg','.md']
	for e in ext:
		if e in url:
			return True
		else:
			return False	
