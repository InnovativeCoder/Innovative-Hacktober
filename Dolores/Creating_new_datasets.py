#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


# In[2]:


dataset = pd.read_csv('train.csv')
dataset_test = pd.read_csv('test.csv')


# In[3]:


average = dataset['theta'] = (dataset.theta1 + dataset.theta2 + dataset.theta3 + dataset.theta4 + dataset.theta5 + dataset.theta6)/6
average = dataset['thetad'] = (dataset.thetad1 + dataset.thetad2 + dataset.thetad3 + dataset.thetad4 + dataset.thetad5 + dataset.thetad6)/6
average = dataset['tau'] = (dataset.tau1 + dataset.tau2 + dataset.tau3 + dataset.tau4 + dataset.tau5)/6 
average = dataset['dm'] = (dataset.dm1 + dataset.dm2 + dataset.dm3 + dataset.dm4 + dataset.dm5)/6 
average = dataset['da'] = (dataset.da1 + dataset.da2 + dataset.da3 + dataset.da4 + dataset.da5)/6
average = dataset['db'] = (dataset.db1 + dataset.db2 + dataset.db3 + dataset.db4 + dataset.db5)/6 


# In[4]:


average = dataset_test['theta'] = ((dataset_test.theta1)+(dataset_test.theta2)+(dataset_test.theta3)+(dataset_test.theta4)+(dataset_test.theta5)+(dataset_test.theta6))/6
average = dataset_test['thetad'] = ((dataset_test.thetad1)+(dataset_test.thetad2)+(dataset_test.thetad3)+(dataset_test.thetad4)+(dataset_test.thetad5)+(dataset_test.thetad6))/6
average = dataset_test['tau'] = ((dataset_test.tau1)+(dataset_test.tau2)+(dataset_test.tau3)+(dataset_test.tau4)+(dataset_test.tau5))/6
average = dataset_test['dm'] = ((dataset_test.dm1)+(dataset_test.dm2)+(dataset_test.dm3)+(dataset_test.dm4)+(dataset_test.dm5))/6
average = dataset_test['da'] = ((dataset_test.da1)+(dataset_test.da2)+(dataset_test.da3)+(dataset_test.da4)+(dataset_test.da5))/6
average = dataset_test['db'] = ((dataset_test.db1)+(dataset_test.db2)+(dataset_test.db3)+(dataset_test.db4)+(dataset_test.db5))/6


# In[5]:


dataset_test.head()


# In[6]:


train_X = (dataset.iloc[:, 35:42].values)
test_X = (dataset_test.iloc[:, 35:41].values)
y = dataset.iloc[:, 35].values


# In[7]:


np.savetxt("train_AM.csv", train_X, delimiter=",")


# In[8]:


np.savetxt("test_AM.csv", test_X, delimiter=",")


# In[ ]:




