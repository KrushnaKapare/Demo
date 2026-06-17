# import paho mqtt client
import paho.mqtt.client as mqtt

def on_message(client, userdata, message):
    print(f"Received msg : {message.payload}")
    str = (message.payload).decode("utf-8")
    # write code to add reading into database
    print(f"type(str) = {type(str)}, str = {str}")
    if str == "bye":
        client.disconnect()

    
# create a client to subscribe the topic
subscriber = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)

# add on message callback into our client
subscriber.on_message = on_message

# connect with broker 
subscriber.connect(host="127.0.0.1")

# subscribe for topic 
subscriber.subscribe(topic="sensor/ldr")

# use loop forever so that subscriber will wait for messages
subscriber.loop_forever()
