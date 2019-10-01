'''
Dependencies:-
    tldextract             pip3 install tldextract
    xmltodict              pip3 install xmltodict
'''
import requests, json, tldextract
from bs4 import BeautifulSoup
import re, datetime, traceback, sys
from Utils import Utils
from urllib.parse import urlparse
import feedparser
class ShowUrlCategory():
    def __init__(self,parameters):
        self.url = parameters.get("url","")
        self.web_url = ''
        self.rss_final_links = []
        self.checked_list = []
        self.scheme = ''
        self.domain_name = tldextract.extract(self.url).domain

    def get_data(self):
        rss_data_links = []
        rss_data = []
        try:
            html_data_of_url = requests.get(self.url,timeout=10,verify=True)
            if html_data_of_url.status_code != 200:
                headers = {"origin":self.url,"Referer":self.url,"user-agent":"Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/59.0.3071.115 Safari/537.36", "x-requested-with":"XMLHttpRequest", 'Accept-Encoding': 'gzip, deflate, br'}
                html_data_of_url = requests.get(self.url,headers = headers,timeout=10,verify=True)
            if html_data_of_url.status_code == 200:
                soup = BeautifulSoup(html_data_of_url.text, 'html.parser')
                rss_data+=soup.find_all(type="application/rss+xml")#checking for rss urls with different types
                rss_data+=soup.find_all(type="application/atom+xml")
                rss_data+=soup.find_all(type="application/rss")
                rss_data+=soup.find_all(type="application/atom")
                rss_data+=soup.find_all(type="application/rdf+xml")
                rss_data+=soup.find_all(type="application/rdf")
                rss_data+=soup.find_all(type="text/rss+xml")
                rss_data+=soup.find_all(type="text/atom+xml")
                rss_data+=soup.find_all(type="text/rss")
                rss_data+=soup.find_all(type="text/atom")
                rss_data+=soup.find_all(type="text/rdf+xml")
                rss_data+=soup.find_all(type="text/rdf")
                rss_data+=soup.find_all(rel="alternate",type="text/xml")
                rss_data+=soup.find_all(rel="alternate",type="application/xml")
                #print(rss_data)
                if rss_data:
                    for each_data in rss_data:
                        domain = tldextract.extract(each_data["href"])
                        if domain.domain:
                            parsed_url = urlparse(each_data["href"])
                            if parsed_url[0]=='' and each_data["href"][0]=="/" and each_data["href"][1]=="/":
                                rss_data_links.append(self.scheme+":"+each_data["href"])
                            elif parsed_url[0]=='' and each_data["href"][0]=="/":
                                rss_data_links.append(self.scheme+":/"+each_data["href"][1:])
                            elif parsed_url[0]=='':
                                rss_data_links.append(self.scheme+"://"+each_data["href"])
                            else:
                                rss_data_links.append(each_data["href"])
                        else:
                            if self.web_url[-1] == "/":
                                rss_data_links.append(self.web_url+each_data["href"][1:])
                            else:
                                rss_data_links.append(self.web_url+each_data["href"])
                else:
                    rss_data_links+=self.check_rss_or_feed_in_page()#check rss or feed (text) in url
        except Exception as e :
            print("Exception from get_data method in ShowUrlCategory : ")
            trace_back = traceback.format_exc()
            Utils.exception_message(str(e),sys.exc_info(),trace_back)
        return rss_data_links


    def check_rss_or_feed_in_page(self):#this method is used to check for /rss or /feed href links in the current page
        rss_urls = []
        try:
            headers = {"origin":self.url,"Referer":self.url,"user-agent":"Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/59.0.3071.115 Safari/537.36", "x-requested-with":"XMLHttpRequest", 'Accept-Encoding': 'gzip, deflate, br'}
            result = requests.get(self.url,headers = headers,timeout=10,verify=True)
            if result.status_code == 200:
                soup = BeautifulSoup(result.text, 'html.parser')
                rss_data = soup.find_all(href=True)
                for each_url in rss_data:
                    if not "feedback" in each_url["href"] and(".rss" in each_url["href"] or ".feed" in each_url["href"] or ".xml" in each_url["href"] or "/rss" in each_url["href"] or "/feed" in each_url["href"] or "/xml" in each_url["href"] or "+rss" in each_url["href"] or "+feed" in each_url["href"] or "+xml" in each_url["href"]):
                        domain = tldextract.extract(each_url["href"])
                        if domain.domain and (self.domain_name == domain.domain):#if the url has domain name and checking for scheme
                            parsed_url = urlparse(each_url["href"])
                            if parsed_url[0]=='' and each_url["href"][0]=="/" and each_url["href"][1]=="/":
                                rss_urls.append(self.scheme+":"+each_url["href"])
                            elif parsed_url[0]=='' and each_url["href"][0]=="/":
                                rss_urls.append(self.scheme+":/"+each_url["href"][1:])
                            elif parsed_url[0]=='':
                                rss_urls.append(self.scheme+"://"+each_url["href"])
                            else:
                                rss_urls.append(each_url["href"])
                        elif domain.domain=='':#if url doesn't has domain name we are adding name
                            if self.web_url[-1] == "/":
                                rss_urls.append(self.web_url+each_url["href"][1:])
                            else:
                                rss_urls.append(self.web_url+each_url["href"])
        except Exception as e:
            print("Exception from check_rss_or_feed_in_page method in ShowUrlCategory : ")
            trace_back = traceback.format_exc()
            Utils.exception_message(str(e),sys.exc_info(),trace_back)
        return rss_urls

    def get_results(self):
        if self.url == '':
            return {"status":False, "error_msg":"url is missing in input parameters"}
        else:#getting only the domain name from url example: self.url = https://www.facebook.com/feltso self.web_url = https://www.facebook.com/
            pattern = re.compile(r'(?:https://|http://)[\w\._-]*/')
            self.web_url = pattern.findall(self.url)[0]
            parsed_url = urlparse(self.url)
            self.scheme = parsed_url.scheme #http or https
        while(True):
            final_data = []
            final_data = self.get_data()
            if final_data:
                self.are_valid_rss_links(final_data)
                break
            else:#cropping the url one step back
                if self.url[-1] == "/":
                    self.url = self.url[:-1]
                if self.url.count("/") == 2:
                    break
                    #return self.rss_final_links
                one_step_back = self.url.rfind("/")
                self.url = self.url[:one_step_back+1]
        if not self.rss_final_links:
            final_data = [self.web_url+"feed/"]
            self.are_valid_rss_links(final_data)
            self.url = self.web_url
            self.forward_scraping_for_urls()
        output = {"status":True, "links":self.rss_final_links}
        #print("RES:",output)
        return output

    def forward_scraping_for_urls(self):
        headers = {"origin":self.url,"Referer":self.url,"user-agent":"Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/59.0.3071.115 Safari/537.36", "x-requested-with":"XMLHttpRequest", 'Accept-Encoding': 'gzip, deflate, br'}
        html_data = requests.get(self.url,headers=headers,timeout=10,verify=True)
        if html_data.status_code == 200:
            soup = BeautifulSoup(html_data.text,"html.parser")
            all_urls_in_main_page = soup.find_all(href=True)
            rss_urls = []
            for each_data in all_urls_in_main_page:
                domain = tldextract.extract(each_data["href"])
                if domain.domain:
                    parsed_url = urlparse(each_data["href"])
                    if parsed_url[0]=='' and each_data["href"][0]=="/" and each_data["href"][1]=="/":
                        self.url = self.scheme+":"+each_data["href"]
                    elif parsed_url[0]=='' and each_data["href"][0]=="/":
                        self.url = self.scheme+":/"+each_data["href"][1:]
                    elif parsed_url[0]=='':
                        self.url = self.scheme+"://"+each_data["href"]
                    else:
                        self.url = each_data["href"]
                else:
                    if self.web_url[-1] == "/":
                        self.url = self.web_url+each_data["href"][1:]
                    else:
                        self.url = self.web_url+each_data["href"]
                if self.url not in self.checked_list and ("mail" not in self.url) and (self.domain_name in self.url):
                    result = self.get_data()
                    if result:
                        rss_urls.extend(result)
                    self.checked_list.append(self.url)
            if rss_urls:
                self.are_valid_rss_links(rss_urls)



    def are_valid_rss_links(self,result_data):#method to check whether the url has rss feed or not
        for single_link in result_data:
            if single_link not in self.checked_list and "comments" not in single_link:
                self.checked_list.append(single_link)
                rss_data_of_url = feedparser.parse(single_link)
                if "entries" in rss_data_of_url and len(rss_data_of_url["entries"]) >= 0:
                    self.transform(rss_data_of_url, single_link)
                else:
                    print("No rss data found in this link",single_link)
                    self.url = single_link
                    result = self.get_data()#to find rss urls in this current url(/rss or /feed)
                    result = list(set(result))
                    i=0
                    for single_link in result:
                        print(i)
                        if single_link not in self.checked_list:
                            self.checked_list.append(single_link)
                            headers = {"origin":self.web_url,"Referer":self.web_url,"user-agent":"Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/59.0.3071.115 Safari/537.36", "x-requested-with":"XMLHttpRequest", 'Accept-Encoding': 'gzip, deflate, br'}
                            rss_data_of_url = feedparser.parse(single_link)
                            if rss_data_of_url["entries"]:
                                self.transform(rss_data_of_url, single_link)
                            else:
                                i+=1
                                continue
                        i+=1

    def transform(self,xml_to_json_data,rss_url):
        output = {}
        if "description" in xml_to_json_data.feed and not bool(BeautifulSoup(xml_to_json_data.feed.description, "html.parser").find()):
            output["post_description"] = xml_to_json_data.feed.description
        else:
            output["post_description"] = ''
        if "title" in xml_to_json_data.feed:
            output["post_title"] = xml_to_json_data.feed.title
        else:
            output["post_title"] = ''
        output["rss_url"] = rss_url
        if "link" in xml_to_json_data.feed:
            output["sourse_url"] = xml_to_json_data.feed.link
        else:
            output["source_url"] = ''
        output["hash_code"] = Utils.get_hash_code(rss_url)
        if "image" in xml_to_json_data.feed:
            if "href" in xml_to_json_data.feed.image:
                output["post_image_url"] = xml_to_json_data.feed.image.href
            else:
                output["post_image_url"] = ""
        else:
            output["post_image_url"] = ""

        if output and "comments" not in output["post_title"].lower():
            self.rss_final_links.append(output)

    def store_results(self,output):
        filename = "ShowUrlCategory" + ("_".join(str(datetime.datetime.now()).split(" "))).replace(":","-") + ".json"
        with open(filename,"w") as f:
            json.dump(output,f,indent=2)
        f.close()

if __name__ == "__main__":
    '''
    url should end with /
    '''
    parameters = {"url":"http://www.elleuk.com/"} 
    obj = ShowUrlCategory(parameters)
    results = obj.get_results()
    print(results)
    #obj.store_results(results)
