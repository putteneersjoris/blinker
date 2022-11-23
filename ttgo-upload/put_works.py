

import requests

data = {"sensorID":00000,"value":"frompy","time":"000"}
headers = {"Content-Type": "application/json"}
r = requests.put('http://hasdata.xyz/', json=data)

print(r)
print(r.status_code)
print(r.text)


