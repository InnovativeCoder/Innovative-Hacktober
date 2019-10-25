import pandas as pd
from googlesearch import search
import wordninja
import requests
from bs4 import BeautifulSoup
from sklearn.cross_validation import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.metrics import accuracy_score
from sklearn.neighbors import KNeighborsClassifier
import Comp_classify_def as alldef


def process_data(filename):
    """
    Processing DataSet
    """
    #Getting Data from testdata_Labeled.csv file.
    data = pd.read_csv(filename)
    #Retrieving only data which are labeled for now
    data_df = data
    #Dropping columns with missing value
    data_df.dropna(how='all',axis=1,inplace=True)
    data_df.dropna(how='all',axis=0,inplace=True)
    data_df.drop(axis=1,labels=[data_df.columns[3],data_df.columns[4]],inplace=True)
    data_df = data_df.head(73)
    X = data_df.housing_flg
    y = data_df.Category
    return X,y
    # """
    # Splitting data into train and test sets among the category before applying
    # vectorization
    # """
    # #X_train,X_test,Y_train,Y_test = train_test_split(X,y,random_state = 1)
    #
def trans_data_to_vect(X):
    """
    get_df_with_desc transforms the series into a dataframe having
    columns filled with respective values
    """
    X_df = alldef.get_df_with_lmtd_desc(X)

    """
    Vectorizing data with TfidfVectorizer
    """
    #configuring TFidf Vectorizer with predefined features.
    vectorizer = TfidfVectorizer(use_idf = 'False',binary=True,ngram_range=(1,2))
    vectorizer.fit(['Finance', 'Loan', 'Insurance',
    'Investor' ,'Business Services','Financial Services', 'Personal Loan', 'Mobile Loan',
    'Consumer Durable Loan', 'Furniture Loan',
    '2-wheeler Loan', 'E - Bike Loan', 'Bank', 'Home Loan', 'Housing Finance'])
    vectorizer.get_feature_names()
    X_res = alldef.transform_to_vector(vectorizer,X_df)
    #X_res is a dataframe that stores the vectorized data
    return X_res
def train_test(data_df,y,num,comp_name):
    """
    Splitting data into train and test sets among the category before applying
    vectorization
    """
    X_df = data_df.head(num)

    X_train,X_test,Y_train,Y_test = train_test_split(X_df,y,random_state = 1)

    #Trying MultinomialNB and KNN classifier algos:

    categories = ['Finance','Assmt','Investor','Loan','Bank','Home Loan','other']
    print('Classification by MultinomialNB: ')
    alp = 0
    max_scr = 0
    for k in range(5):
        model = MultinomialNB(alpha = k)
        model.fit(X_train,Y_train)
        labels = model.predict(X_test)
        scr = accuracy_score(labels,Y_test)
        if scr >max_scr:
            max_scr = scr
            alpha = k
        print('score for alpha ', k,' is ' , scr)
    n = 1
    max_scr = 0
    print('Classification by K nearest Neighbor: ')
    for k in range(25):
        modelknn = KNeighborsClassifier(n_neighbors=(k+1))
        modelknn.fit(X_train.drop(X_train,Y_train))
        labelknn = modelknn.predict(X_test)
        scr = accuracy_score(Y_test,labelknn)
        print('Accuracy for ',k+1,' neighbors = ',scr)
        if scr>max_scr:
            max_scr = scr
            n = k
    comp_name_x = pd.DataFrame([comp_name],columns = {'housing_flg'})
    comp_df = trans_data_to_vect(comp_name_x)
    model = MultinomialNB(alpha =alp)
    model.fit(X_train,Y_train)
    labels = model.predict(comp_df)
    print('Multinomial NB  label: ',labels)
    modelknn = KNeighborsClassifier(n_neighbors=n+1)
    modelknn.fit(X_train,Y_train)
    labels = modelknn.predict(comp_df)
    print('KNN  label: ',labels)
if __name__ == '__main__':
    filename = input('Enter file with labeled data or press 2 to skip train: ')
    if filename!='2':
        X,y = process_data(filename)
        data_processed_df = trans_data_to_vect(X)
        num = input('Enter the number of data already labeled: ')
        comp_name = input('Enter company name to classify: ')
        train_test(data_processed_df,y,74,comp_name)
    else:
        filename = 'testdata_Labeled.csv'
        X,y = process_data(filename)
        data_processed_df = trans_data_to_vect(X)
        comp_name = input('Enter company name to classify: ')
        train_test(data_processed_df,y,74,comp_name)
