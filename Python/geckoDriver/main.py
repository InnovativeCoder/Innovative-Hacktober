from selenium import webdriver
import csv
import time
questions_list = []
answers_list = []
hint_list = []
with open('data.csv') as file:
	temp_file = csv.DictReader(file)
	for line in temp_file:
		questions_list.append(line['Question'])
		answers_list.append(line['Answer'])
		hint_list.append(line['Hint'])

translated_questions = []
translated_answers = []
translated_hints = []

browser = webdriver.Firefox()
browser.get('http://translate.google.com/')
browser.find_element_by_class_name("tl-more").click()
browser.find_element_by_class_name("tl_list_hi_checkmark").click()
source_input = browser.find_element_by_class_name("tlid-source-text-input")
source_input.click()
for i in range(len(questions_list)):
	source_input.send_keys(questions_list[i])
	time.sleep(4)
	x = browser.find_element_by_xpath("""//span[@lang="hi"]""")
	translated_questions.append(x.text)
	browser.find_element_by_id("source").clear()

	source_input.send_keys(answers_list[i])
	time.sleep(4)
	x = browser.find_element_by_xpath("""//span[@lang="hi"]""")
	translated_answers.append(x.text)
	browser.find_element_by_id("source").clear()

	if len(hint_list[i])!=0:  
		source_input.send_keys(hint_list[i])
		time.sleep(4)
		x = browser.find_element_by_xpath("""//span[@lang="hi"]""")
		translated_hints.append(x.text)
		browser.find_element_by_id("source").clear()
	else:
		translated_hints.append(" ")

with open('transn.csv', 'w') as file:
	fieldnames = ['questions', 'answer', 'hints']
	writer = csv.DictWriter(file, fieldnames=fieldnames)
	writer.writeheader()
	for i in range(len(questions_list)):
		row = {"questions": translated_questions[i], "answer": translated_answers[i], "hints": translated_hints[i]}
		writer.writerow(row)
