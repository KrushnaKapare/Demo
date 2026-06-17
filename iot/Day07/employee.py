
import mysql.connector
from flask import Flask, request

mega = Flask(__name__)

connection = mysql.connector.connect(
    host = "127.0.0.1",
    port = 3306,
    user = "root",
    password = "root",
    database = "employees",
    use_pure = True
)

def retreive():
    query = "select  * from persons;"
    cursor = connection.cursor()
    cursor.execute(query)
    data = cursor.fetchall()

    for employee in data:
        print(employee)

def add_employee():
    query = f"insert into employees values({empid},'{name}','{department}','{email}',{salary},{joiningdate});"
    cursor = connection.cursor()
    cursor.execute(query)
    connection.commit()
    cursor.close()
    connection.close()

    return "employee details added successfully"

def update_employee():
    empid = request.form.get('empid')
    name  = request.form.get('name')
  
    query = f"update employees SET name ='{name}' where empid ={empid};"

    cursor = connection.cursor()
    cursor.execute(query)
    connection.commit()
    cursor.close()
    connection.close()

    return f" name of employee with empid = {empid} is updated succesfully"

def delete_employee():
    empid = request.form.get('empid')

    query = f" delete from employees where empid = {empid};"

    cursor = connection.cursor()
    cursor.execute(query)
    connection.commit()
    cursor.close()
    connection.close()

    return f"employee with empid {empid} is deleted successfully"

if __name__ == '__main__':
    mega.run(debug=True)