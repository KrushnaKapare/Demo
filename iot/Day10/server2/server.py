from flask import Flask, render_template, request

app = Flask(__name__)

@app.get('/welcome')
def welcome():
    message = "IoT Application"
    return render_template("welcome.html", message = message)

@app.get('/temperatures')
def get_tempeartures():
    list1 = [(13, "Nira"), (14, "Warana"), (12, "Krishna")]
    return render_template("table.html", message=list1)

@app.route('/temperature', methods = ['POST', 'GET'])
def add_temperature():
    temp = request.form.get('temp')
    location = request.form.get('loc')
    print(f"temp = {temp}, location = {location}")

    return render_template("form.html")

app.run(host='0.0.0.0', debug=True)