import sqlite3

forth = sqlite3.connect('databaserupin.db')

sql = "SELECT * from rupin;"

curforth = forth.cursor()
curforth.execute(sql)

result = curforth.fetchall()
for record in result:
    print(record)