import sqlite3 as sql
i = 0

def db(cmd):
	with sql.connect("database.db") as con:
		try:
			cur = con.cursor()
			cur.execute(cmd)
			con.commit()
			#print('Record successfully added')

		except:
			# i
			con.rollback()
			#print('Error in insert operation')

		finally:
			rows = cur.fetchall()
			return rows
