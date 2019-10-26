"""
This python file stores all definitions used in Comp_Classify_final.py
"""
import pandas as pd
from bs4 import BeautifulSoup
from googlesearch import search
import requests
import wordninja
from sklearn.feature_extraction.text import TfidfVectorizer
def transform_data (inputseries):
    X_df = pd.DataFrame(inputseries)
    X_df['Company'] = 'Nan'
    for i in range(5):
        stri = 'Link'+str(i)
        X_df[stri] = 'Nan'
        stri = 'Data'+str(i)
        X_df[stri] = 'Nan'
    return X_df
#returns X_df (Dataframe having added columns.)
def cleanme(html):
    soup = BeautifulSoup(html) # create a new bs4 object from the html data loaded
    for script in soup(["script"]):
        script.extract()
    text = soup.get_text()
    text = text.replace('\n', ' ').replace('\r', '').replace('\t',' ')
    return text.strip()
#cleans the response from website.
def get_df_with_lmtd_desc(X):
    X_df = link_obtain(X)
    X_df = lmtd_data_desc(X_df)
    return X_df
#combines transform_data, link_obtain and lmtd_data_desc functions
def get_df_with_desc(X):
    X_df = link_obtain(X)
    X_df = data_desc(X_df)
    return X_df
#combines transform_data, link_obtain and data_desc functions
def link_obtain(X_train):
    count =0
    X_df = transform_data(X_train)
    for i,j in X_df.iterrows():
        URL = X_df['housing_flg'][i]
        query = URL
        #print(query)
        #Directly Retrieving all ifsc code data without saving link in column.
        if(len(str(query.strip())))<5:
            t =0
            str_list = list('https://www.ifsccodebank.com/search-by-IFSC-code.aspx?IFSCCode=')
            str_list.append(query)
            url = ''.join(str_list)
            response = requests.get(''.join(str_list))
            soup = BeautifulSoup(response.text,'html.parser')
            t = soup.get_text()
            r = t[t.find(query)+7:]
            r = (r[:r.find('-')-5].strip())
            X_df['Company'][i] = r
            q2 = str(X_df['Company'][i])
            if 'com' not in q2:
                t =0
                for l in search(q2,stop = 2):
                    stri = 'Link'+str(t)
                    #print(q2,l)
                    X_df[stri][i] = l
                    count = count+1
                    t = int(t)+1
                    #print(stri)
            else:
                X_df['Company'][i] = 'Nan'
            continue
        #if Name has no space ---> Using wordninja algo to split the words.
        elif ' ' not in query.strip():
            query = " ".join(str(x) for x in wordninja.split(query))
    ####===> The following gets the link and not the data <===####
        # Direct search for appropriate official Link
        try:
            t = 0
            for k in search(query,stop = 2):
                stri = 'Link' + str(t)
                X_df[stri][i] = k
                t = t+1
                #print(stri)
        # Search the words with key word Financial Services
            t = 2
            query = URL + ' Finanancial Services'
            for k in search(query,stop = 2):
                stri = 'Link' + str(t)
                X_df[stri][i] = k
                t = t+1
                #print(stri)
            count = count+1
        except:
            # except block to store the company which has bad request/other issue
            X_df['Link4'][i] = query
            print('Errored out: ',query)
        print('Completed : ')
        td = count
        print(td//15,end = '\r')
    return X_df
#takes series and returns dataframe with link obtained from the respective companies.
def lmtd_data_desc(X_df):
    for i,j in X_df.iterrows():
        if 'Nan' not in X_df['Link0'][i]:
            response = requests.get(X_df['Link0'][i],verify = False)
            t = cleanme(response.text)
            X_df['Data0'][i] = t
    return X_df
#returns dataframe with data description obtained from first link
def data_desc(X_df):
    for i,j in X_df.iterrows():
        try:
            if 'Nan' not in X_df['Link3'][i]:
                response = requests.get(X_df['Link3'][i],verify = False)
                t = cleanme(response.text)
                X_df['Data3'][i] = t
            if 'Nan' not in X_df['Link0'][i]:
                response = requests.get(X_df['Link0'][i],verify = False)
                t = cleanme(response.text)
                X_df['Data0'][i] = t
        except:
            print('Error: ',i)
    return X_df
#returns dataframe with data description obtained from first and third link.
def transform_to_vector(vectorizer,X_df):
    X_res = pd.DataFrame(columns = vectorizer.get_feature_names())
    for i,j in X_df.iterrows():
        print(X_df['housing_flg'][i])
        rtlst = [0]*len(vectorizer.get_feature_names())
        rt = vectorizer.transform([X_df['Data0'][i]]).toarray()
        for k in range(rt.shape[1]):
            rtlst[k] = rt[0][k]+rtlst[k]
            print ('Initial ',i, rtlst[k])
        rt = vectorizer.transform([X_df['Data3'][i]]).toarray()
        for k in range(rt.shape[1]):
            rtlst[k] = rt[0][k]+rtlst[k]
            print('Final ',i,rtlst[k])
        X_res.loc[i] = rtlst
    return X_res
#vectorizes the dataframe text into numbers => returns dataframe with vectorized
#text according to the features.
