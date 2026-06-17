# import mysql connector
import mysql.connector

# get connection with mysql server
connection = mysql.connector.connect(
    host = "127.0.0.1",
    port = 3306,
    user = "root",
    password = "root",
    database = "iotdb",
    use_pure = True
)

# create a query to insert data into table
uid = 8
name = "csv"
age = 54
address = "chennai"
mobile = "7689054321"

query = f"insert into persons values({uid}, '{name}', {age}, '{address}', '{mobile}');"

# get cursor from connection
cursor = connection.cursor()

# execute query with cursor
cursor.execute(query)

# commit your changes into database server
connection.commit()

# close the cursor
cursor.close()

# close the connection with mysql server
connection.close()