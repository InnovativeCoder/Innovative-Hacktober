#!/usr/bin/env python
# coding: utf-8

# In[1]:


#Importing Libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns


# In[2]:


#Importing datasets
dataset = pd.read_csv('train_AM.csv')
dataset_test = pd.read_csv('test_AM.csv')
dataset_train_real = pd.read_csv('train.csv')
dataset_test_real = pd.read_csv('test.csv')


# In[3]:


dataset.head() #Analysing the dataset


# In[4]:


#Finding Correlation Matrix 
dataset.corr()


# In[5]:


#Creating Variables 
train_X = dataset.iloc[:, 1:7].values
test_X = dataset_test.iloc[:, 0:6].values
y = dataset.iloc[:, 0].values


# In[6]:


from sklearn.ensemble import RandomForestRegressor #Importing RandomForestRegressor Class
regressor = RandomForestRegressor(n_estimators=100, random_state = 0) # Creating object and defining paramaters for regression 


# In[7]:


regressor.fit(train_X, y) # Fitting given data to the Regressor


# In[8]:


y_pred = regressor.predict(test_X) # Predicting values using trained model 


# In[9]:


#Creating a matrix to submit the results
c1 = dataset_test_real['index'].values
c2 = dataset_test_real['id'].values
c3 = y_pred
submit = []
for i in range(0,1000):
    submit.append([c1[i], c2[i], c3[i]])


# In[10]:


submit


# In[11]:


#Saving the matrix submit to a csv file
np.savetxt("Submission.csv", submit, delimiter=",")


# In[12]:


# Plotting heatmap of the new dataset
plt.figure(figsize=(70,40)) 
sns.heatmap(dataset.corr(),annot=True,cmap='cubehelix_r') #draws  heatmap with input as the correlation matrix calculted by(iris.corr())
plt.show()


# In[13]:


# Plotting heatmap of the original dataset
plt.figure(figsize=(70,40)) 
sns.heatmap(dataset_train_real.corr(),annot=True,cmap='cubehelix_r') #draws  heatmap with input as the correlation matrix calculted by(iris.corr())
plt.show()


# In[14]:


#rmse-0.26 (Random Forest n_estimators=10 )
#rmse-0.26 (Random Forest n_estimators=50 )
#rmse-0.25 (Random Forest n_estimators=100 )
#rmse-0.25 (Random Forest n_estimators=500 )


# In[ ]:




