from flask import Flask, request
import paho.mqtt.client as mqtt

from utils.executeQuery import executeQuery
from utils.executeSelectQuery import executeSelectQuery

app = Flask(__name__)
publisher = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)

@app.post('/add')
def add():
    uid = request.form.get('uid')
    steps = request.form.get('steps')
    pulse = request.form.get('pulse')
    oxygen = request.form.get('oxygen')
    temp = request.form.get('temp')

    query = f"insert into healthParameters values({uid}, {steps}, {pulse}, {oxygen}, {temp});"
    executeQuery(query)

    return "Health Parameters are added successfully"

@app.get('/all')
def all():
    status = "success"
    try:
        query = "select * from healthParameter;"
        data = executeSelectQuery(query=query)
    except:
        status = "failure"

    publisher.connect(host="localhost")
    publisher.publish(topic="health/status", payload=f"GET /all : {status}")
    publisher.disconnect()

    
    return f"adat = {data}"

@app.get('/info')
def info():
    uid = request.form.get('uid')

    person = executeSelectQuery(f"select * from persons where uid = {uid};")
    params = executeSelectQuery(f"select * from healthParameters where uid = {uid};")
    d = {
        "person": person,
        "params": params
    }
    return d

@app.put('/update')
def update():
    uid = request.form.get('uid')
    city = request.form.get('city')

    executeQuery(f"update persons SET address = '{city}' where uid = {uid};")
    return "person's city is updated"

@app.get('/steps')
def steps():
    query = "select uid, step from healthParameters order by step DESC limit 1;"
    data = executeSelectQuery(query)
    print(data)
    uid =  data[0][0]
    steps = data[0][1]
    person =  executeSelectQuery(f"select * from persons where uid = {uid};")
    d = {
        "person":person,
        "steps":steps
    }
    return d


if __name__ == '__main__':
    app.run(debug=True)
