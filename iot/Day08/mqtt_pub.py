# import paho mqtt client
import paho.mqtt.client as mqtt

def on_publish(client, userdata, mid, reason_code, properties):
    print("message is published")

# create mqtt client to publish message
publisher = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)

# add our callback into publisher
publisher.on_publish = on_publish

# connect with broker
publisher.connect(host="localhost")

# publish message on topic
publisher.publish(topic="sensor/ldr", payload='bye')

# disconnect from broker
publisher.disconnect()




