

  HTTPClient http;


  http.begin(http://jsonplaceholder.typicode.com/users/1);
  http.addHeader("Content-Type", "application/json");

  String putMsg = "{\"mac\":\"";
  putMsg.concat('mac');
  putMsg.concat("\", \"type\":");
  putMsg.concat('type');
  putMsg.concat(",\"metric\":");
  putMsg.concat('metric');
  putMsg.concat(", \"value\":\"");
  putMsg.concat('value');
  putMsg.concat("\"}");
  Serial.println(putMsg);

  int httpResponseCode = http.PUT(putMsg);
  // http.end();

