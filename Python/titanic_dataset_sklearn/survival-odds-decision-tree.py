import numpy as np
import pandas as pd
from sklearn import tree

def giveClass(i): #A function for assisting in output display
	if(i==1):
		return "First Class"
	if(i==2):
		return "Second Class"
	if(i==3):
		return "Third Class"


def giveAgeGroup(i): #A function for assisting in output display
	if(i==0):
		return "0-9"
	if(i==1):
		return "10-29"
	if(i==2):
		return "30-49"
	if(i==3):
		return "50-80"


data = pd.read_csv('titanic.csv',usecols = ['Pclass','Sex','Age']) #Accessing data from the target .csv file 
data = data.fillna(data['Age'].mean()) #We don't want "NaN" ages throwing off the classifier, hence the mean replacement
data = data.replace(r'^male$', 0, regex = True) #Tokenization of the gender field
data = data.replace(r'^female$', 1, regex = True) 
ageArray = data['Age']
tokenizedAge = [0 for i in range(len(ageArray))]

j=0
for i in ageArray: #Tokenization of the age field
	if(i<10):
		tokenizedAge[j] = 0
	elif(i<30):
		tokenizedAge[j] = 1
	elif(i<50):
		tokenizedAge[j] = 2
	elif(i<=80):
		tokenizedAge[j] = 3
	j+=1
data['Age']=tokenizedAge

X=data
y=pd.read_csv('titanic.csv',usecols = ['Survived'])
clf = tree.DecisionTreeRegressor()
clf = clf.fit(X,y) #Actual fitting

print('''\n\n\nThe table below illustrates the statistical analysis of how probable an individual's 
survival would be under certain conditions. Note that the probabilities observed
are the result of running a decision tree algorithm on the dataset, and that the 
decision tree can also be used to predict whether an individual survived the 
sinking of the Titanic.\n\n\n''')
print("||Class\t\t\t|Gender\t\t|Age Group\t|Survival Probability\t||")
for i in range(1,4): #Gaining an insight as to how various factors came into play in terms of survival odds

	for j in range(0,2):

		for k in range(0,4):

			psgClass = giveClass(i)
			gender = "Male" if j==0 else "Female"
			ageGroup = giveAgeGroup(k)
			probabilityOfSurvival = round(clf.predict([[i,j,k]])[0]*100,3)
			print("||",psgClass," \t|",gender," \t|",ageGroup,"  \t|",probabilityOfSurvival,"  \t\t||")



#Observed output:

'''
λ python firstTryWithPandas.py



The table below illustrates the statistical analysis of how probable an individual's
survival would be under certain conditions. Note that the probabilities observed
are the result of running a decision tree algorithm on the dataset, and that the
decision tree can also be used to predict whether an individual survived the
sinking of the Titanic.



||Class                 |Gender         |Age Group      |Survival Probability   ||
|| First Class          | Male          | 0-9           | 100.0                 ||
|| First Class          | Male          | 10-29         | 36.364                ||
|| First Class          | Male          | 30-49         | 44.681                ||
|| First Class          | Male          | 50-80         | 20.69                 ||
|| First Class          | Female        | 0-9           | 0.0                   ||
|| First Class          | Female        | 10-29         | 97.368                ||
|| First Class          | Female        | 30-49         | 100.0                 ||
|| First Class          | Female        | 50-80         | 93.333                ||
|| Second Class         | Male          | 0-9           | 100.0                 ||
|| Second Class         | Male          | 10-29         | 6.383                 ||
|| Second Class         | Male          | 30-49         | 10.256                ||
|| Second Class         | Male          | 50-80         | 7.692                 ||
|| Second Class         | Female        | 0-9           | 100.0                 ||
|| Second Class         | Female        | 10-29         | 91.429                ||
|| Second Class         | Female        | 30-49         | 92.593                ||
|| Second Class         | Female        | 50-80         | 83.333                ||
|| Third Class          | Male          | 0-9           | 38.095                ||
|| Third Class          | Male          | 10-29         | 12.185                ||
|| Third Class          | Male          | 30-49         | 12.821                ||
|| Third Class          | Male          | 50-80         | 0.0                   ||
|| Third Class          | Female        | 0-9           | 52.381                ||
|| Third Class          | Female        | 10-29         | 54.639                ||
|| Third Class          | Female        | 30-49         | 28.0                  ||
|| Third Class          | Female        | 50-80         | 100.0                 ||
'''