# import Flask
from flask import Flask

# create server
app = Flask(__name__)

@app.get('/')
def homepage():
    return "This is home page"

@app.get('/temperatures')
def get_temperatures():
    temps = [35.5, 23.2, 30.4, 15.0, 20.6]

    return f"temps = {temps}"

@app.post('/temperature/<float:temp>')
def post_temperature(temp):
    print(f"Received Temp : {temp}")

    return f"{temp} is received successfully"


# run server
if __name__ == '__main__':
    app.run(debug=True)