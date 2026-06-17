# import myql connector
import mysql.connector

# create connection with mysql server
connection = mysql.connector.connect(
    host = "127.0.0.1",
    port = 3306,
    user = "root",
    password = "root",
    database = "iotdb",
    use_pure = True
)

# craeate a query to be executed
query = "select * from persons;"

# create a cursor to execute a query
cursor = connection.cursor()

# with the help of cursor execute the query
cursor.execute(query)

# fetch data from cursor and use that data
data = cursor.fetchall()        # returns list of tuples
#print(data)

for person in data:
    print(person)

# close the cursor
cursor.close()

# close connection with mysql server
connection.close()