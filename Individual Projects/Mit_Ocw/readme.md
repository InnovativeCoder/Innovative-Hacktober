
# MIT-OCW Downloader

Download all video lectures from a MIT-OCW course with a single command.

## Features

* Intentionally detailed names, so that it will display and sort properly
    on most interfaces (e.g., MX Video, or VLC on Android devices).
  * URL and lecture name filters to download only video files.
  * Tested on Mac (Python 3.6).

## Instructions to download OCW using this

* [mit-ocw-scrapper][1] basically needs a link to the video lectures page of a MIT-OCW course
    (which of course has video lectures). The link would be something like [<http://ocw.mit.edu/cources/college/course-title/video-lectures/]>

  * Make a [virtual environment][4] for this project on your local machine and activate it.
  
  * Copy the ```download.py``` file to the folder where you want to download the video lectures.
  
  * Run ```python download.py <Lecture Link>``` or ```python3 download.py <Lecture Link>``` in case you have more than one versions of python installed on your system.  
  
  * Voila! Download must have started by now.
  

## Inspiration

  [coursera-dl/coursera][3]