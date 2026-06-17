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
name = "csv"
new_address = "pune"

query = f"update persons SET address = '{new_address}' where name = '{name}';"

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