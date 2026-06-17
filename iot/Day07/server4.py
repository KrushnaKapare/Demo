# import Flask
from flask import Flask, request
import mysql.connector

# create server
app = Flask(__name__)

@app.get('/')
def homepage():
    return "This is home page"

@app.route('/persons', methods=['GET'])
def get_persons():
    conn = mysql.connector.connect(
        host = 'localhost',
        port = 3306,
        user = "root",
        password = "root",
        database = "iotdb",
        use_pure = True        
    )
    query = "select * from persons;"
    cursor = conn.cursor()
    cursor.execute(query)
    data = cursor.fetchall()
    cursor.close()
    conn.close()
    return f"persons = {data}"


@app.route('/person', methods=['POST'])
def post_person():
    uid = request.form.get('uid')
    name = request.form.get('name')
    age = request.form.get('age')
    address = request.form.get('address')
    mobile = request.form.get('mobile')

    conn = mysql.connector.connect(
        host = 'localhost',
        port = 3306,
        user = "root",
        password = "root",
        database = "iotdb",
        use_pure = True        
    )
    query = f"insert into persons values({uid}, '{name}', {age}, '{address}', '{mobile}');"
    print(query)
    cursor = conn.cursor()
    cursor.execute(query)
    conn.commit()
    cursor.close()
    conn.close()
    
    return "Person details are added successfully"

@app.route('/person', methods=['PUT'])
def update_person():
    uid = request.form.get('uid')
    address = request.form.get('address')

    query = f"update persons SET address = '{address}' where uid = {uid};"

    conn = mysql.connector.connect(
        host = 'localhost',
        port = 3306,
        user = "root",
        password = "root",
        database = "iotdb",
        use_pure = True        
    )
    cursor = conn.cursor()
    cursor.execute(query)
    conn.commit()
    cursor.close()
    conn.close()

    return f"address of person with uid = {uid} is updated successfully"

@app.route('/person', methods=['DELETE'])
def delete_person():
    uid = request.form.get('uid')

    query = f"delete from persons where uid = {uid};"

    conn = mysql.connector.connect(
        host = 'localhost',
        port = 3306,
        user = "root",
        password = "root",
        database = "iotdb",
        use_pure = True        
    )
    cursor = conn.cursor()
    cursor.execute(query)
    conn.commit()
    cursor.close()
    conn.close()

    return f"person with uid {uid} is deleted successfully"

# run server
if __name__ == '__main__':
    app.run(debug=True)