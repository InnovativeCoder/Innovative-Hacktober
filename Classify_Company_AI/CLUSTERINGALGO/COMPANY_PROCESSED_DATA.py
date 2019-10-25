
# coding: utf-8

# # COMPANY CLASSIFICATION - **using clustering Algo** #
# ## ---------START OF DATA PROCESSING------- #

# In[1]:

import pandas as pd


# In[2]:

df = pd.read_csv('testdata.csv')


# In[3]:

df.head()


# In[4]:

df.describe()


# In[5]:

td = df.columns.str.contains('^Unnamed')


# In[6]:

df = df.loc[:,~td]


# In[7]:

df.head()


# In[8]:

df.describe()


# In[9]:

df = df.dropna(subset=['housing_flg'])


# In[10]:

df.isnull().head()


# In[11]:

col1 = df.iloc[:,0]


# In[12]:

col1 = pd.DataFrame(col1)


# In[13]:

col1.head()


# In[14]:

df = df.rename( columns = {df.columns[1]:"Link"})


# In[15]:

from googlesearch import search


# In[18]:

#performs a final search for the nan values and replaces in the columns.
#only 36 nan remaining.
count = 0
for val,row in df.iterrows():
        if(str(row[df.columns[1]])==('nan')):
            query = str(row[df.columns[0]])
            print(query)
            for j in search(query,tld = 'com',num = 10, stop =1,pause = 2):
                row[df.columns[1]]= j
                print(j)
                count = count+1
                print(row[df.columns[1]])


# In[19]:

col3 = pd.DataFrame()


# In[20]:

lst = list()
for val,row in df.iterrows():
    if(str(row[df.columns[1]])=='nan'):
        lst.append(row[df.columns[0]])


# In[21]:

col3 = pd.DataFrame(lst)

col3.rename(columns={0:'No LINK Company'}).head()
#col3 holds all nan linked companies


# In[22]:

df = df.dropna(subset=[df.columns[1]])
df.describe()
#dropped all nan links with rows


# ## Data is removed of missing links
# ### *col3* holds the rows with missing links.
# ### df holds the rows with valid links.

# # USING WORDNINJA ON COL3 :3

# In[23]:

import wordninja


# In[24]:

col3.head()


# In[25]:

lst = list()
for val,row in col3.iterrows():
    lst.append(row[col3.columns[0]])


# In[26]:

lst2 = list();
for i in lst:
    lst2.append(wordninja.split(i))


# In[27]:

lst3 = list()
for i in lst2:
    str = ''
    for j in i:
        str+=j+' '
    lst3.append(str)


# In[28]:

altmiss = pd.DataFrame(lst3)


# In[29]:

altmiss['link']=' '


# In[30]:

for val,row in altmiss.iterrows():
    query = row[altmiss.columns[0]]
    print(query)
    for j in search(query,tld = 'com',num = 10, stop =1,pause = 2):
        row[altmiss.columns[1]]= j
        print(j)
        count = count+1
        print(row[altmiss.columns[1]])


# In[31]:

altmiss = altmiss.rename(columns = {altmiss.columns[0]:'Company',altmiss.columns[1]:'Link'})

altmiss.describe()


# In[32]:

df = df.rename(columns = {df.columns[0]:'Company',df.columns[1]:'Link'})
df.describe()


# In[33]:

mp = df.append(altmiss)
#MP HOLDS FINAL VALUES ALONG WITH ALTERED MISSING VALUES

mp.describe()


# ## FOUND MISSING VALUES - LINK with 100% rate -
# ### STORED IN MP

# In[42]:

duplicateColsDF = mp[mp.duplicated(subset = [mp.columns[1]])] #GETTING ALL DUPLICATES WITH RESPECT TO ONLY COLUMNS
duplicateColsDF.describe()
#value = 591
duplicateRowsDF = mp[mp.duplicated(subset = [mp.columns[0]])] #GETTING ALL DUPLICATES WITH RESPECT TO ONLY ROWS
#value = 27
duplicateDF = mp[mp.duplicated()] #GETTING ALL DUPLICATES WITH RESPECT TO COLUMN AND ROWS
#value = 20


# In[43]:

mp2 = mp.drop_duplicates()
mp2.describe()


# # REMOVED DUPLICATE VALUES AND STORED IN MP2

# # ----------END OF PROCESSING OF DATA ----------#

# In[ ]:



