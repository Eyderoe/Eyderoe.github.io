
import operator
import sqlite3
import os.path

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
db_path = os.path.join(BASE_DIR, "movie.db")
conn = sqlite3.connect(db_path)
cursor = conn.cursor()
sql = """select * from movie250"""
cursor.execute(sql)
result = cursor.fetchall()
print(result)
#print(result)
#for i in range(0,250):
#    print(result[i])
#    print('\n')
def typelist(type):
    list=[]
    for i in range(0,250):
        list.append(result[i][type])
    return list
#conn.close()