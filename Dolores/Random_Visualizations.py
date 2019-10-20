#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


# In[2]:


dataset = pd.read_csv('train.csv')
dataset_test = pd.read_csv('test.csv')


# In[15]:


dataset['theta'] = dataset['theta1'] * dataset['theta2']


# In[6]:


dataset.head()


# In[7]:


sum = dataset['theta'] = dataset.theta1 + dataset.theta2 + dataset.theta3 + dataset.theta4 + dataset.theta5 + dataset.theta6
sum = dataset['thetad'] = dataset.thetad1 + dataset.thetad2 + dataset.thetad3 + dataset.thetad4 + dataset.thetad5 + dataset.thetad6
sum = dataset['tau'] = dataset.tau1 + dataset.tau2 + dataset.tau3 + dataset.tau4 + dataset.tau5 
sum = dataset['dm'] = dataset.dm1 + dataset.dm2 + dataset.dm3 + dataset.dm4 + dataset.dm5 
sum = dataset['da'] = dataset.da1 + dataset.da2 + dataset.da3 + dataset.da4 + dataset.da5
sum = dataset['db'] = dataset.db1 + dataset.db2 + dataset.db3 + dataset.db4 + dataset.db5 


# In[10]:


product = dataset['theta'] = (dataset.theta1)*(dataset.theta)*(dataset.theta3)*(dataset.theta4)*(dataset.theta5)*(dataset.theta6)
product = dataset['thetad'] = (dataset.thetad1)*(dataset.thetad2)*(dataset.thetad3)*(dataset.thetad4)*(dataset.thetad5)*(dataset.thetad6)
product = dataset['tau'] = (dataset.tau1)*(dataset.tau2)*(dataset.tau3)*(dataset.tau4)*(dataset.tau5) 
product = dataset['dm'] = (dataset.dm1)*(dataset.dm2)*(dataset.dm3)*(dataset.dm4)*(dataset.dm5) 
product = dataset['da'] = (dataset.da1)*(dataset.da2)*(dataset.da3)*(dataset.da4)*(dataset.da5)
product = dataset['db'] = (dataset.db1)*(dataset.db2)*(dataset.db3)*(dataset.db4)*(dataset.db5) 


# In[11]:


dataset.head()


# In[12]:


train_X = dataset.iloc[:, 36:42].values
test_X = dataset_test.iloc[:, 35:41].values
y = dataset.iloc[:, 35].values


# In[13]:


len(train_X)


# In[17]:


plt.scatter(train_X[:,0], y, s=0.1) # theta(Sum of theta) on x-axis | target on y-axis


# In[17]:


plt.scatter(dataset['theta6'].values, dataset['target'].values, s=0.1)


# In[12]:


plt.scatter(dataset['theta1'].values, dataset['target'].values, s=0.1)


# In[18]:


#Now thetad


# In[19]:


plt.scatter(train_X[:,1], y, s=0.1) # theta(Sum of theta) on x-axis | target on y-axis


# In[21]:


plt.scatter(dataset['thetad2'].values, dataset['target'].values, s=0.1)


# In[26]:


plt.scatter(train_X[:,0], train_X[:,1], s=0.1)


# In[27]:


plt.scatter(train_X[:,0], train_X[:,5], s=0.1)


# In[28]:


plt.scatter(dataset['theta1'].values, dataset['theta2'].values, s=0.1)


# In[4]:


import seaborn as sns


# In[18]:


a = dataset.corr()


# In[19]:


a['target']


# In[ ]:





# In[ ]:




